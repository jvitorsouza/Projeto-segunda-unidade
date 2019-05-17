#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"

class PutSphere : public FiguraGeometrica
{
public:
  PutSphere();
  ~PutSphere();
  void draw(Sculptor &t);
};

#endif // PUTSPHERE_H
