#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>
#include <lista.h>
#include <QMessageBox>
#include <nodoD.h>
#include <vector>
#include <QTimer>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
using std::vector;

QT_BEGIN_NAMESPACE
namespace Ui { class cframe; }
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    cframe(QWidget *parent = nullptr);
    ~cframe();
    vector<long *> de2bi(long x);
    long Modular(long x, long N, long n);
    vector<long *> Ordenar(vector<long *>v);
    void EstablecerConexion();
    void Inicializacion();
     void actualizarcontador();


private slots:
    void on_pushButton_clicked();

private:
    Ui::cframe *ui;


    QTimer *timer,*timer2;
    int contador;
    long Codigo;
    vector<long*>Binario,Original,Ordenado;
    QString Resultado, ConsultaSql, Nombre;
    std::string texto, nombre;
    char Letra;
    int Numero;
    QString firstLine;
    std::string Ruta ="C:\\Users\\pcast\\OneDrive - Universidad Tecnologica Centroamericana\\q\\Q2 2024\\CRIPTOVERSIDAD\\criptoversidad\\ma.txt";

    void insertarArchivo(string);


    int Modular(int N, int a, int b);
    vector<int *> de2bi(int x);

    string cifrar(string);
    void descifrar();

    vector<char> criptoABC;
    vector<int> criptoCHAR;

    void llenarListaChars();

    void ordenarVector(vector<int>& vec);

    lista<char> ListaABC;
    lista<int> ListaNormal,ListaOrdenada;
    nodo<char> *ActPtr;
    nodo<int> *PtrAct;
    int h,f,Pos;

    string token,encrypted,resultado;
  //  void script();
};
#endif // CFRAME_H
