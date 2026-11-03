#include "compat/ptr.h"
#include "gen/owners.h"
class X_5a3f0 {
  public:
};
class Y_5a3f0 {
  public:
    int B();
};
extern "C" int __cdecl FUN_0005a3f0(X_5a3f0* param) {
    if (param != 0) {
        hulk_intptr a = ((int)((owners::Object_592a0 *)param)->FUN_000592a0());
        if (a != 0) {
            hulk_intptr b = ((Y_5a3f0*)a)->B();
            if (b != 0) {
                int c = *(int*)(b + 0x334);
                if (c != 0)
                    return c + 0xdc;
                int d = *(int*)(b + 0x330);
                if (d != 0)
                    return d + 0xdc;
            }
        }
    }
    return 0;
}