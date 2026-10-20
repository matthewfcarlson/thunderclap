// STATUS: equivalent (tools/equiv.py level 3: 1706 inputs, branch coverage 45/46, incomplete)
// FUN_000c1b50 @ 0x000c1b50
// cl-flags: /GS
#include "decls/data/game/global.h"

inline void *operator new(unsigned int, void *p) throw() { return p; }

namespace pure3d { class Texture; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); int pad4; }; } }

struct Pair {
    int a;
    int b;
};

struct Id64 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af50();
};

struct Manager {
    int FUN_000f7240(int a, int b);
    const unsigned short* FUN_000f7220(int id);
};
Manager* __cdecl FUN_000fc1b0();

struct TextEntry {
    char pad[0x24];
    void FUN_000f7930();
    void FUN_000f7960();
    void FUN_000f8500(const char* name, Manager* manager, int flag);
    void FUN_000f79a0(const unsigned short* text, int flag);
};


class FEObject {
public:
    virtual void vfunc_0();
};
FEObject* __cdecl FUN_000fc260(const char* name);

class TextSelector : public FEObject {
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19(TextEntry* entry, int a, int b);
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25(int index);
    char pad04[0x154 - 4];
    int cursor;
    char pad158[0x1d58 - 0x158];
    int count;
    void FUN_000e36c0();
};

class ImageSelector : public FEObject {
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19(void* tex, int row, int col, int id, int flag);
    int FUN_000e4000();
};

class CUnlockable {
public:
    virtual void v0();
};

class CUnlockableGallery : public CUnlockable {
public:
    Id64* FUN_00092340(Id64* out);
    int FUN_00092370();
};

struct ItemTable {
    CUnlockable* FUN_00092ad0(int index);
    Pair* FUN_00092bb0(int index);
    const char* FUN_00092bc0(int index);
    char FUN_00092860(int index);
    char FUN_00092a40(int index);
};

struct Holder {
    void* tex;
};

struct Inventory {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual void* find(content::LoadInventory::DynamicCaster<pure3d::Texture>* caster, unsigned __int64 key);
};


unsigned short* __cdecl FUN_000fb690(unsigned short* dst, const unsigned short* src, int n);
unsigned short* __cdecl FUN_000fb790(unsigned short* dst, const unsigned short* src, int n);

class GalleryScreen;

// The caster's slot doubles as scratch for the image loop: the original keeps `row` in its
// first word and spills img's vptr into the second (across the FUN_00092370 call), and the
// next lookup's caster still carries that word in its pad.
struct Probe {
    union {
        char caster[sizeof(content::LoadInventory::DynamicCaster<pure3d::Texture>)];  // 0x1c
        struct {
            int row;
            void *imgVtbl;
        } t;
    };
    Id64 id;                                                        // 0x24
};

struct Frame {
    union {
        int *dest;      // 0x10
        int j;
    } u10;
    union {
        int cursor;     // 0x14
        int i;
    } u14;
    GalleryScreen *self;                                           // 0x18
    Probe pr;                                                      // 0x1c
    TextEntry entry2;                                              // 0x2c
    TextEntry entry1;                                              // 0x50
    unsigned short buf[0x80];                                      // 0x74
};

class GalleryScreen {
public:
    char pad0[0x4c];
    ItemTable* items;
    char pad50[0x1ba4 - 0x50];
    int list[1];
    void FUN_000c1b50(int kind, int first, int last);
};

void GalleryScreen::FUN_000c1b50(int kind, int first, int last)
{
    Frame f;
    f.self = this;
    f.entry1.FUN_000f7930();
    f.entry1.FUN_000f8500(((char*)&DAT_003f335c), FUN_000fc1b0(), 1);

    if ((kind >= 0x248 && kind <= 0x257) || (kind >= 0x258 && kind <= 0x260)) {
        const char* name = items->FUN_00092bc0(kind);
        if (name != 0) {
            TextSelector* sel = dynamic_cast<TextSelector*>(FUN_000fc260(name));
            if (sel != 0) {
                f.u14.cursor = sel->cursor;
                sel->FUN_000e36c0();
                f.u10.dest = list;
                for (int i = first; i <= last; i++) {
                    if (items->FUN_00092860(i))
                        continue;
                    Pair* p = items->FUN_00092bb0(i);
                    if ((p->a | p->b) == 0)
                        continue;
                    int id = FUN_000fc1b0()->FUN_000f7240(p->a, p->b);
                    if (id == -1)
                        continue;
                    f.entry2.FUN_000f7930();
                    f.entry2.FUN_000f8500(((char*)&DAT_003f335c), FUN_000fc1b0(), 1);
                    FUN_000fb690(f.buf, FUN_000fc1b0()->FUN_000f7220(id), 0x80);
                    if (items->FUN_00092a40(i))
                        FUN_000fb790(f.buf, L"\x0820\x756e", 0x80);
                    f.entry2.FUN_000f79a0(f.buf, 0);
                    sel->vfunc_19(&f.entry2, 0, 0);
                    if (first == 0x258)
                        *f.u10.dest++ = i;
                    f.entry2.FUN_000f7960();
                }
                int last_index = sel->count - 1;
                int idx;
                if (f.u14.cursor >= 0) {
                    if (f.u14.cursor <= last_index)
                        idx = f.u14.cursor;
                    else
                        idx = last_index;
                } else {
                    if (f.u14.cursor <= last_index)
                        idx = 0;
                    else
                        idx = last_index;
                }
                sel->vfunc_25(idx);
                sel->vfunc_3();
            }
        }
    } else {
        f.u10.j = 0;
        for (f.u14.i = first; f.u14.i <= last; f.u14.i++, f.u10.j++) {
            const char* name = f.self->items->FUN_00092bc0(f.u14.i);
            if (name == 0)
                continue;
            ImageSelector* img = dynamic_cast<ImageSelector*>(FUN_000fc260(name));
            if (img == 0)
                continue;
            CUnlockableGallery* gal = dynamic_cast<CUnlockableGallery*>(f.self->items->FUN_00092ad0(f.u14.i));
            if (gal == 0)
                continue;
            Id64* key = gal->FUN_00092340(&f.pr.id);
            Inventory* inv = (*(Inventory**)&DAT_004dd9cc);
            void* tex = inv->find(new (f.pr.caster) content::LoadInventory::DynamicCaster<pure3d::Texture>, *(unsigned __int64*)key);
            f.pr.id.FUN_0027af50();
            if (tex == 0)
                continue;
            if (f.self->items->FUN_00092860(f.u14.i))
                continue;
            int m = f.u10.j % 10;
            f.pr.t.row = m / img->FUN_000e4000();
            int col = m % img->FUN_000e4000();
            f.pr.t.imgVtbl = *(void **)img;
            img->vfunc_19(tex, f.pr.t.row, col, gal->FUN_00092370(), 0);
        }
    }
    f.entry1.FUN_000f7960();
}
