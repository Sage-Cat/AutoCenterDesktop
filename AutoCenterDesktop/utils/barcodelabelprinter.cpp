#include "barcodelabelprinter.h"

#include "utils/code128/code128item.h"

#include <QPainter>
#include <QPrintDialog>
#include <QPrintEngine>
#include <QPrinter>

#include <QFont>

void BarcodeLabelPrinter::printLabels(const QVector<Label>& labels)
{
    QPrinter printer;
    if(!askPrinterSelect(printer))
        return;

    printer.setPaperSize(QSizeF(41, 25), QPrinter::Millimeter);

    QFont font("Helvetica", 8);
    font.setWeight(QFont::Bold);

    double xscale = printer.pageRect().width()/double(200);
    double yscale = printer.pageRect().height()/double(80);
    double scale = qMin(xscale, yscale);

    QPainter painter;
    painter.begin(&printer);
    painter.setFont(font);

    painter.translate(printer.paperRect().x() + printer.pageRect().width()/2,
                                printer.paperRect().y() + printer.pageRect().height()/2);
    painter.scale(scale, scale);
    painter.translate(-200/2, -80/2);

    printer.setPageMargins(5, 2, 0, 0, QPrinter::Millimeter);

    for (const Label& label : labels) {
        Code128Item* m_Barcode = createCode128Label(label);

        for (int i = 0; i < label.timesToPrint; ++i)
            m_Barcode->paint(&painter, nullptr, nullptr);

//        QPixmap pix(200, 80); // MUST match the setWidth, setHeight
//        QPainter painter(&printer);
//        pix.fill(Qt::white);
//        m_Barcode->paint(&painter, nullptr, nullptr);

//        for (int i = 0; i < label.timesToPrint; ++i)
//            painter.drawPixmap(0, 0, pix);

        painter.end();
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
