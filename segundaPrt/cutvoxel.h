#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"

class cutvoxel : public FiguraGeometrica
{
public:
    cutvoxel();
    ~cutvoxel();
    void draw(Sculptor &t);
};

#endif // CUTVOXEL_H
