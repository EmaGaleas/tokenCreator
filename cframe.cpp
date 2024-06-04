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
    , contador(0)  // Inicializamos el contador a 0
{
    ui->setupUi(this);
    llenarListaChars();
    ui->lbl_contador->setVisible(false);
    // Configurar el QTimer
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &cframe::actualizarcontador);
    timer->start(1000);  // Actualiza cada segundo
}

cframe::~cframe()
{
    delete ui;
}


//    timer =new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
//    timer->start(20000);
void cframe::actualizarcontador(){
    contador = (contador + 1) % 61;
    int mostrar_segundos = contador % 60;
    QString timeText = QString("00:%1").arg(mostrar_segundos, 2, 10, QChar('0'));
    ui->lbl_contador->setText(timeText);
}

void cframe::on_pushButton_clicked()
{
    QImage menu(":/new/prefix/tok.png");
    ui->lbl_tit->setPixmap(QPixmap::fromImage(menu));
    ui->pushButton->setVisible(false);
    ui->lbl_tit_3->setVisible(false);
    ui->lbl_contador->setVisible(true);

    timer2 =new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(on_pushButton_clicked()));
    timer2->start(60000);

    srand(time(NULL));
    Codigo=100000+rand()%(999999+1000000);
    //texto es el que se muestra al correr el programa
    texto= std::to_string(Codigo);
    ui->lbl_tit_2->setText(QString::fromStdString(texto));

    resultado="";
    //este es el cifrado de ese token y que procede a guardarse en el archivo
    resultado=cifrar(texto);
    insertarArchivo(resultado);
    contador = 0;
    timer->start(1000);

   // QMessageBox::information(this,"lalala",""+QString::fromStdString(texto)+"\n"+QString::fromStdString(resultado));

}

void cframe::insertarArchivo(string tok)
{
    std::ofstream ar(Ruta);
    if (ar.is_open()) {
        ar << tok;
        ar.close();
        std::cout << "Archivo sobrescrito exitosamente.\n";
    } else {
        std::cerr << "No se pudo abrir el archivo.\n";
    }

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

string cframe::cifrar(string cadena)
{

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

    return cifrado;

}


void cframe::llenarListaChars() {

    criptoABC.push_back(' ');
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

