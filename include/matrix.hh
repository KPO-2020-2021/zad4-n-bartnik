#pragma once

#include "size.hh"
#include "vector.hh"
#include"rectangle.hh"
#include <iostream>
#include <cstdlib>
template <int SIZE>
class Matrix
{

private:
    double value[SIZE][SIZE]; // Wartosci macierzy
    double radian;

public:
   Matrix(double[SIZE][SIZE]); // Konstruktor klasy
    Matrix(); // Konstruktor bezparametryczny klasy
    Vector<SIZE> operator*(Vector<SIZE> tmp); // Operator mnożenia przez wektor
    Matrix<SIZE> operator+(Matrix<SIZE> tmp);
    double &operator()(unsigned int row, unsigned int column);
    const double &operator()(unsigned int row, unsigned int column) const;
    Matrix(double kat);
    void Obroc();

/*Funkcja rotacji. Mnoży prostokąt razy macierz. 
Konieczne wcześniejsze obrócenie macierzy*/
    void Rot(Prostokat &Pr) {Pr=*this*Pr;} 
 
  Prostokat operator*(Prostokat wektor);
  
};




/******************************************************************************
 |  Konstruktor klasy Matrix<SIZE>.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
template <int SIZE>
Matrix<SIZE>::Matrix() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = 0;
        }
    }
    radian=0;
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix<SIZE>.                                              |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                               |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
template <int SIZE>
Matrix<SIZE>::Matrix(double tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}


/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */
template <int SIZE>
Vector<SIZE> Matrix<SIZE>::operator * (Vector<SIZE> tmp) {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;

}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
template <int SIZE>
double &Matrix<SIZE>::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/******************************************************************************
 |  Funktor macierzy                                                ctor::odleglosc(Vector<SIZE> wek)
{      8          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
template <int SIZE>
const double &Matrix<SIZE>::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                  |
 */
template <int SIZE>
Matrix<SIZE> Matrix<SIZE>::operator + (Matrix<SIZE> tmp) {
    Matrix<SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
template <int SIZE>
std::istream &operator>>(std::istream &in, Matrix<SIZE> &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
template <int SIZE>
std::ostream &operator<<(std::ostream &out, const Matrix<SIZE> &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}

/*FUnkcja oblicza dla macierzy zadany kąt (ze stopni na radiany)*/
template <int SIZE>
Matrix<SIZE>::Matrix(double kat)
{
    radian = kat * M_PI / 180;
}

/*Funkcja tworzy macierz obrotu według wzoru podanego w instrukcji zadania*/
template <int SIZE>
void Matrix<SIZE>::Obroc()
{
    value[0][0] = cos(radian);
    value[0][1] = -sin(radian);
    value[1][0] = sin(radian);
    value[1][1] = cos(radian);
}

/*Funkcja mnoży prostokąt i macierz. Używana w rotacji prostokąta*/
template <int SIZE>
Prostokat Matrix<SIZE>::operator*(Prostokat prost)
{
    Prostokat wynik;
    for (int i = 0; i < 4; i++)
    {
        wynik[i] = (*this) * prost[i];
    }
    return wynik;
} 