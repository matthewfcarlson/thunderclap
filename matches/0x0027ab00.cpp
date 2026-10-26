#include "decls/data/engine/global.h"
// data: fmt_27ab00 = DAT_0042c120

extern int Format(char*, const char*, float*, float*, float*);
class Obj_27ab00 {
  public:
    char pad[0x10];
    int index;
    char rest[1];
    bool Check(int);
    bool Run(int a, float* p);
};
bool Obj_27ab00::Run(int a, float* p) {
    if (Check(a))
        return Format((char*)((char*)this + 0xd38 + index * 0x60), DAT_0042c120, p, (float*)((char*)p + 4),
                      (float*)((char*)p + 8)) == 3;
    return false;
}