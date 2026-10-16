// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000f6bd0 @ 0x000f6bd0
// Look up a drawable in the inventory by name, find the entry named `joint` in its table
// and hand the entry's value to FUN_000f69e0.
#include "decls/address.h"
#include "decls/data/game/global.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }

void __cdecl FUN_000f69e0(int value, int arg);

namespace pure3d { class CompositeDrawable; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }

struct Entry_f6bd0 {
    int pad0;
    int key;                        // 4
    int value;                      // 8
};

struct Table_f6bd0 {
    char pad[0x3c];
    Entry_f6bd0 *begin;                   // 0x3c
    Entry_f6bd0 *end;                     // 0x40

    unsigned char size() const { return (unsigned char)(end - begin); }
    Entry_f6bd0 &at(unsigned char i) const { return begin[i]; }
};

struct Finder_f6bd0 {
    unsigned int FUN_0027b200(int lo, int hi);
};

struct Info_f6bd0 {
    char pad[8];
    Finder_f6bd0 *finder;                 // 8
};

class Loaded_f6bd0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10();
    virtual Info_f6bd0 *GetInfo();        // slot 11
    char pad04[0x44 - 4];
    Table_f6bd0 *table;                   // 0x44
};

class Inventory_f6bd0 {
public:
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual Loaded_f6bd0 *find(void *caster, unsigned __int64 key);   // slot 3
};

void FUN_000f6bd0(const char *name, const char *joint, int arg)
{
    struct Frame {
        int result;
        int caster;
    } fr;
    fr.result = 0;
    new (&fr.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>();
    Inventory_f6bd0 *inv = (*(Inventory_f6bd0**)&DAT_004dd9cc);
    Loaded_f6bd0 *loaded = inv->find(&fr.caster, FUN_002672f0(name, 0, 0));
    loaded->v0();
    Finder_f6bd0 *finder = loaded->GetInfo()->finder;
    unsigned __int64 key = FUN_0027b020(joint);
    unsigned int id = finder->FUN_0027b200((int)key, (int)(key >> 32));
    Table_f6bd0 *t = loaded->table;
    for (int i = 0; i < t->size(); i++) {
        if (t->at(i).key == (int)id) {
            fr.result = t->at(i).value;
            break;
        }
    }
    FUN_000f69e0(fr.result, arg);
    loaded->v1();
}
