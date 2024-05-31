#ifndef LISTA_H
#define LISTA_H

#include <nodo.h>
#include <iostream>
using std::cout;
using std::string;

template<typename tipo>
class lista{
    friend class cframe;
private:
    nodo<tipo> *PrimPtr;
    nodo<tipo> *UltPtr;
    int Cant;

public:
    lista();
    ~lista();
    void actualizarUltimo();
    void InsertarInicio(const tipo &);
    void Insertar2daPos(const tipo &);
    void Insertar3raPos(const tipo &);
    void Insertar4taPos(const tipo &);
    void InsertarAntePneultima(const tipo &);
    void InsertarPenultima(const tipo &);
    void InsertarFin(const tipo &);
    void InsertarCreciente(const tipo &);
    void InsertarDecreciente(const tipo &);
    bool InsertarPosicion(const tipo &,int);

    bool EliminarInicio(tipo &);
    bool Eliminar2daPos(tipo &);
    bool Eliminar3raPos(tipo &);
    bool EliminarAntePneultima(tipo &);
    bool EliminarPenultima(tipo &);
    bool EliminarFin(tipo &);
    bool EliminarCreciente(tipo &);
    bool EliminarDecreciente(tipo &);
    bool EliminarPosicion(tipo &,int);

    bool Vacia()const;
//    bool Guardar(string Nombre)const;
//    bool Importar(string Nombre);
    void Limpiar();


};

template<typename tipo>
lista<tipo>::lista() :PrimPtr(0),UltPtr(0), Cant(0)//en cero pq guarda direccion hexadecimal y 0 es que no tiene direccion aun
{}

template<typename tipo>
lista<tipo>::~lista()
{
    if(!Vacia()){
        cout<<"limpiando\n"<<std::endl;
        nodo<tipo> *ptrAct=PrimPtr;
        nodo<tipo> *ptrTemp;
        while(ptrAct!=0){
            ptrTemp=ptrAct;
            cout<<ptrTemp->Dato<<"\n";
            ptrAct=ptrAct->SigPtr;
            Cant--;
            delete ptrTemp;
        }
        cout<<"Vacio\n";
    }
}

template<typename tipo>
void lista<tipo>::actualizarUltimo()
{
        nodo<tipo> *temp = PrimPtr;
        while(temp->SigPtr!=0){
            temp=temp->SigPtr;
        }
        UltPtr=temp;
}


template<typename tipo>
void lista<tipo>::InsertarInicio(const tipo &Dato)
{
    nodo<tipo> *Nuevo = new nodo<tipo> (Dato);
    if(Vacia()){
        PrimPtr=UltPtr=Nuevo;
    }else{
        Nuevo->SigPtr=PrimPtr;//que guarde de la direccion del primero
        PrimPtr=Nuevo;//que ahora el primero sea el nuevo
        actualizarUltimo();
    }
    Cant++;
}

template<typename tipo>
void lista<tipo>::Insertar2daPos(const tipo &Dato)
{
    nodo<tipo> *nuevo = new nodo<tipo>(Dato);
    if(Vacia()){
        PrimPtr =UltPtr=nuevo;
    }else{
        nuevo->SigPtr = PrimPtr->SigPtr;
        PrimPtr->SigPtr = nuevo;
    }
    actualizarUltimo();
    Cant++;

}

template<typename tipo>
void lista<tipo>::Insertar3raPos(const tipo &Dato)
{
    nodo<tipo> *nuevo= new nodo<tipo>(Dato);
    if(Vacia() || Cant==1){
        Insertar2daPos(Dato);
    }else{
        nuevo->SigPtr=PrimPtr->SigPtr->SigPtr;
        PrimPtr->SigPtr->SigPtr=nuevo;
        Cant++;
        actualizarUltimo();
    }
}

template<typename tipo>
void lista<tipo>::Insertar4taPos(const tipo &Dato)
{
    if(Vacia() || Cant<3){
        Insertar3raPos(Dato);
    }else{
        nodo<tipo> *nuevo= new nodo<tipo>(Dato);
        nuevo->SigPtr=PrimPtr->SigPtr->SigPtr->SigPtr;
        PrimPtr->SigPtr->SigPtr->SigPtr=nuevo;
        Cant++;
        actualizarUltimo();
    }
}

template<typename tipo>
void lista<tipo>::InsertarAntePneultima(const tipo &Dato)
{
    if(Vacia() || Cant==1 || Cant==2){
        InsertarInicio(Dato);
    }else{

        nodo<tipo> *nuevo= new nodo<tipo> (Dato);
        nodo<tipo> *antePtr=PrimPtr;
        while (antePtr->SigPtr->SigPtr->SigPtr != nullptr) {
           antePtr = antePtr->SigPtr;
        }
        nuevo->SigPtr = antePtr->SigPtr;
        antePtr->SigPtr = nuevo;
        actualizarUltimo();
        Cant++;
    }

}

