#include "pricelistparsertodb.h"

#include <QXmlStreamReader>
#include <QFile>

#include "widgets/products.h"

PricelistParserToDB::PricelistParserToDB(QObject *parent, const QString &fileName) :
    QObject(parent),
    fileName(fileName)
{
    countApproximateNumberOfRecordsInFile();
}

void PricelistParserToDB::countApproximateNumberOfRecordsInFile()
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        return;

    const qint64 fileSize = file.size();
    qint64 keyWordCount {}, symbols_count {};
    while (keyWordCount < RECORDS_COUNT_TO_CHECK)
    {
        QByteArray line = file.readLine();
        symbols_count += line.size();
        if (line.contains(QByteArray("</Прайс>"))) // means that one more record is checked
            keyWordCount++;
    }
    const qint64 averageCountOfSymbolsPerRecord = symbols_count / RECORDS_COUNT_TO_CHECK;

    approximateCountOfRecordsInFile = averageCountOfSymbolsPerRecord / fileSize;
}

void PricelistParserToDB::parseAsOmegaPriceList()
{
    QString Code = "-",
            Catalog = "-",
            TNVED = "-",
            Name = "-",
            Unit = "шт",
            Price = "0.0";

    // START PARSING
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        return;

    QXmlStreamReader reader(&file);
    int counter {}; // counter for records
    int progressBarValue {};
    const int recordsForOnePercent = approximateCountOfRecordsInFile / 100;

    int miss_count {}; // counter for errors
    while(reader.readNextStartElement() && miss_count < MAX_NUMBER_OF_MISSES)
    {
        if(reader.name().toString() == "Прайс")
        {
            miss_count = 0;

            while(reader.readNextStartElement())
            {
                if(reader.name().toString() == "KART")        Code            = reader.readElementText(); else
                if(reader.name().toString() == "KODKAT")      Catalog         = reader.readElementText(); else
                if(reader.name().toString() == "KODTNVED")    TNVED           = reader.readElementText(); else
                if(reader.name().toString() == "NAIM")        Name            = reader.readElementText(); else
                if(reader.name().toString() == "NAIMUKR")     Name            = reader.readElementText(); else
                if(reader.name().toString() == "BAZED")       Unit            = reader.readElementText(); else
                if(reader.name().toString() == "MINCENA")     Price           = reader.readElementText(); else reader.skipCurrentElement();
            }

            // INSERT NEW RECORD
            if(Code != "-")
                Products::insertProductToDb(Code, Catalog, TNVED, Name, Unit, Price);

            // SET DEFAULT TO CHECK FOR A FOOL
            // ex: user wants to load the pricelist with a similar start "Прайс", but with different keys
            // => here we get a bunch of default-records relentlessly flooding the database
            Code = "-";

            // ProgressBar logic
            counter++;
            if (counter == recordsForOnePercent)
            {
                counter = 0;
                progressBarValue++;
                emit progressChanged(progressBarValue);
            }
        }
        else
            miss_count++;
    }
    emit workFinished();
}
