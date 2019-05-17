#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"

class putvoxel : public FiguraGeometrica
{
public:
    putvoxel();
    ~putvoxel();
    void draw(Sculptor &t);
};

#endif // PUTVOXEL_H
