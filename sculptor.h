#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Voxel
{
    float r, g, b; // cores
    float a; // transparencia
    bool isOn; // incluir ou nao o voxel
};

class sculptor
{
public:
    sculptor(int _nx, int _ny, int _nz);
    ~sculptor();
    void setColor(float r, float g, float b, float alpha);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void writeOFF(string filename);
    void writeVECT(string filename);
    void print();
    Voxel& operator () (int i, int j, int k);

private:
    Voxel ***v; // matriz 3D
    int nx, ny, nz; // dimençoes da matriz
    float r, g, b, a;
};

#endif // SCULPTOR_H
