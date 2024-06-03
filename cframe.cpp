#include "cframe.h"
#include "ui_cframe.h"
#include <QtWidgets>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <istream>
#include <string>
#include <sstream>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include <QProcess>
#include <fstream>
#include <iostream>
#include <sstream>
#include <QDateTime>
#include <cstdlib>
#include <ctime>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
using std::ofstream;
using std::ios;
using std::string;
using std::ios;
using std::cout;

cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
{

    ui->setupUi(this);
    QFile file(":/new/prefix1/ma.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::critical(this, tr("Error"), tr("No se pudo abrir el archivo ma.txt"));
            return;
        }

        // Lee la primera línea del archivo
        QTextStream in(&file);
        QString firstLine = in.readLine();

        // Muestra la primera línea en un QMessageBox
        QMessageBox::information(this, tr("Primera línea"), firstLine);

        // Cierra el archivo
        file.close();


}

cframe::~cframe()
{
    delete ui;
}


//    timer =new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
//    timer->start(20000);

void cframe::on_pushButton_clicked()
{
    QImage menu(":/new/prefix/tok.png");
    ui->lbl_tit->setPixmap(QPixmap::fromImage(menu));
    ui->pushButton->setVisible(false);
    ui->lbl_tit_3->setVisible(false);
    timer =new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_pushButton_clicked()));
    timer->start(20000);

    srand(time(NULL));
    Codigo=100000+rand()%(999999+1000000);
    texto= std::to_string(Codigo);
    ui->lbl_tit_2->setText(QString::number(Codigo));
    Resultado="";
    ofstream Archivo(nombre.data(),ios::out);
    for (int i=0;i<texto.size() ;i++ ) {
        Letra=texto[i];
        Numero=Letra;
        Numero=Modular(Numero,11413,3533);

    }


}
vector<long *> cframe::de2bi(long x){

    vector <long*> b;
    long mod=0;
    while(x>0){
        mod= x%2;
        b.push_back(new long(mod));
        x=x/2;

    }
    return b;
}


long cframe::Modular(long b, long N, long n){
    long a=1;
    b=b%N;
    vector<long*>d=de2bi(n);
    for(long j=0;j<d.size();j++){
        if(*d[j]==1){
            a=(a*b)%N;
        }
        b=b*b;
        b=b%N;
    }
    return a%N;

}

vector<long *> cframe::Ordenar(vector<long *> v)
{

}

void cframe::Inicializacion()
{
    Original.push_back(new long(Modular(32,11413,3533)));
    Original.push_back(new long(Modular(44,11413,3533)));
    Original.push_back(new long(Modular(46,11413,3533)));
    for (int i=48;i<=57 ;i++ ) {
        Original.push_back(new long(Modular(i,11413,3533)));
    }
    for (int i=97;i<=122 ;i++ ) {
        Original.push_back(new long(Modular(i,11413,3533)));
    }
    for (int i=0;i<Original.size() ;i++ ) {
        Original.push_back(new long(*Original[i]));
    }
    Ordenado=Ordenar(Ordenado);

}

