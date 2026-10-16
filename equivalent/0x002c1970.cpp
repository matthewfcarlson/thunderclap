// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// pure3d::CameraLoader::vfunc_5 @ 0x002c1970
#include "gen/pure3d.h"

unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);
void *__cdecl FUN_00263ea0(unsigned int size);
inline void *operator new(unsigned int, void *p) throw() { return p; }

struct Name_2c1970 {
    char data[8];
    void FUN_0027b040(const char *s);
};

struct Vec3_2c1970 { float x, y, z; };

namespace pure3d {
class __declspec(novtable) Camera_2c1970 {
public:
    virtual void c0();
    char pad4[4];
    Name_2c1970 name;
    char pad10[0xf8 - 0x10];
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void setClip(float a, float b);
    virtual void c6();
    virtual void setFov(float a);
    virtual void c8();
    virtual void setAspect(float a);
    Camera_2c1970 *FUN_002939a0();
    void FUN_00293a90(Vec3_2c1970 *v);
    void FUN_00293ac0(Vec3_2c1970 *v);
    void FUN_00293af0(Vec3_2c1970 *v);
};
}

struct Reader_2c1970 {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream_2c1970 {
    char pad0[0x284];
    Reader_2c1970 *reader;
};

struct Frame_2c1970 {
    char pad0[8];
    char pad8[3];
    unsigned char len;       // 0x0b
    float fov;               // 0x0c
    float aspect;            // 0x10
    int version;             // 0x14
    float nearClip;          // 0x18
    float farClip;           // 0x1c
    Vec3_2c1970 position;           // 0x20
    Vec3_2c1970 target;             // 0x2c
    Vec3_2c1970 up;                 // 0x38
    char name[0x100];        // 0x44
};

void pure3d::CameraLoader::vfunc_5(void* __p0, void* __p1, void* __p2, int __p3) { pure3d::Camera_2c1970 ** out = (pure3d::Camera_2c1970 **)__p0; unsigned long long * outId = (unsigned long long *)__p1; Stream_2c1970 * s = (Stream_2c1970 *)__p2; void * ctx = (void *)__p3;

    Frame_2c1970 f;
    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    s->reader->FUN_002647e0(f.name, f.len, 1, 1);
    f.name[f.len] = 0;

    void *mem = FUN_00263ea0(0xf8);
    pure3d::Camera_2c1970 *cam = 0;
    if (mem)
        cam = static_cast<pure3d::Camera_2c1970 *>(mem)->FUN_002939a0();
    cam->name.FUN_0027b040(f.name);

    s->reader->FUN_002647e0(&f.version, 1, 4, 1);
    s->reader->FUN_002647e0(&f.nearClip, 1, 4, 1);
    s->reader->FUN_002647e0(&f.fov, 1, 4, 1);
    s->reader->FUN_002647e0(&f.aspect, 1, 4, 1);
    s->reader->FUN_002647e0(&f.farClip, 1, 4, 1);
    if (f.version <= 2)
        f.fov = 1.0f;
    s->reader->FUN_002647e0(&f.position, 3, 4, 1);
    s->reader->FUN_002647e0(&f.up, 3, 4, 1);
    s->reader->FUN_002647e0(&f.target, 3, 4, 1);

    cam->setClip(f.nearClip, f.fov);
    cam->setFov(f.aspect);
    cam->setAspect(f.farClip);
    cam->FUN_00293af0(&f.position);
    cam->FUN_00293a90(&f.up);
    cam->FUN_00293ac0(&f.target);
    *out = cam;
    *outId = FUN_002672f0(f.name, 0);
}
