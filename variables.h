#ifndef VARIABLES_H
#define VARIABLES_H

#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QArrayData>


class Variable
{
public:
    int tipo_;
    QString valor;

    Variable(int tipo_, QString valor);
    Variable();
};




class array1{

public:
    int tipo;
    int tamanio;
    QStringList arreglo;

    array1(int tipo, int taminaio);
    array1();
    bool anadir(int index, QString valor);

    QString obtener(int index);

};


class array2{};
class array3{};

#endif // VARIABLES_H
