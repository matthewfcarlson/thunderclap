// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// pure3d::ExpressionLoader::vfunc_5 @ 0x002afba0
#include "compat/ptr.h"
#include "gen/pure3d.h"

extern "C" void *__cdecl FUN_00263ea0(unsigned int size);
extern "C" void *__cdecl FUN_0008d6d0(hulk_uintptr size);
unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);
inline void *operator new(unsigned int, void *p) throw() { return p; }

struct Name_2afba0 {
    char data[8];
    void FUN_0027b040(const char *s);
};

namespace pure3d {
class __declspec(novtable) Entity_2afba0 {
public:
    virtual void e0();
    char pad4[4];
    Name_2afba0 name;
    void FUN_0027b070();
    Entity_2afba0() throw() { FUN_0027b070(); }
};

class Expression_2afba0 : public Entity_2afba0 {
public:
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4();
    unsigned int count;
    int *keys;
    float *values;
    Expression_2afba0() throw() { keys = 0; values = 0; }
};
}

struct Reader_2afba0 {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream_2afba0 {
    char pad0[0x284];
    Reader_2afba0 *reader;
};

union Cell_2afba0 {
    int i;
    float f;
};

struct Frame_2afba0 {
    char pad[3];
    unsigned char len;
    Cell_2afba0 cell;
    char name[0x100];
};

void pure3d::ExpressionLoader::vfunc_5(void* __p0, void* __p1, void* __p2, int __p3) { pure3d::Expression_2afba0 ** out = (pure3d::Expression_2afba0 **)__p0; unsigned long long * outId = (unsigned long long *)__p1; Stream_2afba0 * s = (Stream_2afba0 *)__p2; void * ctx = (void *)__p3;

    Frame_2afba0 f;
    s->reader->FUN_002647e0(&f.cell, 1, 4, 1);
    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    s->reader->FUN_002647e0(f.name, f.len, 1, 1);
    f.name[f.len] = 0;

    void *mem = FUN_00263ea0(0x20);
    pure3d::Expression_2afba0 *e = 0;
    if (mem)
        e = new (mem) pure3d::Expression_2afba0();
    e->name.FUN_0027b040(f.name);

    s->reader->FUN_002647e0(&f.cell, 1, 4, 1);
    e->count = f.cell.i;
    e->values = (float *)FUN_0008d6d0(f.cell.i * 4);
    e->keys = (int *)FUN_0008d6d0(e->count * 4);
    for (unsigned int i = 0; i < e->count; i++) {
        s->reader->FUN_002647e0(&f.cell, 1, 4, 1);
        e->values[i] = f.cell.f;
    }
    for (unsigned int i = 0; i < e->count; i++) {
        s->reader->FUN_002647e0(&f.cell, 1, 4, 1);
        e->keys[i] = f.cell.i;
    }
    *out = e;
    *outId = FUN_002672f0(f.name, 0);
}
