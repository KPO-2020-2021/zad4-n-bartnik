#include "../include/Cuboid.hh"
using namespace std;

/*Fuckja buduje prostopadłościan. Przyjmuje wektor zawierający współrzędne jednego z punktów.
A następnie wysokość, długość przekatnej i długość prostopadłościanu (wpisywane standardowym wejściem).
Na podstawie tych danych oblicza współrzędne pozostałych wierzchołków*/
Cuboid::Cuboid(Vector3D pkt, double h, double w, double r)
{

    for (int i = 0; i < 8; i++)
    {
        pkt1[i] = pkt;
    }

    pkt1[1][0] += h;

    pkt1[2][1] += w;

    pkt1[3][0] += h;
    pkt1[3][1] += w;

    pkt1[4][1] += w;
    pkt1[4][2] += r;

    pkt1[5][0] += h;
    pkt1[5][1] += w;
    pkt1[5][2] += r;

    pkt1[6][2] += r;

    pkt1[7][0] += h;
    pkt1[7][2] += r;
}

/*FUnkcja wypisuje kolejne wierzchołki prostopadłościanu, zawiera dodatkowy warunek
kiedy następna indeks wierzchołka jest parzysty to wypisuje nową linię (jest to 
potzebne by narysować prostopadłościan)*/
std::ostream &operator<<(std::ostream &Strm,
                         const Cuboid &Pr)
{
    for (int i = 0; i < 8; i++)
    {
        Strm << Pr[i] << endl;
        if((i+1)%2==0) {
            Strm<<endl;
        } 
    }
    Strm << Pr[0] << endl;
    Strm << Pr[1] << endl;
    return Strm;
}

/*Funkcja dodaje do prostopadłościanu wektor. Używana w translacji*/
Cuboid Cuboid::operator+(Vector3D wektor)
{
    Cuboid wynik;
    for (int i = 0; i < 8; i++)
    {
        wynik[i] = pkt1[i] + wektor;
    }
    return wynik;
}

// /*Funkcja sprawdzająca odległosci boków*/
// double Cuboid::odleglosci()
// {

//     /*deklaracja zmiennych przechowujących długości boków*/
//     double ab, bc, cd, da, wynik;
//     /*wyliczenie długości boków*/
//     ab = pkt1[0].odleglosc(pkt1[1]);
//     bc = pkt1[1].odleglosc(pkt1[2]);
//     cd = pkt1[2].odleglosc(pkt1[3]);
//     da = pkt1[3].odleglosc(pkt1[0]);
//     wynik = ab+bc+cd+da;
//     if (ab != cd || da != bc)
//     {
//         std::cout << "Podane boki są różne. Długości boków to:" << endl;
//         std::cout << "AB = " << ab << endl;
//         std::cout << "BC = " << bc << endl;
//         std::cout << "CD = " << cd << endl;
//         std::cout << "DA = " << da << endl;
//     }
//     else
//     {
//         wynik = ab+bc+cd+da;
//         std::cout << "Podane boki są równe" << endl;
//     }
//    return wynik;
// }