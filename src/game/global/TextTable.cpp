// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e3c70..0x000e3f20 (kind game, layer game, confidence high), dominant class TextTable
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8a05cfd {
#define TREE_TU_END }
namespace fn_f8a05cfd {} using namespace fn_f8a05cfd;
#include "game/global.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif
namespace fn_f8a05cfd {
struct Sub_e3d70 {
    void fn_000f83c0(int);
};
class Obj_e3d70 {
  public:
    char pad0[0xa4];
    int value;
    char pad1[0x495c - 0xa8];
    int width;
    int height;
    char tail[1];
    void update(int x, int y, int z);
};
struct Item {
    char a[0x40];
    bool b;
    char c[3];
    void* p;
    bool d;
    char e[3];
    void* q;
};
class Obj {
    char a[0x4c];
    void* volatile q;
    char b[0xf8];
    void* volatile p;
    char c[4];
    Item* volatile item;

  public:
    void Set(Item* x);
};
class FEControl_e3e20 {
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
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
};
class FEObject_e3e20 {};
class IValueChangedReceiver_e3e20 {};
class IValueChangedSender_e3e20 {};

} // namespace fn_f8a05cfd

// 0x000e3c70 FUN_000e3c70 (186 B): matches/0x000e3c70.cpp
// sym: ?FUN_000e3c70@Obj_e3c70@owners@@QAEXPAU12@@Z
void owners::Obj_e3c70::FUN_000e3c70(owners::Obj_e3c70* p) {
    Base(p);
    memcpy((char*)this + 0x118, (char*)p + 0x118, 40);
    vals[0] = p->vals[0];
    vals[1] = p->vals[1];
    vals[2] = p->vals[2];
    vals[3] = p->vals[3];
    vals[5] = p->vals[5];
    vals[6] = p->vals[6];
    vals[7] = p->vals[7];
    vals[8] = p->vals[8];
    vals[9] = p->vals[9];
    vals[10] = p->vals[10];
    vals[11] = p->vals[11];
    vals[12] = p->vals[12];
}

namespace fn_f8a05cfd {

// 0x000e3d70 FUN_000e3d70 (66 B): matches/0x000e3d70.cpp
// sym: ?update@Obj_e3d70@fn_f8a05cfd@@QAEXHHH@Z
void Obj_e3d70::update(int x, int y, int z) {
    if (x < width && y < height) {
        Sub_e3d70* p = (Sub_e3d70*)((char*)this + 0x15c + (y + x * 8) * 0x24);
        p->fn_000f83c0(z);
        *(int*)p = value;
    }
}


// 0x000e3de0 FUN_000e3de0 (58 B): matches/0x000e3de0.cpp
// sym: ?Set@Obj@fn_f8a05cfd@@QAEXPAUItem@2@@Z
void Obj::Set(Item* x) {
    item = x;
    if (x) {
        x->b = true;
        item->d = true;
        void* v = p;
        item->p = v;
        void* w = q;
        item->q = w;
    }
}

} // namespace fn_f8a05cfd

// 0x000e3e20 TextTable::vfunc_10 (22 B): matches/0x000e3e20.cpp
// sym: ?vfunc_10@TextTable@@UAEDHH@Z
char TextTable::vfunc_10(int x, int y) {
    if (x)
        return x == 4;
    return 1;
}


// 0x000e3e40 TextTable::vfunc_11 (5 B): matches/0x000e3e40.cpp
// sym: ?vfunc_11@TextTable@@UAE_NHH@Z
// Same code shape as 0x000d7a40 (propagated; names are from that function)
bool TextTable::vfunc_11(int , int ) {
    return false;
}


// 0x000e3e50 TextTable::vfunc_12 (88 B): equivalent/0x000e3e50.cpp [wrapped: conflict: TextTable]
// sym: ?vfunc_12@TextTable@fn_000e3e50@@UAEIII@Z @d92160f1e2c3 @w97fc485cb689
namespace fn_000e3e50 {
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 8/8)
// TextTable::vfunc_12 @ 0x000e3e50
class TextTable {
public:
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
 virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
 virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
 virtual unsigned int vfunc_12(unsigned int action, unsigned int unused);
 virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
 virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18();
 char padding[0x495c - 4];
 unsigned int total;
 char gap[4];
 unsigned int position;
 unsigned int selected;
};
unsigned int TextTable::vfunc_12(unsigned int action, unsigned int unused)
{
 if (action == 4) {
  unsigned int oldSelected = selected;
  if (oldSelected == total - 1) return oldSelected & 0xffffff00;
  unsigned int newPosition = position + 1;
  selected = oldSelected + 1;
  position = newPosition;
  return (oldSelected + 1 & 0xffffff00) | 1;
 }
 if (action == 0) {
  unsigned int oldPosition = position;
  if (oldPosition == 0) return 0;
  position = oldPosition - 1;
  --selected;
  return ((oldPosition - 1) & 0xffffff00) | 1;
 }
 return action & 0xffffff00;
}
} // namespace fn_000e3e50


// 0x000e3eb0 TextTable::vfunc_13 (28 B): matches/0x000e3eb0.cpp
// sym: ?vfunc_13@TextTable@@UAEXH@Z
// Same code shape as 0x000e3c30 (propagated; names are from that function)
void TextTable::vfunc_13(int ) {
    int x = *(int*)((char*)this + 0x14c);
    *(int*)((char*)&this->f_148) = x;
    hulk_intptr p = *(int*)((char*)&this->f_150);
    if (p)
        *(int*)((char*)p + 0x44) = x;
}


// 0x000e3ed0 TextTable::vfunc_14 (71 B): matches/0x000e3ed0.cpp
// sym: ?vfunc_14@TextTable@@UAEXH@Z
void TextTable::vfunc_14(int ) {
    int v = this->f_44;
    TextTable* p = (*(TextTable * *)&this->f_150);
    this->f_148 = v;
    if (p)
        p->f_44 = v;
    TextTable* a = (*(TextTable * *)&this->f_154);
    if (a && (*(TextTable * *)&this->f_158)) {
        a->f_118 = 0;
        (*(TextTable * *)&this->f_158)->f_118 = 0;
    }
}

