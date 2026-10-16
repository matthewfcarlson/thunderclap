#include "gen/pure3d.h"

class Object_31b830 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
};
class Helper_31b830 {
  public:
    int f(int);
};
extern "C" int __cdecl FUN_0008d690(int);

int pure3d::d3dDevice::vfunc_7(int arg) {
    int result = FUN_0008d690(0x49c);
    if (result)
        return ((Helper_31b830*)result)->f(*(int*)((char*)this + 0x10));
    return 0;
}
