#pragma once
#include "matrix.hh"
#include <cmath>

typedef Matrix<3> Matrix3x3;

Matrix3x3 macierz_obrot_x(double kat);
Matrix3x3 macierz_obrot_y(double kat);

Matrix3x3 macierz_obrot_z(double kat);