template<typename tipo>
void lista<tipo>::InsertarPenultima(const tipo &Dato)
{
    if(Vacia() || Cant==1){
        InsertarFin(Dato);
    }else{
        nodo<tipo> *temp=PrimPtr;
        nodo<tipo> *nuevo=new nodo<tipo>(Dato);
        while(temp->SigPtr->SigPtr!=nullptr){
            temp=temp->SigPtr;
        }
        nuevo->SigPtr=UltPtr;
        temp->SigPtr=nuevo;
        Cant++;
        actualizarUltimo();
    }
}

template<typename tipo>
void lista<tipo>::InsertarFin(const tipo &Dato)
{
    nodo<tipo> *nuevo = new nodo<tipo>(Dato);
    if(Vacia()){
        PrimPtr =UltPtr=nuevo;
    }else{
        UltPtr->SigPtr=nuevo;
        UltPtr=nuevo;
    }
    Cant++;
}

template<typename tipo>
void lista<tipo>::InsertarCreciente(const tipo &Dato)
{
    nodo<tipo> *nuevo=new nodo<tipo>(Dato);
    if(Vacia()){
        PrimPtr=UltPtr=nuevo;
    }else{
        nodo<tipo> *ant=nullptr;
        nodo<tipo> *act=PrimPtr;

        while(act !=nullptr && act->Dato<Dato){
            ant=act;
            act=act->SigPtr;
        }
        if(ant==nullptr){
            nuevo->SigPtr=PrimPtr;
            PrimPtr=nuevo;
        }else{
            ant->SigPtr=nuevo;
            nuevo->SigPtr=act;
            if(act==nullptr){
                UltPtr=nuevo;
            }
        }
    }
    Cant++;
    actualizarUltimo();
}

template<typename tipo>
bool lista<tipo>::InsertarPosicion(const tipo &Dato, int indice)
{
   nodo<tipo> *nuevo= new nodo<tipo>(Dato);
   if(Vacia() || Cant+1<indice){
       return false;
   }else{
       if(indice==1){
           InsertarInicio(Dato);
       }else if(indice==Cant+1){
           InsertarFin(Dato);
       }else{
           nodo<tipo> *temp=PrimPtr;
           for(int i=1;i<indice-1;i++){
               temp=temp->SigPtr;
           }
           nuevo->SigPtr=temp->SigPtr;
           temp->SigPtr=nuevo;
           UltPtr=(Cant==indice)? nuevo:UltPtr;
           Cant++;
           actualizarUltimo();
       }

       return true;
   }

}

template<typename tipo>
bool lista<tipo>::EliminarInicio(tipo &Dato)
{
    if(Vacia()){
        return false;
    }else{
        if (Cant == 1) {
            if (UltPtr->Dato == Dato) {
                Dato=PrimPtr->Dato;
                delete PrimPtr;
                PrimPtr=nullptr;
                UltPtr=nullptr;
                Cant = 0;
                return true;
            }
        }else if(PrimPtr->Dato==Dato){
            nodo<tipo> *eliminar=PrimPtr;
            PrimPtr = PrimPtr->SigPtr;
            Dato=eliminar->Dato;
            delete eliminar;
            Cant--;
            actualizarUltimo();
            return true;
        }

    }
    return false;
}

template<typename tipo>
bool lista<tipo>::Eliminar2daPos(tipo &Dato)
{
    if(Vacia() || Cant==1){
        return false;
    }else{

        nodo<tipo> *del=PrimPtr;
        del=PrimPtr->SigPtr;
        if(del->Dato==Dato){
            PrimPtr->SigPtr=PrimPtr->SigPtr->SigPtr;
            delete del;
            Cant--;
            actualizarUltimo();
            return true;
        }
    }
    return false;
}

template<typename tipo>
bool lista<tipo>::Eliminar3raPos(tipo &Dato)
{
    if(Vacia() || Cant<=2){
        return false;
    }else{
        nodo<tipo> *elim=PrimPtr->SigPtr->SigPtr;
        if(elim->Dato==Dato){
            PrimPtr->SigPtr->SigPtr=elim->SigPtr;
            delete elim;
            Cant--;
            actualizarUltimo();
            return true;
        }
        return false;
    }
    return false;
}

template<typename tipo>
bool lista<tipo>::EliminarAntePneultima(tipo &Dato)
{
    if (Vacia() || Cant <= 2) {
        return false;
    } else {
        if (PrimPtr->Dato == Dato && Cant==3) {
            nodo<tipo> *eliminar = PrimPtr;
            PrimPtr = PrimPtr->SigPtr;
            delete eliminar;
            Cant--;
            actualizarUltimo();
            return true;

        } else if(!Vacia() && Cant>3){
            nodo<tipo> *del=PrimPtr;
            while(del->SigPtr->SigPtr->SigPtr->SigPtr!=nullptr){
                del=del->SigPtr;
            }
            if(del->SigPtr->Dato==Dato){
                nodo<tipo> *temp=del;
                temp->SigPtr=del->SigPtr->SigPtr;
                del=del->SigPtr;
                delete del;
                Cant--;
                actualizarUltimo();
                return true;
            }
        }
    }
    return false;
}

