#ifndef XMLDOCUMENTLOADER_H
#define XMLDOCUMENTLOADER_H

#include <QDate>
#include <QMap>
#include <QString>
#include <QObject>

struct Person;
struct Record;

class QSqlTableModel;
class QXmlStreamReader;
class QXmlStreamAttribute;

class XmlDocumentLoader : public QObject
{
    Q_OBJECT

    const int ID_COLUMN_INDEX { 0 };
    const int LIST_ID_COLUMN_INDEX { 1 };
    const int CODE_COLUMN_INDEX { 2 };
    const int TNVED_COLUMN_INDEX { 4 };
    const int NAME_COLUMN_INDEX { 5 };
    const int COUNT_COLUMN_INDEX { 6 };
    const int UNIT_COLUMN_INDEX { 7 };
    const int PRICE_COLUMN_INDEX { 8 };
    const int SUM_COLUMN_INDEX { 9 };

public:
    XmlDocumentLoader();

    void generatePodatkovaNakladna(const Person& seller, const Person& customer, const QSqlTableModel* model,
        const QDate& date, const QString& listnumber);
    void loadOmegaNakladnaToDB(const QString& fileName);

signals:
    void tabRecordsRequested(int list_id);

private:
    int insertNewProduct(const Record &newProduct);
    void insertNewRecordToList(const int& list_id, const int& product_id, const QString& count, const QString& price);
    int insertNewNakladnaWithSellerEDRPOY(const QString& EDRPOY);
    bool parseOmegaNakladnaRowByAttributeName(QXmlStreamReader &reader, const QString &attribute, Record &product);

    // https://medoc.ua/files/others/032021/ef1b8b2801ec55f56033674c7c4aae16.pdf
    const QString PODATKOVA_NAKLADNA_ROW {
        "<RXXXXG3S ROWNUM=\":i\">:Name</RXXXXG3S>\n"
        "<RXXXXG4 ROWNUM=\":i\">:TNVED</RXXXXG4>\n"
        ":isImport"
        "<RXXXXG4S ROWNUM=\":i\">:Unit</RXXXXG4S>\n"
        "<RXXXXG105_2S ROWNUM=\":i\">:UnitCode</RXXXXG105_2S>\n"
        "<RXXXXG5 ROWNUM=\":i\">:Count</RXXXXG5>\n"
        "<RXXXXG6 ROWNUM=\":i\">:Price</RXXXXG6>\n"
        "<RXXXXG008 ROWNUM=\":i\">20</RXXXXG008>\n"
        "<RXXXXG010 ROWNUM=\":i\">:Sum</RXXXXG010>\n"
    };
};

#endif // XMLDOCUMENTLOADER_H
