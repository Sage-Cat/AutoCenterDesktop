#include "barcodelabelprinter.h"

#include "utils/code128/code128item.h"

#include <QPainter>
#include <QPrintDialog>
#include <QPrinter>

void BarcodeLabelPrinter::printLabels(const QVector<Label>& labels)
{
    QPrinter printer;
    if(!askPrinterSelect(printer))
        return;

    for (const Label& label : labels) {
        Code128Item* m_Barcode = createCode128Label(label);

        QPainter painter(&printer);
        painter.setFont(QFont("Helvetica", 8));

        for (int i = 0; i < label.timesToPrint; ++i)
            m_Barcode->paint(&painter, nullptr, nullptr);

//        QPixmap pix(200, 80); // MUST match the setWidth, setHeight
//        QPainter painter(&printer);
//        pix.fill(Qt::white);
//        m_Barcode->paint(&painter, nullptr, nullptr);

//        for (int i = 0; i < label.timesToPrint; ++i)
//            painter.drawPixmap(0, 0, pix);

        delete m_Barcode;
    }
}

bool BarcodeLabelPrinter::askPrinterSelect(QPrinter& printer)
{
    QPrintDialog dialog(&printer);
    dialog.setWindowTitle("Вибір принтера");

    if(dialog.exec() == QDialog::Accepted)
        return true;

    return false;
}

Code128Item* BarcodeLabelPrinter::createCode128Label(const Label& label)
{
    Code128Item* m_Barcode = new Code128Item();
    m_Barcode->setWidth(200);
    m_Barcode->setHeight(80);
    m_Barcode->setPos(0, 0);
    m_Barcode->setHighDPI(true);
    m_Barcode->setText(label.barcodeData, label.labelText);

    return m_Barcode;
}
