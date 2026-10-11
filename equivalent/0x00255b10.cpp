// STATUS: equivalent (tools/equiv.py level 3: 63 inputs, branch coverage 32/32)
// audio::SeqActionCrossFade::vfunc_1 @ 0x00255b10
struct Group;
struct Handle;
struct Item;

struct Pair {
    int a;
    int b;
};

struct Source {
    char pad0[0x3c];
    Group *group;
};

struct Layer {
    char pad0[8];
    Source *owner;
};

struct Item {
    char pad0[8];
    Source *source;
};

struct Target {
    char pad0[0x2c];
    int level;
};

struct Config {
    char pad0[8];
    int f8;
    int fc;
    int f10;
    int f14;
    char pad18;
    char keepAlive;
    char pad1a[0x2c - 0x1a];
    int levels;
};

Handle *__cdecl FUN_002495c0(Group *g);
Item *__cdecl FUN_002495f0(Handle *h);
Item *__cdecl FUN_00249600(Handle *h, Item *prev);
Handle *__cdecl FUN_002495e0(Group *g, Handle *h);
void __cdecl FUN_002497e0(Item *item);
int __cdecl FUN_00247930(Group *g, Item *item);
void __cdecl FUN_00247a90(Group *g, Item *item, Pair *p);
void __cdecl FUN_00247b30(Group *g, Item *item, Pair *p, int zero);
bool __cdecl FUN_00261f90(int *levels, int cur, int target);

class SeqActionCrossFade {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(Source *src);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad4[4];
    Config *config;
    int state;
    Item *current;
    Target *pending;
    int level;
    bool FUN_00255980(Group *g, Target *t);
};

void SeqActionCrossFade::vfunc_1(Source *src)
{
    if (current) {
        if (pending) {
            if (FUN_00255980(src->group, pending)) {
                int t = pending->level;
                if (!FUN_00261f90(&config->levels, level, t)) {
                    level = t;
                    return;
                }
            }
        }

        Group *g = src->group;
        Handle *h = FUN_002495c0(g);
        while (h) {
            Item *it = FUN_002495f0(h);
            while (it) {
                if (current == it) {
                    Pair p1;
                    p1.a = config->f8;
                    p1.b = config->fc;
                    if (FUN_00247930(g, it) == 2)
                        FUN_00247a90(g, it, &p1);
                } else if (it->source != src) {
                    int r = FUN_00247930(g, it);
                    if (r != 0 && r != 5) {
                        Pair p2;
                        p2.a = config->f10;
                        p2.b = config->f14;
                        FUN_00247b30(g, it, &p2, 0);
                    }
                }
                it = FUN_00249600(h, it);
            }
            h = FUN_002495e0(g, h);
        }

        if (!config->keepAlive) {
            FUN_002497e0(current);
            current = 0;
        }
    }

    if (config->keepAlive && current)
        state = 3;
    else
        state = 0;
}
