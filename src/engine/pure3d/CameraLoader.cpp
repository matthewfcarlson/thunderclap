// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c1970..0x002c1c00 (kind game, layer engine, confidence medium), dominant class pure3d::CameraLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f4e0afb8 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f4e0afb8 {} using namespace fn_f4e0afb8;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);
namespace fn_f4e0afb8 {
void *__cdecl FUN_00263ea0(unsigned int size);
} // namespace fn_f4e0afb8
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_f4e0afb8 {
struct Name_2c1970 {
    char data[8];
};
struct Vec3_2c1970 { float x, y, z; };
} // namespace fn_f4e0afb8
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
namespace fn_f4e0afb8 {
struct Reader_2c1970 {
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
extern "C" char DAT_0042ebe8[];
class CameraLoader {
  public:
    void* vf;
    int a;
    int b;
    int c;
    int d;
    CameraLoader();
};

} // namespace fn_f4e0afb8

// 0x002c1970 pure3d::CameraLoader::vfunc_5 (436 B): equivalent/0x002c1970.cpp
// sym: ?vfunc_5@CameraLoader@pure3d@@UAEXPAX00H@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// pure3d::CameraLoader::vfunc_5 @ 0x002c1970
void pure3d::CameraLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr __p3) { pure3d::Camera_2c1970 ** out = (pure3d::Camera_2c1970 **)__p0; unsigned long long * outId = (unsigned long long *)__p1; Stream_2c1970 * s = (Stream_2c1970 *)__p2; void * ctx = (void *)__p3;

    Frame_2c1970 f;
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(f.name), (hulk_intptr)(f.len), 1, (hulk_intptr)1);
    f.name[f.len] = 0;

    void *mem = FUN_00263ea0(0xf8);
    pure3d::Camera_2c1970 *cam = 0;
    if (mem)
        cam = static_cast<pure3d::Camera_2c1970 *>(mem)->FUN_002939a0();
    ((owners::Target_27b040 *)&(cam->name))->FUN_0027b040((hulk_uintptr)(f.name));

    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.version), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.nearClip), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.fov), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.aspect), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.farClip), (hulk_intptr)1, 4, (hulk_intptr)1);
    if (f.version <= 2)
        f.fov = 1.0f;
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.position), (hulk_intptr)3, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.up), (hulk_intptr)3, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.target), (hulk_intptr)3, 4, (hulk_intptr)1);

    cam->setClip(f.nearClip, f.fov);
    cam->setFov(f.aspect);
    cam->setAspect(f.farClip);
    cam->FUN_00293af0(&f.position);
    cam->FUN_00293a90(&f.up);
    cam->FUN_00293ac0(&f.target);
    *out = cam;
    *outId = FUN_002672f0(f.name, 0);
}

namespace fn_f4e0afb8 {

// 0x002c1b30 FUN_002c1b30 (27 B): matches/0x002c1b30.cpp
// sym: ??0CameraLoader@fn_f4e0afb8@@QAE@XZ
CameraLoader::CameraLoader() {
    a = 0;
    b = 0x2200;
    c = 0;
    d = 0;
    vf = (void*)((hulk_intptr)DAT_0042ebe8);
}

} // namespace fn_f4e0afb8

// 0x002c1b50 pure3d::CameraLoader::vfunc_2 (31 B): matches/0x002c1b50.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002c1b50@@UAEPAV123@E@Z
namespace fn_002c1b50 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_2c1b50 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_2c1b50 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002c1b50

