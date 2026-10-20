#include "compat/ptr.h"
#include "decls/data/game/global.h"

struct Matrix {
    unsigned int data[16];
    void FUN_0022c3b0(unsigned int, unsigned int);
    void FUN_0022c2b0(unsigned int, unsigned int);
};
struct Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int type();
    char pad[0x48];
    Matrix matrix;
    char pad2[0x40];
    unsigned char enabled;
    void FUN_00306600(unsigned int);
};
struct Record_304530 {
    Matrix matrix;
    unsigned int extra;
    void FUN_002f8ec0(unsigned int, unsigned int, Object*, unsigned int, unsigned int, unsigned int);
};
struct Renderer_304530 {
    void FUN_00314be0(unsigned int, unsigned int, Object*, unsigned int, unsigned int, unsigned int);
};
struct Global_304530 {
    char pad[0x70];
    Renderer_304530 renderer;
};
struct Queue_304530 {
    unsigned int field0;
    Record_304530* next;
    Record_304530* end;
    void FUN_00304500();
    void target(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e,
                Object* object, unsigned int flags);
};
void Queue_304530::target(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e,
                   Object* object, unsigned int flags) {
    Record_304530 temp;
    if (object->type() == 4 && object->enabled) {
        temp.matrix = object->matrix;
        temp.matrix.FUN_0022c3b0(e, e);
        temp.matrix.FUN_0022c2b0(d, d);
    }
    if (flags & 1) {
        object->FUN_00306600(b);
        (*(Global_304530**)&DAT_00554c14)->renderer.FUN_00314be0(a, d, object, d, c, e);
    } else if (flags & 2) {
        object->FUN_00306600(b);
        temp.FUN_002f8ec0(a, d, object, d, c, e);
        Record_304530* dest = next;
        if ((hulk_uintptr)dest < (hulk_uintptr)end) {
            next = dest + 1;
            if (dest)
                *dest = temp;
        }
        if (flags & 8)
            FUN_00304500();
    }
}
