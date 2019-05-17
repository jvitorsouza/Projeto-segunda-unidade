#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"

class putellipsoid : public FiguraGeometrica
{
public:
    putellipsoid();
    ~putellipsoid();
    void draw(Sculptor &t);
};

#endif // PUTELLIPSOID_H
