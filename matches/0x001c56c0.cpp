#include "gen/Render.h"

class StoreBase_1c56c0 {
  public:
    virtual void f0();
    virtual int f1(int);
    virtual void f2();
};
class Object_1c56c0 {};

template <> int Render::Store<Render::Object>::vfunc_1(int value) {
    return value + 8;
}
