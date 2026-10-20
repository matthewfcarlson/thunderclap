#include "compat/ptr.h"
extern int vderived;
class ParamValue {
  public:
    virtual void F();
    char pad[4];
};
class ValuePart {
  public:
    ValuePart(int);
};
class ParamValueVector : public ParamValue {
    ValuePart part;

  public:
    ParamValueVector(int);
    virtual void G();
};
ParamValueVector::ParamValueVector(int x) : part(x) {
    *((hulk_intptr*)this) = (hulk_intptr)&vderived;
}
