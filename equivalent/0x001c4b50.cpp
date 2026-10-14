// STATUS: equivalent (tools/equiv.py level 3: 113 inputs, branch coverage 38/38)
// FUN_001c4b50 @ 0x001c4b50
struct V3_1c4b50 {
    float x, y, z;
};

struct Out_1c4b50 : V3_1c4b50 {
    float w;
    void FUN_000110d0(const V3_1c4b50 *p);
};

struct Mat_1c4b50 {
    float m[16];
    void FUN_0022c2b0(const V3_1c4b50 *in, V3_1c4b50 *out);
};

struct Mgr_1c4b50 {
    char pad0[0xc];
    unsigned int count;
    char pad10[0x1c - 0x10];
    Mat_1c4b50 *elems;
    char pad20[3];
    char flag23;
    unsigned int FUN_002843a0(int lo, int hi);
    void FUN_00284820(Mat_1c4b50 *m);
};

struct HashPair {
    char pad0[8];
    unsigned int lo;
    unsigned int hi;
};

struct Info_1c4b50 {
    char pad0[0x84];
    char flag84;
    char flag85;
};

class Body_1c4b50 {
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual Mat_1c4b50 *v15();
    char pad4[0xec - 4];
    HashPair *hash;
    char FUN_001d64c0();
    Info_1c4b50 *FUN_001d72e0();
};

unsigned __int64 __cdecl FUN_0027b020(const char *name) throw();
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);
extern const char *DAT_004c5188;

class Locator {
public:
    char pad0[0x18];
    Mgr_1c4b50 *mgr;
    Body_1c4b50 *body;
    char pad20[2];
    char hasBody;
    char pad23[0x30 - 0x23];
    Mat_1c4b50 mat30;
    V3_1c4b50 vec70;
    float f7c;

    void FUN_001c4b50(Out_1c4b50 *out);
};

void Locator::FUN_001c4b50(Out_1c4b50 *out)
{
    if (!out)
        return;
    out->w = f7c;
    if (!mgr || mgr->count == 0) {
        mat30.FUN_0022c2b0(&vec70, out);
        return;
    }
    static unsigned __int64 cowHash = FUN_0027b020("cow_male_cow_male");
    bool match = false;
    if (hasBody && body) {
        if (body->FUN_001d64c0()) {
            HashPair *h = body->hash;
            if (h->lo == (unsigned int)cowHash && h->hi == (unsigned int)(cowHash >> 32))
                match = true;
            else
                match = false;
        } else {
            match = false;
        }
    }
    Mgr_1c4b50 *m = mgr;
    unsigned __int64 id = FUN_002672f0(DAT_004c5188, 0, 0);
    unsigned int idx = m->FUN_002843a0((int)id, (int)(id >> 32));
    if (idx != 0xffff && !match) {
        Mat_1c4b50 *e = &mgr->elems[idx];
        const V3_1c4b50 *p = (const V3_1c4b50 *)&e->m[12];
        out->x = p->x;
        out->y = p->y;
        out->z = p->z;
        if (mgr->flag23)
            out->FUN_000110d0((const V3_1c4b50 *)&mat30.m[12]);
        return;
    }
    V3_1c4b50 v;
    if (mgr->flag23) {
        mat30.FUN_0022c2b0(&vec70, &v);
    } else {
        v.x = vec70.x;
        v.y = vec70.y;
        v.z = vec70.z;
    }
    if (hasBody && body) {
        Info_1c4b50 *info = body->FUN_001d72e0();
        if (!info || !body->FUN_001d72e0()->flag84) {
            Info_1c4b50 *info2 = body->FUN_001d72e0();
            if (info2 && body->FUN_001d72e0()->flag85) {
                mgr->FUN_00284820(body->v15());
            } else {
                body->v15()->FUN_0022c2b0(&vec70, out);
                return;
            }
        }
    }
    mgr->elems->FUN_0022c2b0(&v, out);
}
