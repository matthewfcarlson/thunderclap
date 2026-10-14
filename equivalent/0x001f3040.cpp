// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001f3040 @ 0x001f3040
// FUN_001f3040: look up an entry and fetch two sound handles from it (or default to "hulk")
typedef unsigned __int64 u64;

struct Node {
    char pad00[8];
    int nameA;
    int nameB;
    int nameC;
    int nameD;
    int flag;
};

struct Key {
    u64 key;
};

struct Dest {
    char pad00[0x10];
    int handleA;
    int handleB;
    char pad18[0x5c];
    int flag;
};

struct Sound {
    int FUN_001e9860(int a, int b);
    int FUN_001ea010(const char *name);
};

extern Sound *DAT_004e3690;

Node *__cdecl FUN_001f2ff0(Key *k);
u64 __cdecl FUN_0027b020(const char *name);

void __cdecl FUN_001f3040(Dest *d, Key *k)
{
    Node *n = FUN_001f2ff0(k);
    if (n != 0) {
        d->handleA = DAT_004e3690->FUN_001e9860(n->nameA, n->nameB);
        d->handleB = DAT_004e3690->FUN_001e9860(n->nameC, n->nameD);
        d->flag = n->flag;
        return;
    }
    if (k->key == FUN_0027b020("hulk")) {
        d->handleA = DAT_004e3690->FUN_001ea010("hulk_sfx");
        d->handleB = DAT_004e3690->FUN_001ea010("hulk_vox");
        d->flag = 1;
    }
}
