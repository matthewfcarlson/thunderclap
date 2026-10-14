// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00027d60 @ 0x00027d60
// Group method: look up a named pawn and a bank/node by path, then register the pawn's slot with it.
typedef unsigned __int64 Key;
extern Key __cdecl FUN_002672f0(const char *name, int a, int b);
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, const void *srcType, const void *dstType, int isRef);
extern char DAT_0048e090;
extern char DAT_0048e0ac;
extern char DAT_0048e0c8;
extern const char *DAT_0048e064;

struct Node {
    void FUN_00231ad0(void *slot, int arg, unsigned int flags);
};

struct Found {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual Node *Resolve(int arg, int zero);       // slot 8
};

struct Pawn {
    char pad00[0xb4];
    char slot[4];                   // 0xb4
    char pad0b8[0x104 - 0xb8];
    int arg;                        // 0x104
};

struct Tree {
    Found *FUN_00233580(const char *path);
};

struct Entry {
    char pad[0x5c];
    Tree *tree;                     // 0x5c
};

struct Registry {
    Entry *FUN_00232840(Key key);
};

extern Registry *DAT_004e5af8;

struct Group {
    Pawn *FUN_00024280(Key key);
    void FUN_00027d60(const char *name, const char *path);
};

void Group::FUN_00027d60(const char *name, const char *path)
{
    Pawn *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (!pawn)
        return;
    if (!path)
        return;
    const char *keyName = DAT_0048e064;
    Registry *registry = DAT_004e5af8;
    Found *found = registry->FUN_00232840(FUN_002672f0(keyName, 0, 0))->tree->FUN_00233580(path);
    if (!found)
        return;
    int arg = pawn->arg;
    Node *node = (Node *)FUN_00344e74(found, 0, &DAT_0048e090, &DAT_0048e0ac, 0);
    if (!node) {
        Found *bank = (Found *)FUN_00344e74(found, 0, &DAT_0048e090, &DAT_0048e0c8, 0);
        if (!bank)
            return;
        node = bank->Resolve(arg, 0);
        if (!node)
            return;
    }
    node->FUN_00231ad0(pawn->slot, arg, 0x80000000);
}
