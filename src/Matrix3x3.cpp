
#include "../include/Matrix3x3.hh"

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