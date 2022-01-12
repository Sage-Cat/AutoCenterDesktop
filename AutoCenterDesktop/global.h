#ifndef GLOBAL_H
#define GLOBAL_H

#include <QStringList>

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


#endif // GLOBAL_H
