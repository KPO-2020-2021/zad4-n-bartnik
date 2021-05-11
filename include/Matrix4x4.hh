#pragma once
#include "matrix.hh"
#include <cmath>

typedef Matrix<4> Matrix4x4;

Matrix4x4 macierz_obrot_x(double kat, double alfa, double beta, double gamma, double x, double y, double z)
{
    double rad_alfa = alfa * M_PI / 180, rad_beta = beta * M_PI / 180, rad_gamma = gamma * M_PI / 180 Matrix4x4 obrot;
    obrot(0, 0) = cos(rad_alfa) * cos(rad_beta);
    obrot(0, 1) = cos(rad_alfa) * sin(rad_beta) * sin(rad_gamma) - sin(rad_alfa) * cos(rad_gamma);
    obrot(0, 2) = cos(rad_alfa) * sin(rad_beta) * cos(rad_gamma) + sin(rad_alfa) * sin(rad_gamma);
    obrot(0, 3) = x;

    obrot(1, 0) = cos(rad_alfa) * cos(rad_beta);
    obrot(1, 1) = cos(rad_alfa) * sin(rad_beta) * sin(rad_gamma) + sin(rad_alfa) * cos(rad_gamma);
    obrot(1, 2) = cos(rad_alfa) * sin(rad_beta) * cos(rad_gamma) - sin(rad_alfa) * sin(rad_gamma);
    obrot(1, 3) = y;

    obrot(2, 0) = -sin(rad_beta);
    obrot(2, 1) = cos(rad_beta) * sin(rad_gamma);
    obrot(2, 2) = cos(rad_beta) * cos(rad_gamma);
    obrot(2, 3) = z;

    obrot(3, 0) = 0;
    obrot(3, 1) = 0;
    obrot(3, 2) = 0;
    obrot(3, 3) = 1;
}
