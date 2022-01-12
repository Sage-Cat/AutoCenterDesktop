#ifndef DOCUMENTPRINTER_H
#define DOCUMENTPRINTER_H

#include <QSqlTableModel>

struct Seller {
    QString
        name {},
        iban {},
        bank {},
        number {},
        edrpoy {},
        ipn {};
};

class DocumentPrinter {

    const int ID_COLUMN_INDEX { 0 };
    const int LIST_ID_COLUMN_INDEX { 1 };
    const int CODE_COLUMN_INDEX { 2 };
    const int NAME_COLUMN_INDEX { 5 };
    const int COUNT_COLUMN_INDEX { 6 };
    const int UNIT_COLUMN_INDEX { 7 };
    const int PRICE_COLUMN_INDEX { 8 };
    const int SUM_COLUMN_INDEX { 9 };

public:
    DocumentPrinter();
    void printPdvRahunok(const Seller& seller, const QString& customerName, const QSqlTableModel* model,
                         const QString &datetime, const QString &listnumber);

private:
    void printHtmlForm(const QString& html);
    QString convertPriceInWords(float sum);

    const QString TABLE_ROW = "<TR CLASS=R0>"
                              "<TD><SPAN></SPAN></TD>"
                              "<TD CLASS=\"R25C1\" COLSPAN=2><SPAN STYLE=\"white-space:nowrap;max-width:0px;\">:Number</SPAN></TD>"
                              "<TD CLASS=\"R25C3\" COLSPAN=3>:Code</TD>"
                              "<TD CLASS=\"R25C3\" COLSPAN=20>:Name</TD>"
                              "<TD CLASS=\"R25C26\" COLSPAN=3><SPAN STYLE=\"white-space:nowrap;max-width:0px;\">:Count</SPAN></TD>"
                              "<TD CLASS=\"R25C29\" COLSPAN=2><SPAN STYLE=\"white-space:nowrap;max-width:0px;\">:Unit</SPAN></TD>"
                              "<TD CLASS=\"R25C26\" COLSPAN=3><SPAN STYLE=\"white-space:nowrap;max-width:0px;\">:Price</SPAN></TD>"
                              "<TD CLASS=\"R25C34\" COLSPAN=4><SPAN STYLE=\"white-space:nowrap;max-width:0px;\">:Sum</SPAN></TD>"
                              "<TD><SPAN></SPAN></TD>"
                              "<TD></TD>"
                              "</TR>";
};

#endif // DOCUMENTPRINTER_H
