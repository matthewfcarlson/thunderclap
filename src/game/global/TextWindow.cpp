// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e3ac0..0x000e3c70 (kind game, layer game, confidence high), dominant class TextWindow
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd5f5c06 {
#define TREE_TU_END }
namespace fn_fd5f5c06 {} using namespace fn_fd5f5c06;
#include "game/global.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif
namespace fn_fd5f5c06 {
struct Node { char pad0[0x40]; unsigned char active; char pad41[3]; void* link; unsigned char enabled; char pad49[3]; void* owner; };
struct Object { char pad0[0x4c]; void* owner; char pad50[0xf8]; void* link; char pad14c[4]; Node* node; void FUN_000e3b70(Node* value); };
class FEControl_e3bb0 {
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
class FEObject_e3bb0 {};
class IValueChangedReceiver_e3bb0 {};
class IValueChangedSender_e3bb0 {};

} // namespace fn_fd5f5c06

// 0x000e3ac0 FUN_000e3ac0 (145 B): matches/0x000e3ac0.cpp
// sym: ?FUN_000e3ac0@Thing_e3ac0@owners@@QAEXPAU12@@Z
void owners::Thing_e3ac0::FUN_000e3ac0(owners::Thing_e3ac0* other) {
    Init(other);
    memcpy((char*)this + 0x118, (char*)other + 0x118, 0x28);
    *(unsigned int*)((char*)this + 0x15c) = *(unsigned int*)((char*)other + 0x15c);
    *(unsigned int*)((char*)this + 0x160) = *(unsigned int*)((char*)other + 0x160);
    memcpy((char*)this + 0x164, (char*)other + 0x164, 0x800);
    *(unsigned int*)((char*)this + 0x964) = *(unsigned int*)((char*)other + 0x964);
    *(unsigned int*)((char*)this + 0x96c) = *(unsigned int*)((char*)other + 0x96c);
    *(unsigned int*)((char*)this + 0x970) = *(unsigned int*)((char*)other + 0x970);
    *(unsigned int*)((char*)this + 0x974) = *(unsigned int*)((char*)other + 0x974);
    *(unsigned int*)((char*)this + 0x97c) = *(unsigned int*)((char*)other + 0x97c);
}

namespace fn_fd5f5c06 {

// 0x000e3b70 FUN_000e3b70 (58 B): equivalent/0x000e3b70.cpp
// sym: ?FUN_000e3b70@Object@fn_fd5f5c06@@QAEXPAUNode@2@@Z @e1f3a71d9e03 @w5a56563d1916
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000e3b70 @ 0x000e3b70
void Object::FUN_000e3b70(Node* value) { node = value; if (value) { value->active = 1; node->enabled = 1; node->link = link; node->owner = owner; } }

} // namespace fn_fd5f5c06

// 0x000e3bb0 TextWindow::vfunc_10 (22 B): matches/0x000e3bb0.cpp
// sym: ?vfunc_10@TextWindow@@UAEDHH@Z
// Same code shape as 0x000e3e20 (propagated; names are from that function)
char TextWindow::vfunc_10(int x, int y) {
    if (x)
        return x == 4;
    return 1;
}


// 0x000e3bd0 TextWindow::vfunc_11 (5 B): matches/0x000e3bd0.cpp
// sym: ?vfunc_11@TextWindow@@UAE_NHH@Z
// Same code shape as 0x000d7a40 (propagated; names are from that function)
bool TextWindow::vfunc_11(int , int ) {
    return false;
}


// 0x000e3be0 TextWindow::vfunc_12 (75 B): equivalent/0x000e3be0.cpp [wrapped: conflict: TextWindow]
// sym: ?vfunc_12@TextWindow@fn_000e3be0@@QAEIII@Z @31d14c29e705 @wce4ecd37f606
namespace fn_000e3be0 {
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// TextWindow::vfunc_12 @ 0x000e3be0
struct TextWindow {
    char pad[0x964];
    unsigned int limit;
    char pad2[4];
    unsigned int position;
    unsigned int end;
    unsigned int vfunc_12(unsigned int direction, unsigned int unused);
};
unsigned int TextWindow::vfunc_12(unsigned int direction, unsigned int unused)
{
    if (direction == 0) {
        unsigned int value = position;
        if (value != 0) {
            value--;
            position = value;
            return (value & 0xffffff00u) | 1;
        }
        return 0;
    }
    if (direction == 4) {
        unsigned int value = limit - 1;
        if (end != value) {
            value = position + 1;
            position = value;
            return (value & 0xffffff00u) | 1;
        }
        return value & 0xffffff00u;
    }
    return direction & 0xffffff00u;
}
} // namespace fn_000e3be0


// 0x000e3c30 TextWindow::vfunc_13 (28 B): matches/0x000e3c30.cpp
// sym: ?vfunc_13@TextWindow@@UAEXH@Z
void TextWindow::vfunc_13(int ) {
    int x = *(int*)((char*)this + 0x14c);
    *(int*)((char*)&this->f_148) = x;
    hulk_intptr p = *(int*)((char*)&this->f_150);
    if (p)
        *(int*)((char*)p + 0x44) = x;
}


// 0x000e3c50 TextWindow::vfunc_14 (25 B): matches/0x000e3c50.cpp
// sym: ?vfunc_14@TextWindow@@UAEXH@Z
void TextWindow::vfunc_14(int ) {
    int eax = this->f_44;
    this->f_148 = eax;
    if ((*(TextWindow * *)&this->f_150))
        (*(TextWindow * *)&this->f_150)->f_44 = eax;
}

