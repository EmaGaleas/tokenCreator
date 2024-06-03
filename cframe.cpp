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
    extraerArchivo();
    llenarListaChars();



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
//    Codigo=100000+rand()%(999999+1000000);
//    texto= std::to_string(Codigo);
    ui->lbl_tit_2->setText(QString::fromStdString(cifrar()));
    Resultado="";


}

void cframe::extraerArchivo()
{
    QFile file(":/new/prefix1/ma.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, tr("Error"), tr("No funca archivo ma.txt"));
        return;
    }
    QTextStream in(&file);
    firstLine = in.readLine();
    QMessageBox::information(this, tr(""), firstLine);


    file.close();
}
vector<int *> cframe::de2bi(int x)
{
    vector <int*> b;
    int mod=0;
    while(x>0){
        mod=x%2;
        b.push_back(new int(mod));
        x=x/2;
    }
    return b;
}


int cframe::Modular(int b, int N, int n)
{
    int a = 1;
    b = b % N;
    vector <int *> Villanueva = de2bi(n);

    for(int i=0 ; i < Villanueva.size(); i++){
        if(*Villanueva[i] == 1)
            a = (a*b)%N;
        b = b*b;
        b = b%N;
    }
    return a%N;
}


vector<long *> cframe::Ordenar(vector<long *> v)
{

}

void cframe::Inicializacion()
{
//    Original.push_back(new long(Modular(32,11413,3533)));
//    Original.push_back(new long(Modular(44,11413,3533)));
//    Original.push_back(new long(Modular(46,11413,3533)));
//    for (int i=48;i<=57 ;i++ ) {
//        Original.push_back(new long(Modular(i,11413,3533)));
//    }
//    for (int i=97;i<=122 ;i++ ) {
//        Original.push_back(new long(Modular(i,11413,3533)));
//    }
//    for (int i=0;i<Original.size() ;i++ ) {
//        Original.push_back(new long(*Original[i]));
//    }
//    Ordenado=Ordenar(Ordenado);

}
string cframe::cifrar()
{

    string cadena = firstLine.toStdString();
    string cifrado = "";

    for (int i = 0; i < cadena.size(); i++) {
        int ascii = static_cast<int>(cadena[i]);
        int mod = Modular(ascii, 11413, 3533);


        for (int pos = 0; pos < criptoABC.size(); pos++)
        {
            if (criptoCHAR.at(pos) == mod) {
                cifrado += criptoABC.at(pos);
                break;
            }
        }
    }

    QFile file(":/new/prefix1/ma.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, tr("Error"), tr("No funca archivo ma.txt"));
        return "";
    }
    QTextStream in(&file);
    firstLine = in.readLine();
    QMessageBox::information(this, tr(""), firstLine);

    file.seek(0);

    QTextStream out(&file);
    QString newLine = QString::fromStdString(cifrado);
    out << newLine << endl;
    file.close();


    return cifrado;

}

void cframe::descifrar() {
    //string cifrado = ui->TBx_Frase->text().toStdString();
//    string descifrado = "";

//    for (int i = 0; i < cifrado.size(); i++) {
//        int posC;
//        for (int pos = 0; pos < criptoABC.size(); pos++) {
//            if (criptoABC.at(pos) == cifrado.at(i)) {
//                posC = pos;
//                break;
//            }
//        }

//        int mod = criptoCHAR.at(posC);
//        int inversa = Modular(mod, 11413, 6597);
//        cout << inversa << "\n";
//        cout << (char) mod << "\n";

//        descifrado += (char) inversa;

//    }
   // mostrar(cifrado,  descifrado);

}
void cframe::llenarListaChars() {

    criptoABC.push_back(' ');
    criptoABC.push_back('!');
    criptoABC.push_back('"');
    criptoABC.push_back('#');
    criptoABC.push_back('$');
    criptoABC.push_back('%');
    criptoABC.push_back('&');
    criptoABC.push_back('\'');
    criptoABC.push_back('(');
    criptoABC.push_back(')');
    criptoABC.push_back('*');
    criptoABC.push_back('+');
    criptoABC.push_back(',');
    criptoABC.push_back('-');
    criptoABC.push_back('.');
    criptoABC.push_back('/');


    for (int i = 0; i < 10; i++) {
        criptoABC.push_back('0' + i);
    }

    criptoABC.push_back(';');

    for (int i = 0; i < 26; i++) {
        criptoABC.push_back('A' + i);
    }

    for (int i = 0; i < 26; i++) {
        criptoABC.push_back('a' + i);
    }

    for (int i = 0; i< criptoABC.size(); i++) {
        criptoCHAR.push_back(Modular((int) criptoABC.at(i), 11413, 3533));
    }

    ordenarVector(criptoCHAR);
}
void cframe::ordenarVector(vector<int> &vec) {
    int n = vec.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

//void cframe::script()
//{
//    /*
//    CREATE TABLE SecureData (
//        id INT AUTO_INCREMENT PRIMARY KEY,
//        encrypted_data TEXT NOT NULL,
//        token VARCHAR(255) NOT NULL
//    );

//    INSERT INTO SecureData (encrypted_data, token) VALUES ('encrypted', 'token');

//    SELECT encrypted_data FROM SecureData WHERE token = 'Token123';
//    */
//}

