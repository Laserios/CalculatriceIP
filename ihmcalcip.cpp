#include "ihmcalcip.h"
#include "ui_ihmcalcip.h"
#include <QDebug>
#include <QtMath>

IHMCalcIP::IHMCalcIP(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IHMCalcIP)
{
    ui->setupUi(this);

    connect(ui->BtnValider, SIGNAL(clicked()), this,SLOT(test()));


    //On crée le CIDR et le masque
    quint32 leMasque,fenetre;
    quint8 octet=0;
    int i;
    leMasque =0xFF000000;
    // pour toutes les valeurs de suffixes comprises entre 8 et 30 : suffixe CIDR /8 jusqu'a suffixe CIDR /30

    for(int valeur=8; valeur<=30; valeur++)
    {
        QString masque="";
        fenetre = 0xFF000000 ;

        for(i =0; i<=3; i++)
        {
            octet = (leMasque & fenetre) >> (8 * (3-i));
            qDebug()<<"octet" << octet ;
            masque = masque + QString::number(octet);

            if(i<3)
            {
                masque = masque + "." ;
                fenetre = fenetre >> 8;
            }
        }
        leMasque =leMasque >> 1;
        leMasque = leMasque | 0x80000000;
        ui->combSuf->addItem(QString::number(valeur));
        ui->combMask->addItem(masque);

        // Attention !!!: Mise à jour du tableau mask a déclarer comme attribut dans le fichier d'entête de la classe;
        // quint8 mask[4] contiendra les 4 parties du masque de sous-réseau

        QRegExp rx("[. ]");// match a comma or a space
        QStringList list = ui->combMask->currentText ().split(rx, QString::SkipEmptyParts);
        qDebug() << list;

        for(int i=0; i< list.size(); i++)
        {
            mask[i] = list[i].toInt(); // quint8 mask[4] }
        }

        // calcul du nombre max de sous-réseaux a compléter
        qint32 nbreMaxSousReseaux = qPow(2,32-valeur);
        ui->combSRmax->addItem(QString::number(nbreMaxSousReseaux));

        //calcul du nombre max d'hôtes à compléter;
        qint32 nbreMaxHote = qPow(2,32-valeur)-2;
        ui->combHotesmax->addItem(QString::number(nbreMaxHote));
    }
}


IHMCalcIP::~IHMCalcIP()
{
    delete ui;
}


void IHMCalcIP :: recupIP()
{
    IP1 = ui->IPEdit1->text().toInt(); // recuperer l'adresse IP
    IP2 = ui->IPEdit2->text().toInt();
    IP3 = ui->IPEdit3->text().toInt();
    IP4 = ui->IPEdit4->text().toInt();

    qDebug() <<  IP1 << "." << IP2 << "." << IP3 << "." << IP4;
}

void IHMCalcIP :: adresseRes(){

}

void IHMCalcIP :: adresseUtil(){

}

void IHMCalcIP :: adresseDiff(){

}
