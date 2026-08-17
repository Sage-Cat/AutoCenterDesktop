#include "mainwindow.h"

#include <QApplication>

#include <QSqlDatabase>
#include <QMessageBox>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>
#include <QDir>
#include <QStandardPaths>

bool initDB(QMainWindow *parent, QSqlDatabase *db);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /* Connect to DB */
    const QString dataDirectory = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (dataDirectory.isEmpty() || !QDir().mkpath(dataDirectory)) {
        QMessageBox::critical(nullptr, "Помилка", "Не вийшло створити каталог для даних", QMessageBox::Ok);
        return EXIT_FAILURE;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dataDirectory + "/database.db");
    if (!db.open()) {
        QMessageBox::critical(nullptr, "Помилка", "Не вийшло відкрити базу даних\n" + db.lastError().text(), QMessageBox::Ok);
        return EXIT_FAILURE;
    }

    MainWindow w;
    if (!initDB(&w, &db))
        return EXIT_FAILURE;

    w.show();
    return a.exec();
}

bool initDB(QMainWindow *parent, QSqlDatabase *db)
{
    QFile file(":/db_init.sql");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(parent, "Помилка", "Не вийшло ініціалізувати базу даних", QMessageBox::Ok);
        return false;
    }

    // Parsing the db_init.sql file and executing queries
    QSqlQuery qry(*db);
    if (!qry.exec("PRAGMA foreign_keys=ON"))
        return false;

    const auto list = QString::fromUtf8(file.readAll()).split('|');
    if (list.size() % 2 != 0) {
        QMessageBox::critical(parent, "Помилка", "Невірний формат db_init.sql", QMessageBox::Ok);
        return false;
    }

    if (!db->transaction())
        return false;

    for (int i = 0; i < list.size(); i += 2) {
        if (!qry.exec(list.at(i + 1))) {
            db->rollback();
            QMessageBox::critical(parent, "Помилка",
                "Не вийшло ініціалізувати базу даних\n" + qry.lastError().text(),
                QMessageBox::Ok);
            return false;
        }
    }

    return db->commit();
}
