// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "../include/exampleConfig.h.in"
#include "../include/example.h"
#include "../include/vector3D.hh"
#include "../include/Matrix3x3.hh"
#include "../include/Cuboid.hh"
#include "../include/lacze_do_gnuplota.hh"

/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */

#define DL_KROTKI_BOK 100
#define DL_DLUGI_BOK 150

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i Cuboida
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void PrzykladZapisuWspolrzednychDoStrumienia(std::ostream &StrmWy,
                                             double Przesuniecie)
{
       //----------------------------------------------std::
       //
       double x1, y1, x2, y2, x3, y3, x4, y4;

       x1 = y1 = 10;
       x2 = x1 + DL_DLUGI_BOK;
       y2 = y1;
       x3 = x2;
       y3 = y2 + DL_KROTKI_BOK;
       x4 = x3 - DL_DLUGI_BOK;
       y4 = y3;

       StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x1 + Przesuniecie
              << std::setw(16) << std::fixed << std::setprecision(10) << y1 + Przesuniecie << std::endl;
       StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x2 + Przesuniecie
              << std::setw(16) << std::fixed << std::setprecision(10) << y2 + Przesuniecie << std::endl;
       StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x3 + Przesuniecie
              << std::setw(16) << std::fixed << std::setprecision(10) << y3 + Przesuniecie << std::endl;
       StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x4 + Przesuniecie
              << std::setw(16) << std::fixed << std::setprecision(10) << y4 + Przesuniecie << std::endl;
       StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x1 + Przesuniecie
              << std::setw(16) << std::fixed << std::setprecision(10) << y1 + Przesuniecie << std::endl;
       /*Jeszcze raz zapisujemy pierwszy punkt,
       aby gnuplot narysowal zamkniętą linię.*/
}

bool PrzykladZapisuWspolrzednychDoPliku(const char *sNazwaPliku,
                                        Cuboid Pr)
{
       std::ofstream StrmPlikowy;

       StrmPlikowy.open(sNazwaPliku);
       if (!StrmPlikowy.is_open())
       {
              std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
                        << ":(  nie powiodla sie." << std::endl;
              return false;
       }

       StrmPlikowy << Pr;

       StrmPlikowy.close();
       return !StrmPlikowy.fail();
}

int main()
{
       char menu;
       double kat, tab[2] = {20, 30};
       Vector3D wektor_trans;
       Vector3D wektor(tab);
       Cuboid Pr(wektor, 50, 50, 50);

       //wysokosc i długosc Cuboida
       // std::cout << "Project Rotation 2D based on C++ Boiler Plate v"
       //           << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
       //           << "."
       //           << PROJECT_VERSION_MINOR /* istotne zmiany */
       //           << "."
       //           << PROJECT_VERSION_PATCH /* naprawianie bugów */
       //           << "."
       //           << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
       //           << std::endl;

       PzG::LaczeDoGNUPlota Lacze; // Ta zmienna jest potrzebna do wizualizacji
                                   // rysunku Cuboida

       //-------------------------------------------------------
       //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
       //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
       //  na dwa sposoby:
       //   1. Rysowane jako linia ciagl o grubosci 2 piksele
       //
       Lacze.DodajNazwePliku("../datasets/Cuboid.dat", PzG::RR_Ciagly, 2);
       //
       //  Ustawienie trybu rysowania 3D, tzn. rysowany zbiór punktów
       //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
       //  jako wspolrzedne punktow podajemy x,y,z.
       //
       Lacze.ZmienTrybRys(PzG::TR_3D);

       // Ustawienie zakresow poszczegolnych osi
       Lacze.UstawZakresY(-155, 155);
       Lacze.UstawZakresX(-155, 155);
       Lacze.UstawZakresZ(-155, 155);

       if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Cuboid.dat", Pr))
              return 1;
       Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku

       //----------------------------------------------------------
       // Ponownie wypisuje wspolrzedne i rysuje prostokąt w innym miejscu.
       //
       
       Matrix3x3 mac2;
       char os;
       while (menu != 'k')
       {

              std::cout << "Wybierz jedna z dostepnych opcji: " << std::endl;
              std::cout << "o - obrot cuboida o zadany kat" << std::endl;
              std::cout << "t - powtorzenie poprzedniego obrotu" << std::endl;
              std::cout << "p - przesuniecie cuboida o zadany wektor" << std::endl;
              std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
              std::cout << "m - wyswietl menu" << std::endl;
              std::cout << "k - koniec dzialania programu" << std::endl;
              std::cin >> menu;

              switch (menu)
              {
              case 'o':
              {

                     Matrix3x3 mac;
                     
                     
                            std::cout << "os" << std::endl;
                            std::cin >> os;
                            if (os == '.')
                                   break;
                            std::cout << "podaj kat" << std::endl;
                            std::cin >> kat;
                            if (os == 'x')
                                   mac = mac * macierz_obrot_x(kat);
                            if (os == 'y')
                                   mac = mac * macierz_obrot_y(kat);
                            if (os == 'z')
                                   mac = mac * macierz_obrot_z(kat);
                     
                     mac2 = mac;
                     Pr.rot(mac);
              }
              break;
              case 't':
              {
                     Pr.rot(mac2);
              }
              break;
              case 'p':
              {
                     std::cout << "Podaj wektor translacji" << std::endl;
                     std::cin >> wektor_trans;
                     Pr = Pr + wektor_trans;
              }
              break;
              case 'w':
              {
                     std::cout << Pr;
              }
              break;
              case 'm':
                     break;
              case 'k':
              {
                     std::cout << "Koniec dzialania programu." << std::endl;
              }
              break;
              default:
              {
                     std::cout << "Bledna opcja" << std::endl;
              }
              break;
              }
              if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Cuboid.dat", Pr))
                     return 1;
              Lacze.Rysuj();
       }
       return 0;
}
