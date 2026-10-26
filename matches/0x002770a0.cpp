#include "compat/ptr.h"
#include "decls/data/engine/core.h"
// data: g_obj_2770a0 = DAT_0052a224

struct Drive {
    virtual void v0();
    virtual void v1();
    virtual void v2(unsigned char);
};
struct Obj_2770a0 {
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4(void*);
};
extern void f850(void*);
extern void f840(void*);
extern void* vtmain;
extern void* vtbase;
extern void* vtref;
class InstanceDrive {
  public:
    virtual void v0();
    virtual void v1();
    virtual InstanceDrive* vfunc_2(unsigned char);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    char pad[8];
    Drive* drive;
};
InstanceDrive* InstanceDrive::vfunc_2(unsigned char flag) {
    *(void**)this = &vtmain;
    *(void**)((char*)this + 4) = &vtbase;
    drive->v1();
    *(void**)this = &vtref;
    if (flag & 1) {
        f850((void*)((hulk_intptr)DAT_0052a208));
        (*(Obj_2770a0**)&DAT_0052a224)->x4(this);
        f840((void*)((hulk_intptr)DAT_0052a208));
    }
    return this;
}