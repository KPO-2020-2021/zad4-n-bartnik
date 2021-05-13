
#include "../include/Matrix3x3.hh"

/*FUnkcja obraca oś względem osi OX. Przyjmuje kąt i przelicza go na radiany, zwraca
macierz obrotu. Dla każdego indeksu macierzy wpisuje do komórki wartości zgodnie 
ze wzorem na obrót macirzy. Do wartości przypisanych zmiennej X przypisane jest 0 ze względu na to, że 
ta wartość ma się nie zmieniać. Jedynie dla współrzędnych macierzy 0,0 (czyli x,x) jest przypisana wartość 1 
zgodnie ze wzorem udostępnionym w instrukcji labolatoryjnej*/
Matrix3x3 macierz_obrot_x(double kat){
    double rad = kat * M_PI/180;
    Matrix3x3 obrot;
    obrot(0, 0) = 1;
    obrot(0, 1) = 0;
    obrot(0, 2) = 0;

    obrot(1, 0) = 0;
    obrot(1, 1) = cos(rad);
    obrot(1, 2) = -sin(rad);

    obrot(2, 0) = 0;
    obrot(2, 1) = sin(rad);
    obrot(2, 2) = cos(rad);
    return obrot;
}

/*FUnkcja obraca oś względem osi OY. Przyjmuje kąt i przelicza go na radiany, zwraca
macierz obrotu. Dla każdego indeksu macierzy wpisuje do komórki wartości zgodnie 
ze wzorem na obrót macirzy. Do wartości przypisanych zmiennej Y przypisane jest 0 ze względu na to, że 
ta zmienna ma się nie zmieniać. Jedynie dla współrzędnych macierzy 1,1 (czyli y,y) jest przypisana wartość 1 
zgodnie ze wzorem udostępnionym w instrukcji labolatoryjnej*/
Matrix3x3 macierz_obrot_y(double kat)
{
    double rad = kat * M_PI / 180;
    Matrix3x3 obrot;
    obrot(0, 0) = cos(rad);;
    obrot(0, 1) = 0;
    obrot(0, 2) = sin(rad);

    obrot(1, 0) = 0;
    obrot(1, 1) = 1;
    obrot(1, 2) = 0;

    obrot(2, 0) = -sin(rad);
    obrot(2, 1) = 0;
    obrot(2, 2) = cos(rad);
    return obrot;
}

/*FUnkcja obraca oś względem osi OZ. Przyjmuje kąt i przelicza go na radiany, zwraca
macierz obrotu. Dla każdego indeksu macierzy wpisuje do komórki wartości zgodnie 
ze wzorem na obrót macirzy. Do wartości przypisanych zmiennej Z przypisane jest 0 ze względu na to, że 
ta zmienna ma się nie zmieniać. Jedynie dla współrzędnych macierzy 2,2 (czyli z,z) jest przypisana wartość 1 
zgodnie ze wzorem udostępnionym w instrukcji labolatoryjnej*/
Matrix3x3 macierz_obrot_z(double kat)
{
    double rad = kat * M_PI / 180;
    Matrix3x3 obrot;
    obrot(0, 0) = cos(rad);;
    obrot(0, 1) = -sin(rad);
    obrot(0, 2) = 0;

    obrot(1, 0) = sin(rad);
    obrot(1, 1) = cos(rad);
    obrot(1, 2) = 0;

    obrot(2, 0) = 0;
    obrot(2, 1) = 0;
    obrot(2, 2) = 1;
    return obrot;
}