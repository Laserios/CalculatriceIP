#ifndef IHMCALCIP_H
#define IHMCALCIP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class IHMCalcIP; }
QT_END_NAMESPACE

class IHMCalcIP : public QMainWindow
{
    Q_OBJECT

public:
    IHMCalcIP(QWidget *parent = nullptr);
    ~IHMCalcIP();

private:
    Ui::IHMCalcIP *ui;

    int IP1;
    int IP2;
    int IP3;
    int IP4;
    int hotemax;
    quint8 mask[4];


private slots:
    void recupIP();
    void adresseRes();
    void adresseUtil();
    void adresseDiff();

};
#endif // IHMCALCIP_H
