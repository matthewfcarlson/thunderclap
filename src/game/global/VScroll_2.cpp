// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e8c70..0x000e9030 (kind game, layer game, confidence high), dominant class VScroll
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_ff353e98 {
#define TREE_TU_END }
namespace fn_ff353e98 {} using namespace fn_ff353e98;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ff353e98 {
class Worker_e8cb0 {
  public:
    void run(int, int, int);
};
class FELayout_e8cb0 {
    char pad[0x44];
};
class Child_e8fc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13(int);
};
class FELayout_e8fc0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
};
struct VScroll_nv_e8fc0 {
    void helper(int, int);
};
class FELayout_e9010 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};
class Obj_e9010 {
  public:
    void run(int, int, int);
};

} // namespace fn_ff353e98

// 0x000e8c70 FEDoBackScreen::vfunc_0 (31 B): matches/0x000e8c70.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_000e8c70@@UAEPAV123@E@Z
namespace fn_000e8c70 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class FEDoAction_e8c70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public FEDoAction_e8c70 {
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
} // namespace fn_000e8c70


// 0x000e8c90 SingleLayout::vfunc_21 (31 B): matches/0x000e8c90.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_000e8c90@@UAEPAV123@E@Z
namespace fn_000e8c90 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class FELayout_e8c90 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public FELayout_e8c90 {
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
} // namespace fn_000e8c90


// 0x000e8cb0 SingleLayout::vfunc_10 (24 B): matches/0x000e8cb0.cpp
// sym: ?vfunc_10@SingleLayout@@UAEXH@Z
void SingleLayout::vfunc_10(int param) {
    Worker_e8cb0* p = (*(Worker_e8cb0 * *)&this->f_44);
    if (p)
        p->run(param, -1, -1);
}


// 0x000e8cd0 VScroll::vfunc_21 (31 B): matches/0x000e8cd0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_000e8cd0@@UAEPAV123@E@Z
namespace fn_000e8cd0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class FELayout_e8cd0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public FELayout_e8cd0 {
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
} // namespace fn_000e8cd0


// 0x000e8cf0 FUN_000e8cf0 (389 B): equivalent/0x000e8cf0.cpp [wrapped: conflict: FEControl; FEObject; VScroll]
// sym: ?FUN_000e8cf0@VScroll@fn_000e8cf0@@QAEXHH@Z
namespace fn_000e8cf0 {
// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 31/34, incomplete)
// FUN_000e8cf0 @ 0x000e8cf0
class FEObject {
public:
    virtual void o0();
};

class Widget_e8cf0 {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual bool w4(int a, int b, int c, int d);
};

class FEControl : public FEObject {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void vfn13(int mode);
    virtual void vfn14(int mode);
    char pad0[0xa8 - 4];
    int value;
    char pad1[0x118 - 0xac];
    Widget_e8cf0 *widgets[10];
};

class Engine_e8cf0 {
public:
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void e6();
    virtual void e7();
    virtual void e8();
    virtual void e9();
    virtual void e10();
    virtual void e11();
    virtual void e12();
    virtual void e13();
    virtual void e14();
    virtual void e15();
    virtual void e16();
    virtual void e17();
    virtual void e18();
    virtual void e19();
    virtual void e20();
    virtual void e21();
    virtual void e22();
    virtual void e23();
    virtual void e24();
    virtual void e25();
    virtual void e26();
    virtual void e27();
    virtual void e28();
    virtual void e29();
    virtual void e30();
    virtual void e31();
    virtual void e32();
    virtual void e33();
    virtual void e34();
    virtual void e35();
    virtual void e36();
    virtual void e37();
    virtual void e38();
    virtual void e39();
    virtual void e40();
    virtual void e41();
    virtual void e42();
    virtual void e43();
    virtual void e44();
    virtual void e45();
    virtual void e46();
    virtual void e47();
    virtual void vfn48(int mode);
};

class Manager_e8cf0 {
public:
    virtual void m0();
    Engine_e8cf0 *engine;
};

struct Item_e8cf0 {
    FEObject *obj;
    int pad[2];
    char flag;
    char pad2[3];
};

class VScroll {
public:
    virtual void v0();
    char pad04[4];
    Manager_e8cf0 *manager;
    char padC[0x40 - 0xc];
    Item_e8cf0 items[32];
    char pad240[4];
    FEControl *selected;    // 0x244
    int index;
    int cursor;
    char pad250[0x268 - 0x250];
    int cursorMax;
    void FUN_000e23f0();
    void FUN_000e8cf0(int index, int mode);
};

void VScroll::FUN_000e8cf0(int idx, int mode)
{
    bool forward = (mode == 2);
    int i;
    FEControl *cur = selected;
    if (cur != 0) {
        for (i = 0; i < 10; i++) {
            Widget_e8cf0 *w = cur->widgets[i];
            if (w == 0) break;
            if (w->w4(3, cur->value, -1, -1))
                cur->widgets[i]->w1();
        }
        selected->vfn14(forward ? 2 : 1);
    }
    index = idx;
    FEControl *cast = dynamic_cast<FEControl *>(items[idx].obj);
    Manager_e8cf0 *mgr = manager;
    selected = cast;
    mgr->engine->vfn48(2);
    if (items[index].flag == 0) {
        for (int n = 1000000; n > 0; n--) {
            if (forward)
                cursor++;
            else
                cursor--;
            if (cursor < 0) {
                cursor += 2;
                forward = true;
            }
            if (cursor > cursorMax)
                cursor = 0;
            FUN_000e23f0();
            if (items[index].flag != 0)
                break;
        }
    }
    if (selected != 0) {
        selected->vfn13(forward ? 2 : 1);
        FEControl *s = selected;
        for (i = 0; i < 10; i++) {
            Widget_e8cf0 *w = s->widgets[i];
            if (w == 0) break;
            if (w->w4(2, s->value, -1, -1))
                s->widgets[i]->w1();
        }
    }
}
} // namespace fn_000e8cf0


