
#pragma once

#include "size.hh"
#include <iostream>
#include <cmath>
template <int SIZE>
class Vector {

private:

    double size[SIZE];     //Tablica wektora

public:

    Vector();

    Vector(double size[SIZE])  ;

    Vector<SIZE> operator + (const Vector<SIZE> &v);

    Vector<SIZE> operator - (const Vector<SIZE> &v);

    Vector<SIZE> operator * (const double &tmp);

    Vector<SIZE> operator / (const double &tmp);

    const double &operator [] (int index) const;

    double &operator [] (int index);
    bool operator==(Vector<SIZE> wek) const;
    double odleglosc (Vector<SIZE> wek);

};




/******************************************************************************
 |  Konstruktor klasy Vector<SIZE>.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
template <int SIZE>
Vector<SIZE>::Vector()
{
    for (int i = 0; i < SIZE; ++i)
    {
        size[i] = 0;
    }
}

/******************************************************************************
 |  Konstruktor klasy Vector<SIZE>.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */
template <int SIZE>
Vector<SIZE>::Vector(double size[SIZE])
{
     for (int i = 0; i < SIZE; ++i)
    {
        this->size[i] = size[i];
    }
}

/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator+(const Vector<SIZE> &v)
{
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] += v[i];
    }
    return result;
}

/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator-(const Vector<SIZE> &v)
{
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] -= v[i];
    }
    return result;
}

/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator*(const double &tmp)
{
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] *= tmp;
    }
    return result;
}

/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator/(const double &tmp)
{
    Vector<SIZE> result;

    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] / tmp;
    }

    return result;
}

/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
template <int SIZE>
const double &Vector<SIZE>::operator[](int index) const
{
    if (index < 0 || index >= SIZE)
    {
        throw "Error: Wektor jest poza zasiegiem!";

    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return size[index];
}

/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
template <int SIZE>
double &Vector<SIZE>::operator[](int index)
{
    return const_cast<double &>(const_cast<const Vector<SIZE> *>(this)->operator[](index));
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
template <int SIZE>
std::ostream &operator<<(std::ostream &out, Vector<SIZE> const &tmp)
{
    for (int i = 0; i < SIZE; ++i)
    {
        out << tmp[i] << " ";
    }
    return out;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
template <int SIZE>
std::istream &operator>>(std::istream &in, Vector<SIZE> &tmp)
{
    for (int i = 0; i < SIZE; ++i)
    {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}

/*Funkcja porównuje ze sobą dwa wektory - wektor oryginalny i wektor podany do funkcji*/
template <int SIZE>
bool Vector<SIZE>::operator==(Vector<SIZE> wek) const
{
        for (int i = 0; i < SIZE; ++i)
    if (wek[i] != size[i] )
        return false;

    return true;
}
template <int SIZE>
double Vector<SIZE>::odleglosc(Vector<SIZE> wek)
{     /* dY, dX - odleglosci bokow */
    double wynik, suma=0;
    for(int i=0; i<SIZE; i++){
    suma += pow(this->size[i] - wek[i],2);
    
    }
    wynik = sqrt(suma); /* liczy pierwiastek z sumy kwadratów odległosći */
    return wynik;
}
