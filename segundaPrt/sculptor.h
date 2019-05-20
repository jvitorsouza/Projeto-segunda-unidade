#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;


struct Voxel {
  float r, g, b,a;
  bool isOn;
};

class Sculptor {
protected:
  int nx, ny, nz;
  Voxel ***vx;
  float r,g,b,a;
public:
  Sculptor();
  Sculptor(int _nx, int _ny, int _nz);
  ~Sculptor();

  void setColor(float red, float green, float blue, float alpha);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void writeOFF(string filename);
  void writeVECT(string filename);
};

#endif // SCULPTOR_H
