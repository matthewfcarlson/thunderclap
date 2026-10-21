// STATUS: equivalent (tools/equiv.py level 3: 20136 inputs, branch coverage 33/34, incomplete)
// FUN_000d3f10 @ 0x000d3f10
// cl-flags: /GS
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
namespace pure3d { class DrawableHierarchy; }
namespace content {
class LoadInventory {
  public:
    template <class T> class DynamicCaster {
      public:
        virtual T* Cast(void* p);
    };
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void* Find(const DynamicCaster<pure3d::DrawableHierarchy>& c, __int64 uid);
};
}
struct Lookup_d3f10 {
    int idx;
    int kind;
};
struct Provider_d3f10 {
    hulk_intptr FUN_000ad7b0(int a, int b, int c);
    hulk_intptr FUN_000ad580(int a, int b, int c);
};
extern "C" int strcmp(const char*, const char*);
extern "C" char* strstr(const char*, const char*);
extern "C" int sprintf(char*, const char*, ...);
extern "C" unsigned int strlen(const char*);
const char* __cdecl FUN_000b09c0(int a, int b);
const char* __cdecl FUN_000b08a0(int a, int b);

struct Finder_d3f10 {
    char pad[4];
    Finder_d3f10* sub;
    Provider_d3f10* FUN_000ae640(int i);
    void* FUN_000d3f10(const char* name);
};

void* Finder_d3f10::FUN_000d3f10(const char* name) {
    char buf[64];
    int i = 0;
    const char* s = ((const char**)&DAT_0040b020)[0];
    for (;;) {
        if (s == 0) {
            return 0;
        }
        if (strcmp(s, name) == 0) break;
        s = ((const char**)&DAT_0040b020)[i + 1];
        i++;
    }
    int idx = ((Lookup_d3f10*)&DAT_004a0560)[i].idx;
    int kind = ((Lookup_d3f10*)&DAT_004a0560)[i].kind;
    const char* text = 0;
    if (kind == 3) {
        text = ((const char**)&DAT_004a0658)[idx];
    } else {
        Provider_d3f10* p;
        int n = 0;
        do {
            p = sub->FUN_000ae640(n);
            if (p) break;
            n++;
        } while (n < 1);
        kind = ((Lookup_d3f10*)&DAT_004a0560)[i].kind;
        if (kind == 1) {
            if (p) text = (const char*)p->FUN_000ad7b0(0, idx, 0);
            else text = FUN_000b09c0(idx, 0);
        } else if (kind == 2) {
            if (p) text = (const char*)p->FUN_000ad580(0, idx, 0);
            else text = FUN_000b08a0(idx, 0);
        }
    }
    if (strstr(text, (*(const char**)&DAT_004a06a4)) == text)
        text += strlen((*(const char**)&DAT_004a06a4));
    const char* prefix = (((Lookup_d3f10*)&DAT_004a0560)[i].kind == 3) ? "" : "xbox_ctrlr_btn_";
    sprintf(buf, "%s%s%s", prefix, text, (*(const char**)&DAT_004a06a0));
    content::LoadInventory* ld = (*(content::LoadInventory**)&DAT_004dd9cc);
    __int64 uid = FUN_0027b020(buf);
    void* r = ld->Find(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>(), uid);
    return r;
}
