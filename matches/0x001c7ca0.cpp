#include "gen/Render.h"

struct StoreBase_1c7ca0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
struct Room_1c7ca0 {};

template <> int Render::Store<Render::Room>::vfunc_1(int __p0) { unsigned int x = (unsigned int)__p0;

    return (int)(x);
}
