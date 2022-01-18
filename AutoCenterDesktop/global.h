#ifndef GLOBAL_H
#define GLOBAL_H

#include <QStringList>
#include <QMap>


struct Person {
    QString
        name {},
        iban {},
        bank {},
        number {},
        edrpoy {},
        ipn {},
        address {};
};

struct Record {
    QString
        code {},
        tnved{},
        catalog{},
        name{},
        count{},
        unit{},
        purchase_price{};
};


const QStringList DOC_TYPES_NAMES {
    "Рахунок",
    "Видаткова накладна",
    "Товарний чек",
    "Податкова накладна",
    "Накладна на повернення",
    "Накладна на надходження"
};

enum DOC_TYPES {
    Rahunok,
    Vydatkova_nakladna,
    Tovarniy_chek,
    Podatkova_nakladna,
    Nakladna_na_povernennya,
    Nakladna_na_nadhodjennya
};

const QStringList Suppliers {
    "Омега"
};

const QMap<QString, QString> UNIT_CODE {
    { "шт", "2009" },
    { "компл", "2938" },
    { "м", "0101" },
    { "л", "0138" }
};


#endif // GLOBAL_H