template<typename tipo>
bool lista<tipo>::EliminarPenultima(tipo &Dato)
{
    if (Vacia() || Cant <= 1) {
        return false;
    } else if (Cant == 2) {
        if(EliminarInicio(Dato))
            return true;
    } else if(!Vacia() && Cant>2) {
        nodo<tipo> *tenp = PrimPtr;
        while (tenp->SigPtr->SigPtr->SigPtr != nullptr) {
            tenp = tenp->SigPtr;
        }
        if(tenp->SigPtr->Dato==Dato){
            nodo<tipo> *del = tenp->SigPtr;
           tenp->SigPtr = tenp->SigPtr->SigPtr;
           delete del;
            Cant--;
            actualizarUltimo();
            return true;

        }
    }

    return false;
}





template<typename tipo>
bool lista<tipo>::EliminarFin(tipo &Dato)
{
    if (!Vacia()) {
        if (Cant == 1) {
            if (PrimPtr->Dato == Dato) {
                delete PrimPtr;
                PrimPtr=nullptr;
                UltPtr=nullptr;
                Cant = 0;
                return true;
            }
        } else {
            if (UltPtr->Dato == Dato) {
                nodo<tipo> *ptrMantener=PrimPtr;
                while (ptrMantener->SigPtr->SigPtr != nullptr) {
                    ptrMantener = ptrMantener->SigPtr;
                }
                delete UltPtr;
               UltPtr = ptrMantener;
               UltPtr->SigPtr = nullptr;
               Cant--;

                return true;
            }
        }
    }
    return false;
}

template<typename tipo>
bool lista<tipo>::EliminarCreciente(tipo &Dato)
{

        if (Vacia()) {
            return false;
        }

        nodo<tipo> *Actual = PrimPtr;
        nodo<tipo> *Anterior = nullptr;
        nodo<tipo> *Minimo = Actual;
        nodo<tipo> *AnteriorMinimo = nullptr;

        while (Actual != nullptr) {
            if (Actual->Dato < Minimo->Dato) {
                Minimo = Actual;
                AnteriorMinimo = Anterior;
            }
            Anterior = Actual;
            Actual = Actual->SigPtr;
        }

        if (AnteriorMinimo != nullptr) {
            AnteriorMinimo->SigPtr = Minimo->SigPtr;
        } else {
            PrimPtr = Minimo->SigPtr;
        }

        if (Minimo == UltPtr) {
            UltPtr = AnteriorMinimo;
        }

        Dato = Minimo->Dato;
        delete Minimo;
        Cant--;

        return true;

}

 template<typename tipo>
bool lista<tipo>::EliminarDecreciente(tipo &Dato)
{
        nodo<tipo> *actual = PrimPtr;
        nodo<tipo> *anterior = nullptr;

        nodo<tipo> *anteriorMayor = nullptr;
        nodo<tipo> *nodoMayor = nullptr;

        while (actual != nullptr) {
            if (nodoMayor == nullptr) {
                anteriorMayor = anterior;
                nodoMayor = actual;
            } else {
                if (actual->Dato > nodoMayor->Dato) {
                    anteriorMayor = anterior;
                    nodoMayor = actual;
                }
            }
            anterior = actual;
            actual = actual->SigPtr;
        }

        tipo datoBorrado = nodoMayor->Dato;

        // El nodo Mayor es primer puntero (head)
        if(anteriorMayor == nullptr) {
            PrimPtr = nodoMayor->SigPtr;
            delete nodoMayor;
            Dato = datoBorrado;
            Cant--;
            return true;
        }

        anteriorMayor->SigPtr = nodoMayor->SigPtr;
        delete nodoMayor;
        Dato= datoBorrado;
        Cant--;
        return true;


}

template<typename tipo>
bool lista<tipo>::EliminarPosicion(tipo &Dato, int n)
{
    if(Vacia() || n>Cant){
        return false;
    }else if(Cant==1 && n==1){
        EliminarInicio(Dato);
        return true;
    }else if(n==Cant){
        EliminarFin(Dato);
        return true;
    } else if (n > 1 && n < Cant) {
        nodo<tipo> *del = PrimPtr;
        for (int i = 1; i < n - 1; i++) {
            del = del->SigPtr;
        }
        nodo<tipo> *eliminarNodo = del->SigPtr;
        del->SigPtr = eliminarNodo->SigPtr;
        Dato = eliminarNodo->Dato;
        delete eliminarNodo;
        Cant--;
        actualizarUltimo();
        return true;
    }
    return false;
}



template<typename tipo>
bool lista<tipo>::Vacia()const
{
    return PrimPtr==0;
    //    if(PrimPtr->getDato()==nullptr){
}

template<typename tipo>
void lista<tipo>::Limpiar()
{
    lista<tipo>::~lista();
}

#endif // LISTA_H





