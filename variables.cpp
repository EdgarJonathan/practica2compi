#include "variables.h"

//******************************************************************************
//***************************Variables ************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
Variable::Variable(int tipo_, QString valor)
{
    this->tipo_ = tipo_;
    this->valor =valor;



}

//******************************************************************************
//*************************** Array1************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************


array1::array1(int tipo, int tamanio){


    this->tamanio = tamanio;
    this->tipo =tipo;
    for (int x= 0; x< tamanio; x++)
    {
        arreglo.insert(0,"null");

    }


    QTextStream(stdout) << "tamanio: "+QString::number(arreglo.size()) << endl;

}

bool array1::anadir(int index, QString valor){

    if(index<tamanio){

        arreglo.insert(index,valor);

        return true;
    }else{

        return false;
    }

}

QString array1::obtener(int index){

    if(index<tamanio){

        return  arreglo.at(index);


    }else{

        return "vacio";
    }

}
