// STATUS: equivalent (tools/equiv.py level 3: 61 inputs, branch coverage 8/8)
// pure3d::LocatorLoader::vfunc_5 @ 0x002c1770
#include "gen/pure3d.h"

unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);
void *__cdecl FUN_00263ea0(unsigned int size);
inline void *operator new(unsigned int, void *p) throw() { return p; }

struct Name_2c1770 {
    char data[8];
    void FUN_0027b040(const char *s);
};

struct Vec3_2c1770 { float x, y, z; };
struct Quat_2c1770 { float x, y, z, w; };

namespace pure3d {
class __declspec(novtable) Entity_2c1770 {
public:
    virtual void e0();
    char pad4[4];
    Name_2c1770 name;
    void FUN_0027b070();
    Entity_2c1770() throw() { FUN_0027b070(); }
};

class Locator_2c1770 : public Entity_2c1770 {
public:
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4();
    Vec3_2c1770 position;
    Quat_2c1770 rotation;
    Locator_2c1770() throw() {
        rotation.x = 0.0f;
        rotation.y = 0.0f;
        rotation.z = 0.0f;
        rotation.w = 1.0f;
    }
};
}

struct Reader_2c1770 {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream_2c1770 {
    char pad0[0x284];
    Reader_2c1770 *reader;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

struct Frame_2c1770 {
    char pad[3];
    unsigned char len;
    float pos[3];
    float quat[4];
    int count;
    char name[0x100];
};

void pure3d::LocatorLoader::vfunc_5(void* __p0, void* __p1, void* __p2, int __p3) { pure3d::Locator_2c1770 ** out = (pure3d::Locator_2c1770 **)__p0; unsigned long long * outId = (unsigned long long *)__p1; Stream_2c1770 * s = (Stream_2c1770 *)__p2; void * ctx = (void *)__p3;

    Frame_2c1770 f;
    Reader_2c1770 *rd = s->reader;
    rd->FUN_002647e0(&f.len, 1, 1, 1);
    s->reader->FUN_002647e0(f.name, f.len, 1, 1);
    s->reader->FUN_002647e0(&f.count, 1, 4, 1);
    f.name[f.len] = 0;
    s->reader->FUN_002647e0(f.pos, 3, 4, 1);

    void *mem = FUN_00263ea0(0x30);
    pure3d::Locator_2c1770 *loc = 0;
    if (mem)
        loc = new (mem) pure3d::Locator_2c1770();
    loc->name.FUN_0027b040(f.name);
    loc->position = *(Vec3_2c1770 *)f.pos;

    while (s->FUN_002669f0()) {
        if (s->FUN_00266a30() == 0x14001) {
            s->reader->FUN_002647e0(f.quat, 4, 4, 1);
            loc->rotation = *(Quat_2c1770 *)f.quat;
        }
        s->FUN_00266be0();
    }
    *out = loc;
    *outId = FUN_002672f0(f.name, 0);
}
