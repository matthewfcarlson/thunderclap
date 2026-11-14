// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000d7890..0x000d7af0 (kind game, layer game, confidence high), dominant class FEBackground
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb027fad {
#define TREE_TU_END }
namespace fn_fb027fad {} using namespace fn_fb027fad;
namespace fn_fb027fad { extern "C" char DAT_0040b494[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fb027fad {
class Handler_d7890;
struct Item_d7890 {
    virtual void v0();
    virtual void v1();
};
struct Cursor_d7890 {
    bool FUN_000f9ef0();
    void FUN_000f9f30();
    Item_d7890* FUN_000fb110();
    void FUN_000fa0a0();
    void FUN_000f9fb0();
};
struct Dispatcher_d7890 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33();
    virtual bool v34(Cursor_d7890* c, Item_d7890* it, int zero);
    virtual bool v35(Cursor_d7890* c, int flag, Handler_d7890* h, Item_d7890* it);
    virtual bool v36(Cursor_d7890* c, int flag, Handler_d7890* h, Item_d7890* it);
};
class Handler_d7890 {
public:
    bool FUN_000d7890(Cursor_d7890* c, Dispatcher_d7890* d, int flag);
};
struct Vec3_d7950 {
    float x, y, z;
};
class Renderer_d7950 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v15(int a);
    virtual void v16(int a);
};
class Overlay_d7950 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int a, int b);
};
struct Display_d7950 {
    Renderer_d7950* renderer;
    void FUN_00293d00(Vec3_d7950* v);
    void FUN_00293bf0(float angle);
};
struct FEBackground_nv_d7950 {
    Vec3_d7950* FUN_000e2800(Vec3_d7950* out);
};
extern void* hulk_at_0040b494[];
class Ref_d79c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class FEControl_d79c0 {
  public:
    void* vptr;
    void Fin_000e92b0();
};
class FEBackground_d79c0 : public FEControl_d79c0 {
  public:
    char pad[0x14c];
    Ref_d79c0* m150;
    ~FEBackground_d79c0();
};
extern void* g_vftable_d7ab0[];
class Ref_d7ab0 {
  public:
    virtual void F0();
    virtual void Release();
};
class FEControl_d7ab0 {
  public:
    void* vptr;
    void Fin_000e92b0();
};
class FEBackground_d7ab0 : public FEControl_d7ab0 {
  public:
    char pad[332];
    Ref_d7ab0* m;
    FEBackground_d7ab0* f2(unsigned char flags);
};


// 0x000d7890 FUN_000d7890 (152 B): matches/0x000d7890.cpp
// sym: ?FUN_000d7890@Handler_d7890@fn_fb027fad@@QAE_NPAUCursor_d7890@2@PAUDispatcher_d7890@2@H@Z
// FUN_000d7890 @ 0x000d7890
bool Handler_d7890::FUN_000d7890(Cursor_d7890* c, Dispatcher_d7890* d, int flag)
{
    if (c->FUN_000f9ef0()) {
        c->FUN_000f9f30();
        while (((owners::ThisWrap_000f9e50 *)c)->FUN_000f9e50()) {
            Item_d7890* it = c->FUN_000fb110();
            it->v1();
            if (d->v35(c, flag, this, it))
                continue;
            if (d->v36(c, flag, this, it))
                continue;
            if (d->v34(c, it, 0))
                continue;
            c->FUN_000fa0a0();
            break;
        }
        c->FUN_000f9fb0();
    }
    return true;
}

// 0x000d7930 FEBackground::vfunc_3 (5 B): not yet verified

// 0x000d7940 FEBackground::vfunc_4 (1 B): matches/0x000d7940.cpp
// sym: ?FUN_000d7940@fn_fb027fad@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000d7940() {}

} // namespace fn_fb027fad

// 0x000d7950 FEBackground::vfunc_5 (104 B): matches/0x000d7950.cpp
// sym: ?vfunc_5@FEBackground@@UAEXXZ
// FEBackground::vfunc_5 @ 0x000d7950
void FEBackground::vfunc_5() {
    if ((*(Overlay_d7950 * *)&this->f_150) == 0)
        return;
    Vec3_d7950 pos;
    (*(Display_d7950**)&DAT_0052c2ac)->renderer->v15(0);
    (*(Display_d7950**)&DAT_0052c2ac)->FUN_00293d00(((FEBackground_nv_d7950*)this)->FUN_000e2800(&pos));
    (*(Display_d7950**)&DAT_0052c2ac)->FUN_00293bf0(-1.5707964f);
    (*(Overlay_d7950 * *)&this->f_150)->v8(0, 0);
    (*(Display_d7950**)&DAT_0052c2ac)->renderer->v16(0);
}

