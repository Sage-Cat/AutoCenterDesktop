#include "mainwindow.h"

#include <QApplication>

#include <QSqlDatabase>
#include <QMessageBox>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>

bool initDB(QMainWindow *parent, QSqlDatabase *db);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    /* Connect to DB */
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
    if (!(db.open() && initDB(&w, &db)))
        QMessageBox::critical(&w, "Помилка", "Не вийшло відкрити базу даних", QMessageBox::Ok);

    w.show();
    return a.exec();
}

bool initDB(QMainWindow *parent, QSqlDatabase *db)
{
    bool success{ true };

    QFile file(":/db_init.sql");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(parent, "Помилка", "Не вийшло ініціалізувати базу даних", QMessageBox::Ok);
        success = false;
    }

    // Parsing the db_init.sql file and executing queries
    QSqlQuery qry(*db);
    auto list = QString(file.readAll()).split('|');
    while(list.size() != 0)
    {
        // 0 - Information
        // 1 - Query
        QString qryName = list.at(0);
        bool result = qry.exec(list.at(1));
//        if(result)
//            qDebug() << "Processing:" << qryName << "... " << result;
//        else
//            qDebug() << "Processing:" << qryName << "... " << qry.lastError().text();

        list.pop_front();
        list.pop_front();
    }

    return success;
}
