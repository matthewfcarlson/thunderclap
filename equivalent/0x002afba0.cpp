// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// pure3d::ExpressionLoader::vfunc_5 @ 0x002afba0
extern "C" void *__cdecl FUN_00263ea0(unsigned int size);
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);
unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);
inline void *operator new(unsigned int, void *p) throw() { return p; }

struct Name_2afba0 {
    char data[8];
    void FUN_0027b040(const char *s);
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void e0();
    char pad4[4];
    Name_2afba0 name;
    void FUN_0027b070();
    Entity() throw() { FUN_0027b070(); }
};

class Expression : public Entity {
public:
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4();
    unsigned int count;
    int *keys;
    float *values;
    Expression() throw() { keys = 0; values = 0; }
};
}

struct Reader {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
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

class ExpressionLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(pure3d::Expression **out, unsigned __int64 *outId, Stream *s, void *ctx);
};

void ExpressionLoader::vfunc_5(pure3d::Expression **out, unsigned __int64 *outId, Stream *s, void *ctx)
{
    Frame_2afba0 f;
    s->reader->FUN_002647e0(&f.cell, 1, 4, 1);
    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    s->reader->FUN_002647e0(f.name, f.len, 1, 1);
    f.name[f.len] = 0;

    void *mem = FUN_00263ea0(0x20);
    pure3d::Expression *e = 0;
    if (mem)
        e = new (mem) pure3d::Expression();
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
