#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "../include/vector.hh"
#include "../include/Cuboid.hh"
#include "../include/matrix.hh"
#include "../include/size.hh"


TEST_CASE("konstruktor parametryczny")
{
    double a = 1.0, b = 2.0, c=3.0 ;
    Vector3D wektor  /*( a, b )*/  ;

    wektor[0] = a;
    wektor[1] =b;
    wektor[2] =c;

    CHECK(wektor[0] == 1);
    CHECK(wektor[1] == 2);
    CHECK(wektor[2] == 3);
}


TEST_CASE("konstruktor bezparametryczny")
{

    Vector3D wektor;

    CHECK(wektor[0] == 0);
    CHECK(wektor[1] == 0);
    CHECK(wektor[2] == 0);
}

TEST_CASE("Dodawanie wektorów")
{
    double tab1[3]={1,2,3};
    double tab2[3]={2,1,3};
    Vector3D wektor1(tab1);
    Vector3D wektor2(tab2);
    Vector3D wynik;

    wynik = wektor1 + wektor2;
    CHECK(wynik[0] == 3);
    CHECK(wynik[1] == 3);
    CHECK(wynik[2] == 6);
}

TEST_CASE("Odejmowanie wektorów")
{
    double tab1[3]={1,2,3};
    double tab2[3]={2,1,3};
    Vector3D wektor1(tab1);
    Vector3D wektor2(tab2);
    Vector3D wynik;

    wynik = wektor1 - wektor2;
    CHECK(wynik[0] == -1);
    CHECK(wynik[1] == 1);
    CHECK(wynik[2] == 0);
}

TEST_CASE("wektor * stała")
{
    double tab1[3]={1,2,3};
    Vector3D wektor1(tab1);
    double a = 2;
    Vector3D wynik;

    wynik = wektor1 * a;
    CHECK(wynik[0] == 2);
    CHECK(wynik[1] == 4);
    CHECK(wynik[2] == 6);
}

TEST_CASE("wektor - wyświetlanie")
{
    double tab1[3]={1,2,3};
    Vector3D wektor1(tab1);
    // double a[2]={1,2};
    std::ostringstream StrmWyj;
    StrmWyj << wektor1;
    std::cout << StrmWyj.str();
    CHECK("1 2 3 " == StrmWyj.str());
}

TEST_CASE("wektor - wpisywanie")
{
    Vector3D a;

    std::istringstream in("1 1 1");
    in >> a;
    std::ostringstream out;
    out << a;

    CHECK("1 1 1 " == out.str());
}

TEST_CASE("operator porownania")
{
    double tab1[3]={1,2,3};
    Vector3D wektor1(tab1);
    Vector3D wektor2(tab1);

    CHECK(wektor1 == wektor2);
}

TEST_CASE("operator porownania")
{
    double tab1[3]={1,2,3};
    Vector3D wektor1(tab1);
    Vector3D wektor2(tab1);

    CHECK(wektor1 == wektor2);
}

// TEST_CASE("mierzenie odległosci")
// {
//     double tab1[3]={1,2,3};
//     double wynik;
//     Vector3D wektor1(tab1);
//     Vector3D wektor2(tab1);

//     wynik = wektor1.spr(wektor2) ;

//     CHECK(wynik == 0);
// }

/********************MACIERZ**********************/

TEST_CASE("konstruktor parametryczny")
{

    double tab[3][3] = {{2,2,2}, {2,2,2}};
    Matrix3x3 macierz(tab);

    CHECK(macierz(0, 0) == 2);
    CHECK(macierz(0, 1) == 2);
    CHECK(macierz(0, 2) == 2);
    CHECK(macierz(1, 0) == 2);
    CHECK(macierz(1, 1) == 2);
    CHECK(macierz(1, 2) == 2);
}

TEST_CASE("konstruktor bezparametryczny")
{

    Matrix3x3 macierz;

    CHECK(macierz(0, 0) == 1);
    CHECK(macierz(0, 1) == 0);
    CHECK(macierz(0, 2) == 0);
    CHECK(macierz(1, 0) == 0);
    CHECK(macierz(1, 1) == 1);
    CHECK(macierz(1, 2) == 0);
}


TEST_CASE("macierz mnożenie * wektor")
{
    double tab1[3]={1,2,3};
    double tab2[3]={0,0,0};
    Vector3D wektor1(tab1);
    Vector3D wektor2(tab2);
    Matrix3x3 macierz;

    wektor1 = macierz * wektor2;
    CHECK(wektor1 == wektor2);
}
