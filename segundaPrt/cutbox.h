#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"

class CutBox : public FiguraGeometrica
{
public:
    CutBox();
    ~CutBox();
    void draw(Sculptor &t);
};

#endif // CUTBOX_H