namespace fn_fb027fad {

// 0x000d79c0 FUN_000d79c0 (42 B): matches/0x000d79c0.cpp
// sym: ??1FEBackground_d79c0@fn_fb027fad@@QAE@XZ
FEBackground_d79c0::~FEBackground_d79c0() {
    vptr = hulk_at_0040b494;
    _ReadWriteBarrier();
    if (m150) {
        m150->Release();
        m150 = 0;
    }
    Fin_000e92b0();
}

} // namespace fn_fb027fad

// 0x000d79f0 IValueChangedReceiver::vfunc_1 (3 B): matches/0x000d79f0.cpp
// sym: ?vfunc_1@IValueChangedReceiver@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void IValueChangedReceiver::vfunc_1(int a) {
    (void)a;
}


// 0x000d7a00 FEObject::vfunc_6 (3 B): matches/0x000d7a00.cpp
// sym: ?vfunc_6@FEObject@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void FEObject::vfunc_6(hulk_intptr a) {
    (void)a;
}


// 0x000d7a10 FEObject::vfunc_7 (3 B): matches/0x000d7a10.cpp
// sym: ?vfunc_7@FEObject@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void FEObject::vfunc_7(int a) {
    (void)a;
}


// 0x000d7a20 FEObject::vfunc_8 (7 B): matches/0x000d7a20.cpp
// sym: ?vfunc_8@FEObject@@UAEMXZ
hulk_freg FEObject::vfunc_8() {
    return *(float*)((char*)&this->f_9c);
}


// 0x000d7a30 FEObject::vfunc_9 (7 B): matches/0x000d7a30.cpp [wrapped: conflict: FEObject; IValueChangedReceiver]
// sym: ?vfunc_9@FEObject@fn_000d7a30@@UAEMXZ
namespace fn_000d7a30 {
class IValueChangedReceiver_d7a30 {
  public:
    virtual void f0();
};
class IValueChangedReceiver {
  public:
    virtual void f1();
};
class FEObject : public IValueChangedReceiver_d7a30, public IValueChangedReceiver {
  public:
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual float vfunc_9();
    char pad[0xA0 - 8];
    float value;
};
float FEObject::vfunc_9() {
    return value;
}
} // namespace fn_000d7a30


// 0x000d7a40 FEControl::vfunc_10 (5 B): matches/0x000d7a40.cpp
// sym: ?vfunc_10@FEControl@@UAEDHH@Z
char FEControl::vfunc_10(int , int ) {
    return (char)(false);
}


// 0x000d7a50 FEControl::vfunc_11 (5 B): matches/0x000d7a50.cpp
// sym: ?vfunc_11@FEControl@@UAE_NHH@Z
// Same code shape as 0x000d7a40 (propagated; names are from that function)
bool FEControl::vfunc_11(int , int ) {
    return false;
}


// 0x000d7a60 FEControl::vfunc_12 (5 B): matches/0x000d7a60.cpp
// sym: ?vfunc_12@FEControl@@UAE_NHH@Z
// Same code shape as 0x000d7a40 (propagated; names are from that function)
bool FEControl::vfunc_12(int , int ) {
    return false;
}


// 0x000d7a70 FEControl::vfunc_13 (3 B): matches/0x000d7a70.cpp
// sym: ?vfunc_13@FEControl@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void FEControl::vfunc_13(int a) {
    (void)a;
}


// 0x000d7a80 FEControl::vfunc_14 (3 B): matches/0x000d7a80.cpp
// sym: ?vfunc_14@FEControl@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void FEControl::vfunc_14(int a) {
    (void)a;
}

namespace fn_fb027fad {

// 0x000d7a90 FEControl::vfunc_15 (1 B): matches/0x000d7a90.cpp
// sym: ?FUN_000d7a90@fn_fb027fad@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000d7a90() {}


// 0x000d7aa0 FEControl::vfunc_16 (1 B): matches/0x000d7aa0.cpp
// sym: ?FUN_000d7aa0@fn_fb027fad@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000d7aa0() {}


// 0x000d7ab0 FEBackground::vfunc_2 (63 B): matches/0x000d7ab0.cpp
// sym: ?f2@FEBackground_d7ab0@fn_fb027fad@@QAEPAV12@E@Z
FEBackground_d7ab0* FEBackground_d7ab0::f2(unsigned char flags) {
    vptr = ((void**)DAT_0040b494);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_000e92b0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_fb027fad
