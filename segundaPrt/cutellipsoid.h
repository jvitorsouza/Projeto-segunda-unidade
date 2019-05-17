#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"


class cutellipsoid : public FiguraGeometrica
{
public:
    cutellipsoid();
    ~cutellipsoid();
    void draw(Sculptor &t);
};

#endif // CUTELLIPSOID_H
