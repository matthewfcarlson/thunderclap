// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00027d60 @ 0x00027d60
// Group method: look up a named pawn and a bank/node by path, then register the pawn's slot with it.
#include "decls/address.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/unknown.h"
typedef unsigned __int64 Key_27d60;
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, const void *srcType, const void *dstType, int isRef);
extern char DAT_0048e090;
extern char DAT_0048e0ac;
extern char DAT_0048e0c8;

struct Node {
    void FUN_00231ad0(void *slot, int arg, unsigned int flags);
};

struct Found_27d60 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual Node *Resolve(int arg, int zero);       // slot 8
};

struct Pawn_27d60 {
    char pad00[0xb4];
    char slot[4];                   // 0xb4
    char pad0b8[0x104 - 0xb8];
    int arg;                        // 0x104
};

struct Tree_27d60 {
    Found_27d60 *FUN_00233580(const char *path);
};

struct Entry_27d60 {
    char pad[0x5c];
    Tree_27d60 *tree;                     // 0x5c
};

struct Registry_27d60 {
    Entry_27d60 *FUN_00232840(Key_27d60 key);
};


struct Group_27d60 {
    Pawn_27d60 *FUN_00024280(Key_27d60 key);
    void FUN_00027d60(const char *name, const char *path);
};

void Group_27d60::FUN_00027d60(const char *name, const char *path)
{
    Pawn_27d60 *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (!pawn)
        return;
    if (!path)
        return;
    const char *keyName = (*(const char**)&DAT_0048e064);
    Registry_27d60 *registry = (*(Registry_27d60**)&DAT_004e5af8);
    Found_27d60 *found = registry->FUN_00232840(FUN_002672f0(keyName, 0, 0))->tree->FUN_00233580(path);
    if (!found)
        return;
    int arg = pawn->arg;
    Node *node = (Node *)FUN_00344e74(found, 0, &DAT_0048e090, &DAT_0048e0ac, 0);
    if (!node) {
        Found_27d60 *bank = (Found_27d60 *)FUN_00344e74(found, 0, &DAT_0048e090, &DAT_0048e0c8, 0);
        if (!bank)
            return;
        node = bank->Resolve(arg, 0);
        if (!node)
            return;
    }
    node->FUN_00231ad0(pawn->slot, arg, 0x80000000);
}
