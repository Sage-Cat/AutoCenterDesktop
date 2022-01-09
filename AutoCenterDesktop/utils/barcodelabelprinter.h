#ifndef BARCODELABELPRINTER_H
#define BARCODELABELPRINTER_H

#include <QVector>

class QPrinter;
class Code128Item;

namespace BarcodeLabelPrinter {
struct Label {
    QString barcodeData {};
    QString labelText {};
    int timesToPrint {};
};

void printLabels(const QVector<Label>& labels);
bool askPrinterSelect(QPrinter &printer);
Code128Item* createCode128Label(const Label &label);
};

#endif // BARCODELABELPRINTER_H
