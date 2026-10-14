// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 12/12)
// FUN_00027c90 @ 0x00027c90
// Group method: look up a named pawn and a node by path, then register the pawn's slot with it.
typedef unsigned __int64 Key;
extern Key __cdecl FUN_002672f0(const char *name, int a, int b);
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, const void *srcType, const void *dstType, int isRef);
extern char DAT_0048e090;
extern char DAT_0048e0ac;
extern const char *DAT_0048e060;

struct Node {
    void FUN_00231ad0(void *slot, int arg, unsigned int flags);
};

struct Found {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual Node *Resolve(int arg, int zero);       // slot 8
};

struct Flags {
    char pad[0xa8];
    char flag;                      // 0xa8
};

struct Pawn2 {
    char pad00[0xdc];
    char slot[4];                   // 0xdc
    char pad0e0[0x104 - 0xe0];
    int arg;                        // 0x104
    Flags *FUN_00036a80(int on);
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
    Pawn2 *FUN_00024280(Key key);
    void FUN_00027c90(const char *name, const char *path);
};

void Group::FUN_00027c90(const char *name, const char *path)
{
    Pawn2 *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (!pawn)
        return;
    if (!path)
        return;
    const char *keyName = DAT_0048e060;
    Registry *registry = DAT_004e5af8;
    Found *found = registry->FUN_00232840(FUN_002672f0(keyName, 0, 0))->tree->FUN_00233580(path);
    if (!found)
        return;
    int arg = pawn->arg;
    Node *node = (Node *)FUN_00344e74(found, 0, &DAT_0048e090, &DAT_0048e0ac, 0);
    if (!node) {
        node = found->Resolve(arg, 0);
        if (!node)
            return;
    }
    Flags *f = pawn->FUN_00036a80(1);
    if (f)
        f->flag = 1;
    node->FUN_00231ad0(pawn->slot, arg, 0x80000000);
}
