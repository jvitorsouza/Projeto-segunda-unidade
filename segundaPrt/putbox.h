#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"

class PutBox : public FiguraGeometrica{
public:
  PutBox();
  ~PutBox();
  void draw(Sculptor &t);
};

#endif // BOX_H
