#include "decls/address.h"
typedef unsigned char u8;
struct NodeIsNotRunningCondition {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(void*, void*, void*);
    char pad[8];
    u8 mValue;
};
extern int FUN_00344e74(void*, int, const void*, const void*, int);
struct Runner_1a49c0 {
    bool run(int);
};
struct World {
    char pad[0x30];
    Runner_1a49c0* runner;
};
extern char DAT_0048e0ac;
extern char DAT_0048e090;
bool NodeIsNotRunningCondition::vfunc_6(void* arg, void*, void*) {
    bool result = false;
    int value = FUN_00344e74(arg, 0, &DAT_0048e090, &DAT_0048e0ac, 0);
    if (value)
        result = DAT_004dd700->runner->run(value);
    return result != mValue;
}