// STATUS: equivalent (tools/equiv.py level 3: 194 inputs, branch coverage 67/84, incomplete)
// CSPHulkPropLoader::vfunc_5 @ 0x001d57d0
struct NameKey {
    unsigned lo;
    unsigned hi;
    NameKey *FUN_0027af10(unsigned a, unsigned b);
    void FUN_0027af50();
    void FUN_0027af60(unsigned a, unsigned b);
    void FUN_0027af70(NameKey *k);
    void FUN_0027b040(const char *s);
};

struct Item {
    NameKey key;
    const char *val;
    int pad;
};

struct Entry {
    NameKey key;
    const char *val;
    int pad;
};

struct Channel {
    char pad[0x3c];
    int count;
    Entry *entries;
};

struct PropData {
    char pad0[8];
    NameKey name;
    char pad10[0x1c - 0x10];
    Channel **channels;
    Channel **channelsEnd;
    char pad24[4];
    Item *items;
    Item *itemsEnd;
};

struct Reader;

struct Z {
    int FUN_00023e80(const char *s);
};

class P10 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual Z *v11();
};

struct P90 {
    char pad[0x10];
    P10 *p10;
};

struct Curves {
    float FUN_001df3e0(const char *s);
};

struct World {
    char pad[0xc];
    Curves *curves;
};
extern World *DAT_004dd700;
extern NameKey DAT_004e2430;
extern NameKey DAT_004e2438;
extern NameKey DAT_004e2448;
extern NameKey DAT_004e2450;
extern NameKey DAT_004e2458;
extern NameKey DAT_004e2460;
extern NameKey DAT_004e2468;
extern NameKey DAT_004e2470;
extern NameKey DAT_004e2478;
extern NameKey DAT_004e2480;
extern NameKey DAT_004e2488;
extern NameKey DAT_004e2490;
extern NameKey DAT_004e2498;
extern NameKey DAT_004e24a0;
extern NameKey DAT_004e24a8;
extern NameKey DAT_004e24b0;
extern NameKey DAT_004e24b8;

int __cdecl FUN_001d5050(const char *s);
int __cdecl FUN_001d50e0(const char *s);
int __cdecl FUN_001d51f0(const char *s);
int __cdecl FUN_001d5300(const char *s);
int __cdecl FUN_001d54c0(const char *s);
int __cdecl FUN_00096600(const char *a, const char *b);
float __cdecl FUN_003458c1(const char *s);
void *__cdecl FUN_00263ea0(unsigned int size);

struct PropObj {
    char pad0[8];
    NameKey name;
    char pad10[0x90 - 0x10];
    P90 *p90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    float fa4;
    int fa8;
    int fac;
    char fb0;
    char fb1;
    char fb2;
    char fb3;
    char fb4;
    char fb5;
    char fb6;
    char padb7;
    float *weights;
    char padbc[4];
    NameKey set;
    PropObj *FUN_001d4d50();
    void FUN_001d5730(PropData *d);
};

class StatePropDataLoader {
public:
    void FUN_00290bf0(PropData **out, NameKey *id, Reader *r, int unused);
};

class CSPHulkPropLoader : public StatePropDataLoader {
public:
    void vfunc_5(PropObj **out, NameKey *outId, Reader *r, int unused);
};

void CSPHulkPropLoader::vfunc_5(PropObj **out, NameKey *outId, Reader *r, int unused)
{
    PropData *data;
    NameKey id;
    FUN_00290bf0(&data, &id, r, unused);

    PropObj *obj = (PropObj *)FUN_00263ea0(0xc8);
    PropObj *n = 0;
    if (obj)
        n = obj->FUN_001d4d50();
    n->FUN_001d5730(data);
    n->name.FUN_0027af60(data->name.lo, data->name.hi);
    NameKey key;
    key.FUN_0027af10(data->name.lo, data->name.hi);
    n->set.FUN_0027af70(&key);

    int count = data->itemsEnd - data->items;
    if (count > 0) {
        for (int i = 0; i < count; i++) {
            Item *it = &data->items[i];
            if (it->key.lo == DAT_004e2448.lo && it->key.hi == DAT_004e2448.hi) {
                n->f94 = FUN_001d5050(it->val);
            } else if (it->key.lo == DAT_004e2460.lo && it->key.hi == DAT_004e2460.hi) {
                n->f9c = FUN_001d50e0(it->val);
            } else if (it->key.lo == DAT_004e2458.lo && it->key.hi == DAT_004e2458.hi) {
                n->fa0 = FUN_001d51f0(it->val);
            } else if (it->key.lo == DAT_004e2468.lo && it->key.hi == DAT_004e2468.hi) {
                n->fb0 = FUN_00096600(it->val, "true") == 0;
            } else if (it->key.lo == DAT_004e2470.lo && it->key.hi == DAT_004e2470.hi) {
                n->fa4 = FUN_003458c1(it->val);
            } else if (it->key.lo == DAT_004e2478.lo && it->key.hi == DAT_004e2478.hi) {
                n->fa8 = FUN_001d5300(it->val);
            } else if (it->key.lo == DAT_004e2480.lo && it->key.hi == DAT_004e2480.hi) {
                n->fac = FUN_001d54c0(it->val);
            } else if (it->key.lo == DAT_004e2488.lo && it->key.hi == DAT_004e2488.hi) {
                int v = n->p90->p10->v11()->FUN_00023e80(it->val);
                if (v != 0xffff)
                    n->f98 = v;
            } else if (it->key.lo == DAT_004e2450.lo && it->key.hi == DAT_004e2450.hi) {
                n->set.FUN_0027b040(it->val);
            } else if (it->key.lo == DAT_004e2490.lo && it->key.hi == DAT_004e2490.hi) {
                n->fb1 = FUN_00096600(it->val, "true") == 0;
            } else if (it->key.lo == DAT_004e2498.lo && it->key.hi == DAT_004e2498.hi) {
                n->fb2 = FUN_00096600(it->val, "true") == 0;
            } else if (it->key.lo == DAT_004e24a0.lo && it->key.hi == DAT_004e24a0.hi) {
                n->fb3 = FUN_00096600(it->val, "true") == 0;
            } else if (it->key.lo == DAT_004e24a8.lo && it->key.hi == DAT_004e24a8.hi) {
                n->fb4 = FUN_00096600(it->val, "true") == 0;
            } else if (it->key.lo == DAT_004e24b0.lo && it->key.hi == DAT_004e24b0.hi) {
                n->fb5 = FUN_00096600(it->val, "true") == 0;
            } else if (it->key.lo == DAT_004e24b8.lo && it->key.hi == DAT_004e24b8.hi) {
                n->fb6 = FUN_00096600(it->val, "true") == 0;
            }
        }
    }

    Curves *curves = DAT_004dd700->curves;
    int nch = data->channelsEnd - data->channels;
    for (int i = 0; i < nch; i++) {
        int cnt = data->channels[i]->count;
        float a = -1.0f;
        float b = 1.0f;
        for (int j = 0; j < cnt; j++) {
            Entry *e = &data->channels[i]->entries[j];
            if (e->key.lo == DAT_004e2430.lo && e->key.hi == DAT_004e2430.hi) {
                a = curves->FUN_001df3e0(e->val);
            } else if (e->key.lo == DAT_004e2438.lo && e->key.hi == DAT_004e2438.hi) {
                b = FUN_003458c1(e->val);
            }
        }
        n->weights[i] = b * a;
    }

    *out = n;
    outId->lo = n->name.lo;
    outId->hi = n->name.hi;
    key.FUN_0027af50();
}
