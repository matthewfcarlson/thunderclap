// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000f6af0 @ 0x000f6af0
typedef unsigned __int64 U64;
struct Drawable { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual int slot11(); };
namespace pure3d { struct CompositeDrawable {}; }
namespace content { struct LoadInventory { template<class T> struct DynamicCaster { virtual void slot0(); }; }; }
typedef content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> Caster;
struct Inventory { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Drawable* slot3(Caster*, unsigned, unsigned); };
struct InventoryTable { void* slot0; void* slot1; void* slot2; Drawable* (__fastcall *slot3)(Inventory*, int, Caster*, unsigned, unsigned); };
extern Inventory* DAT_004dd9cc;
extern U64 __cdecl FUN_002672f0(int, int, int);
extern U64 __cdecl FUN_0027b020(int);
struct Result { int value; int unused; unsigned low; unsigned high; };
void __cdecl FUN_000f6af0(int name, int aux, Result* result) {
    Inventory* inventory = DAT_004dd9cc;
    InventoryTable* table = *(InventoryTable**)inventory;
    Caster caster;
    U64 id = FUN_002672f0(name, 0, 0);
    Drawable* drawable = table->slot3(inventory, 0, &caster, (unsigned)id, (unsigned)(id >> 32));
    result->value = drawable->slot11();
    U64 other = FUN_0027b020(aux);
    result->low = (unsigned)other;
    result->high = (unsigned)(other >> 32);
}