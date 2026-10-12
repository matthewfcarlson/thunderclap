// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 40/42, incomplete)
// FUN_0029e320 @ 0x0029e320
extern float DAT_003f32e0;  // 0.0
extern float DAT_0042d61c;  // -0.0001
extern float DAT_0042d620;  // 0.333
extern char DAT_004c534c[];
extern char DAT_004cf658[];

void *__cdecl FUN_00263ea0(unsigned int size);
void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

struct V3 {
    float x, y, z;
};

struct Node {
    Node *FUN_002a2e70();
    void FUN_002a07a0(unsigned int color);
    void FUN_002a2fc0(const V3 *pos);
};

struct Container {
    char pad0[0x10];
    int count;              // 0x10
    int size;               // 0x14
    Node **items;           // 0x18
    void FUN_002a0fc0(int index, Node *node);
};

struct List {
    void FUN_002a1180(int n);
};

struct Rec {                // 0x20 bytes
    int f00;
    unsigned int color;     // 0x04
    int f08;
    V3 pos;                 // 0x0c
    int f18;
    int f1c;
};

struct Holder40 {
    List *list;
    Rec *recs;
    void FUN_0029c660();
};

union Arg3 {
    int value;
    char flag;
};

static inline int ColorMax(unsigned int c)
{
    int m = c & 0xff;
    int g = (c >> 8) & 0xff;
    if (g >= m)
        m = g;
    int b = (c >> 16) & 0xff;
    if (b >= m)
        m = b;
    return m;
}

class Effect {
public:
    char pad0[0x40];
    Holder40 *f40;
    float FUN_0029dcc0(int a, int b);
    float FUN_0029dd30(Holder40 *h);
    void FUN_0029e320(Container *c, V3 *p, Arg3 a3);
};

void Effect::FUN_0029e320(Container *c, V3 *p, Arg3 a3)
{
    int n = c->size;
    if (n == 0)
        return;

    f40->FUN_0029c660();
    f40->list->FUN_002a1180(n + 1);
    float scale = FUN_0029dcc0(a3.value, 4);

    float x = p->x < DAT_003f32e0 ? p->x : DAT_003f32e0;
    float y = p->y < DAT_003f32e0 ? p->y : DAT_003f32e0;
    float z = p->z < DAT_003f32e0 ? p->z : DAT_003f32e0;
    float blend = 1.0f;
    a3.flag = 0;
    float avg = (z + y + x) * DAT_0042d620;
    if (scale > DAT_003f32e0 && avg < DAT_0042d61c) {
        a3.flag = 1;
        blend = (avg + scale) / scale;
        if (blend < DAT_003f32e0)
            blend = 0.0f;
    }

    FUN_0029dd30(f40);
    int top = ColorMax(f40->recs[n].color);
    for (int i = 0; i < n; i++) {
        int m = ColorMax(f40->recs[i].color) - top;
        int v;
        if (m < 0)
            v = 0;
        else if (m > 0xff)
            v = 0xff;
        else
            v = m;
        if (a3.flag)
            v = (int)(v * blend);
        if (v <= 0) {
            c->FUN_002a0fc0(i, 0);
        } else {
            Node *node = i < c->count ? c->items[i] : 0;
            Node *obj = (Node *)FUN_00344e74(node, 0, DAT_004c534c, DAT_004cf658, 0);
            if (!obj) {
                void *mem = FUN_00263ea0(0x68);
                if (mem)
                    obj = ((Node *)mem)->FUN_002a2e70();
                else
                    obj = 0;
                c->FUN_002a0fc0(i, obj);
            }
            obj->FUN_002a07a0((((v | 0xffffff00u) << 8 | v) << 8) | v);
            V3 pos = f40->recs[i].pos;
            obj->FUN_002a2fc0(&pos);
        }
    }
}