// 0x000e8e80 VScroll::vfunc_7 (306 B): equivalent/0x000e8e80.cpp [wrapped: conflict: FEControl; FELayout; FEObject; VScroll]
// sym: ?vfunc_7@VScroll@fn_000e8e80@@UAEDHH@Z
namespace fn_000e8e80 {
// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 29/34, incomplete)
// VScroll::vfunc_7 @ 0x000e8e80
class FEObject {
public:
    virtual void o0();
};

class FEControl : public FEObject {
public:
    virtual void c0();
};

class Child_e8e80 {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual char vfunc_12(int a, int b);
};

class Manager_e8e80 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual int vfunc_17();
};

struct Item_e8e80 {
    FEObject *obj;
    int pad[3];
};

class FELayout {
public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
};

class VScroll : public FELayout {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v5();
    virtual void v6();
    virtual char vfunc_7(int event, int arg);
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
    virtual void v21();
    char pad04[4];
    Manager_e8e80 *manager;
    char padC[0x40 - 0xc];
    Item_e8e80 items[32];
    char pad240[4];
    Child_e8e80 *child;
    int index;
    char pad24c[0x268 - 0x24c];
    int fallbackIndex;
    void FUN_000e8cf0(int index, int mode);
};

char VScroll::vfunc_7(int event, int arg)
{
    if (child != 0) {
        if (child->vfunc_12(event, arg))
            return 1;
    }

    if (event == 0) {
        int i = index - 1;
        while (i >= 0) {
            FEObject *obj = items[i].obj;
            if (obj != 0 && dynamic_cast<FEControl *>(obj) != 0) {
                FUN_000e8cf0(i, 1);
                break;
            }
            i--;
        }
        if (i != -1)
            return 1;
        if (manager->vfunc_17() == 1)
            FUN_000e8cf0(0, 1);
        return 0;
    }

    if (event == 4) {
        int i = index + 1;
        while (i < 32) {
            FEObject *obj = items[i].obj;
            if (obj == 0)
                break;
            if (dynamic_cast<FEControl *>(obj) != 0) {
                FUN_000e8cf0(i, 2);
                break;
            }
            i++;
        }
        if (i != 32) {
            if (items[i].obj != 0)
                return 1;
        }
        if (manager->vfunc_17() == 1) {
            FUN_000e8cf0(fallbackIndex, 2);
            return 0;
        }
    }
    return 0;
}
} // namespace fn_000e8e80


// 0x000e8fc0 VScroll::vfunc_8 (79 B): matches/0x000e8fc0.cpp
// sym: ?vfunc_8@VScroll@@UAEXH@Z
void VScroll::vfunc_8(int p) {
    switch (p) {
    case 1: {
        int x = this->f_268;
        if (this->f_248 != x)
            ((VScroll_nv_e8fc0*)this)->helper(x, 1);
        break;
    }
    case 2:
        if (this->f_248 != 0)
            ((VScroll_nv_e8fc0*)this)->helper(0, 2);
        break;
    }
    if ((*(Child_e8fc0 * *)&this->f_244))
        (*(Child_e8fc0 * *)&this->f_244)->f13(p);
}


// 0x000e9010 VScroll::vfunc_10 (32 B): matches/0x000e9010.cpp
// sym: ?vfunc_10@VScroll@@UAEXH@Z
void VScroll::vfunc_10(int arg) {
    Obj_e9010* p = (*(Obj_e9010 * *)&this->f_244);
    if (p && arg == 0)
        p->run(0, -1, -1);
}

