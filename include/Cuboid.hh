
#pragma once

#include <iostream>
#include <cmath>
#include "Matrix3x3.hh"
#include "vector3D.hh"
#include "size.hh"

class Cuboid
{
  Vector3D pkt1[8];

public:
  Cuboid(){};
  Cuboid(Vector3D pkt, double h, double w, double r);
  Vector3D operator[](int Ind) const { return pkt1[Ind]; }
  Vector3D &operator[](int Ind) { return pkt1[Ind]; }
  Cuboid operator+(Vector3D wektor);
  double odleglosci();
  void rot(Matrix3x3 mac)
  {
    for(int i=0; i<8; i++)
    {
      pkt1[i]=mac*pkt1[i];
    }
  }
  void trans(Vector3D wektor)
  {
    *this = *this + wektor;
  }

};

/*
 Operator wypisywania, przyjmuje prostokąt
 */
std::ostream &operator<<(std::ostream &Strm,
                         const Cuboid &Pr);