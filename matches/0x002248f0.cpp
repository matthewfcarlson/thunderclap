#include "decls/data/engine/choreo2.h"
// data: gCount_2248f0 = DAT_004e5aac

#include "compat/ptr.h"
extern "C" char DAT_004272f0[];
class JointDriver {
  public:
    char pad[0x18];
    void Init();
    JointDriver(int arg);
};
extern void __fastcall BaseInit(void*);
JointDriver::JointDriver(int arg) {
    BaseInit((void*)(this));
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004272f0);
    *(int*)((char*)this + 0x10) = arg;
    *(int*)((char*)this + 0x14) = 3;
    ((JointDriver*)((char*)this + 0x18))->Init();
    int a = (*(int*)&DAT_004e5aac);
    int b = (*(int*)&DAT_004e5ab0);
    a++;
    (*(int*)&DAT_004e5aac) = a;
    if (a > b)
        (*(int*)&DAT_004e5ab0) = a;
}
