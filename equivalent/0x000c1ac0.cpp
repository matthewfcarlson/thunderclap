// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 4/4)
// FUN_000c1ac0 @ 0x000c1ac0
#include "decls/data/game/global.h"

namespace content { namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase { public: virtual void cast(void* p); };
template <class T> class DynamicCaster : public DynamicCasterBase { public: virtual void cast(void* p); };
} }
namespace pure3d { class CompositeDrawable; }
extern char DAT_0049dba4[];
extern char DAT_0049f48c[];
void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);
void* __cdecl FUN_000fc260(const char* name);
int __cdecl FUN_000fc1b0();
struct Id_c1ac0 { unsigned lo, hi; };
Id_c1ac0 __cdecl FUN_0027b020(const char* s);
struct Label_c1ac0 { void FUN_000f8500(const char* text, int a, int b); };
struct Element_c1ac0 { char pad[0x18]; Label_c1ac0 label; };
class Drawable {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(float t, int flag); virtual void v7(); virtual void v8();
    virtual void v9();
};
class Inventory_c1ac0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual Drawable* Find(content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>* caster, unsigned lo, unsigned hi);
};
void ShowDecryptBar() {
    Element_c1ac0* e = (Element_c1ac0*)FUN_00344e74(FUN_000fc260("dycrypting_sequence_text"), 0, DAT_0049dba4, DAT_0049f48c, 0);
    if (e)
        e->label.FUN_000f8500("", FUN_000fc1b0(), 1);
    Inventory_c1ac0* inv = (*(Inventory_c1ac0**)&DAT_004dd9cc);
    content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
    Id_c1ac0 id = FUN_0027b020("decryptingProgressBar");
    Drawable* d = inv->Find(&caster, id.lo, id.hi);
    if (d) {
        d->v9();
        d->v6(10.0f, 0);
    }
}
