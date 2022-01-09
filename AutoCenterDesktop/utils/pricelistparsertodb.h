#ifndef PRICELISTPARSERTODB_H
#define PRICELISTPARSERTODB_H

#include <QObject>
#include <QSqlQuery>

class PricelistParserToDB : public QObject
{
    Q_OBJECT

    const int MAX_NUMBER_OF_MISSES = 10;
    const int RECORDS_COUNT_TO_CHECK = 50;

public:
    explicit PricelistParserToDB(QObject *parent = nullptr, const QString &fileName = {});

    /*!
     * \brief countRecordEntropy counts number of records that file should have
     * \abstract It calculates average number of symbols per xml-record for the first 1000 records
     * and then divides FILE_SIZE / AVARAGE_COUNT_OF_SYMBOLS_IN_RECORD
     */
    void countApproximateNumberOfRecordsInFile();

public slots:
    void parseAsOmegaPriceList();

signals:
    void progressChanged(int newValue);
    void workFinished();

private:
    QString fileName {};
    QSqlQuery qry;
    int approximateCountOfRecordsInFile {};
};

#endif // PRICELISTPARSERTODB_H
