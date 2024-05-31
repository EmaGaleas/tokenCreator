#ifndef NODO_H
#define NODO_H

template<typename tipo> class lista;
template<typename tipo> //cualquier tipo de dato
class nodo{
    friend class lista<tipo>;//la clase lista podra acceder a la parte privada
    friend class cframe;
private:
    tipo Dato;
    nodo<tipo> *SigPtr;
    //nodo<tipo> *AntPtr;
public:
    nodo(const tipo &);//constructor
    tipo getDato()const;//obtener el valor getter
};

template<typename tipo>
nodo<tipo>::nodo(const tipo &Dato) : Dato(Dato), SigPtr(0)//poner nullptr es lo mismo
{
//    this->Dato=Dato;
//    this->SigPtr=0;
    //poner esto es lo mismo de la linea de arriba
}

template<typename tipo>
tipo nodo<tipo>::getDato() const
{
    return Dato;
}

#endif // NODO_H




