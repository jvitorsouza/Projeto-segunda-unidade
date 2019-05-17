#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"

class cutsphere : public FiguraGeometrica
{
public:
    cutsphere();
    ~cutsphere();
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
