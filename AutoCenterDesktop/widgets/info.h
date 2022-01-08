#ifndef INFO_H
#define INFO_H

#include <QWidget>

class QSqlTableModel;

namespace Ui {
class Info;
}

class Info : public QWidget {
    Q_OBJECT

    const int ID_COLUMN_INDEX{ 0 };

public:
    explicit Info(QWidget* parent = nullptr, int id = 0);
    ~Info();

private:
    Ui::Info* ui;
    int id {};
    QSqlTableModel *model;
};

#endif // INFO_H
