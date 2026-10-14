// STATUS: equivalent (tools/equiv.py level 3: 233 inputs, branch coverage 42/47, incomplete)
// physics::CollisionObjectLoader::vfunc_5 @ 0x00308410
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0

struct Stream {
    char FUN_002647e0(void *dest, unsigned int count, unsigned int size, int flag);
};

struct Reader {
    char pad[0x284];
    Stream *stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
    int FUN_00266c30();
};

struct NameField_308410 {
    void FUN_0027b040(const char *s);
};

struct NameKey_308410 {
    unsigned int lo;
    unsigned int hi;
};

struct HashList {
    int count;
    int cap;
    unsigned __int64 *data;
    int pad;
    void FUN_00304a10(int newCap);
};

struct Sub38_308410 {
    void FUN_00307f30(int n);
};

struct Target_308410 {
    void FUN_00306300();
};

class CollisionObject {
public:
    char pad0[8];
    NameField_308410 name;
    char pad9[7];
    NameField_308410 name2;
    char pad11[0x20 - 0x11];
    Target_308410 *f20;
    int f24;
    char pad28[0x38 - 0x28];
    Sub38_308410 sub;
    char pad39[0x3c - 0x39];
    HashList *lists;
    char pad40[0x50 - 0x40];
    char b50;
    char pad51[3];
    int f54;
    char pad58[0x68 - 0x58];
    char b68;
    char b69;
    char pad6a[2];
    int f6c;
    char pad70[0x78 - 0x70];
    int f78;
    char pad7c[4];

    CollisionObject *FUN_00304ed0();
    void FUN_00305190(int v1, int v2, bool b1, bool b2);
    void FUN_00304b40(int x);
    void FUN_00304740(int x);
};

void *thunk_FUN_0008d690(unsigned int size);
unsigned __int64 __cdecl FUN_0027b020(const char *s);
int __cdecl FUN_003080a0(Reader *r);
int __cdecl FUN_002f2750(unsigned int lo, unsigned int hi);

class CollisionObjectLoader {
public:
    void vfunc_5(CollisionObject **out, NameKey_308410 *outId, Reader *r, int unused);
};

struct Frame_308410 {
    char pad10[3];
    unsigned char len;
    int tmp;
    char pad18[2];
    unsigned char flag5;
    unsigned char flag6;
    unsigned short s4;
    short p1c;
    unsigned short s5;
    short p20;
    unsigned short s6;
    short p24;
    unsigned short s2;
    short p28;
    unsigned short s3;
    short p2c;
    unsigned short sD;
    short p30;
    unsigned short s1;
    short p34;
    int n;
    int v1;
    int v3;
    int v2;
    NameKey_308410 *savedName;
    int i1;
    int i2;
    int i3;
    char name2[0x100];
    char name1[0x100];
    char name3[0x100];
};

void CollisionObjectLoader::vfunc_5(CollisionObject **out, NameKey_308410 *outId, Reader *r, int unused)
{
    Frame_308410 f;
    void *mem = thunk_FUN_0008d690(0x80);
    CollisionObject *obj = 0;
    if (mem)
        obj = ((CollisionObject *)mem)->FUN_00304ed0();

    r->stream->FUN_002647e0(&f.len, 1, 1, 1);
    unsigned int l1 = f.len;
    r->stream->FUN_002647e0(f.name1, l1, 1, 1);
    f.name1[l1] = 0;
    f.savedName = (NameKey_308410 *)&obj->name;
    obj->name.FUN_0027b040(f.name1);

    r->stream->FUN_002647e0(&f.tmp, 1, 4, 1);
    obj->f78 = f.tmp;
    r->stream->FUN_002647e0(&f.len, 1, 1, 1);
    unsigned int l2 = f.len;
    r->stream->FUN_002647e0(f.name2, l2, 1, 1);
    f.name2[l2] = 0;
    obj->name2.FUN_0027b040(f.name2);

    r->stream->FUN_002647e0(&f.tmp, 1, 4, 1);
    obj->f24 = f.tmp;
    r->stream->FUN_002647e0(&f.tmp, 1, 4, 1);
    if (f.tmp > 0)
        obj->sub.FUN_00307f30(f.tmp);

    if (r->FUN_002669f0()) {
        f.tmp = 0;
        do {
            r->FUN_00266a30();
            int id = r->FUN_00266c30();
            switch (id) {
            case 0x7010001:
                obj->FUN_00304b40(FUN_003080a0(r));
                break;
            case 0x7010020:
                r->stream->FUN_002647e0(&f.v1, 1, 4, 1);
                r->stream->FUN_002647e0(&f.v2, 1, 4, 1);
                r->stream->FUN_002647e0(&f.s1, 1, 2, 1);
                r->stream->FUN_002647e0(&f.s2, 1, 2, 1);
                obj->FUN_00305190(f.v1, f.v2, f.s1 != 0, f.s2 != 0);
                break;
            case 0x7010021:
                r->stream->FUN_002647e0(&f.n, 1, 4, 1);
                if (f.n > 0 && r->FUN_002669f0()) {
                    do {
                        r->FUN_00266a30();
                        if (r->FUN_00266c30() == 0x7010022) {
                            r->stream->FUN_002647e0(&f.len, 1, 1, 1);
                            unsigned int l3 = f.len;
                            r->stream->FUN_002647e0(f.name3, l3, 1, 1);
                            f.name3[l3] = 0;
                            HashList *list = (HashList *)((char *)obj->lists + f.tmp);
                            if (list->count >= list->cap)
                                list->FUN_00304a10(list->cap * 2);
                            list->count++;
                            unsigned __int64 *slot = &list->data[list->count - 1];
                            *slot = FUN_0027b020(f.name3);
                        }
                        r->FUN_00266be0();
                    } while (r->FUN_002669f0());
                }
                f.tmp += 0x10;
                break;
            case 0x7010023: {
                r->stream->FUN_002647e0(&f.sD, 1, 2, 1);
                obj->b50 = f.sD != 0;
                r->stream->FUN_002647e0(&f.v3, 1, 4, 1);
                obj->f54 = f.v3;
                r->stream->FUN_002647e0(&f.s3, 1, 2, 1);
                r->stream->FUN_002647e0(&f.s4, 1, 2, 1);
                bool b4 = f.s4 != 0;
                r->stream->FUN_002647e0(&f.s5, 1, 2, 1);
                r->stream->FUN_002647e0(&f.s6, 1, 2, 1);
                f.flag5 = f.s5 != 0;
                r->stream->FUN_002647e0(&f.i1, 1, 4, 1);
                f.flag6 = f.s6 != 0;
                r->stream->FUN_002647e0(&f.i2, 1, 4, 1);
                r->stream->FUN_002647e0(&f.i3, 1, 4, 1);
                int m = f.s3 != 0 ? 0xf : 0xb;
                if (!b4)
                    m -= 2;
                if (!f.flag5)
                    m -= 8;
                if (!f.flag6)
                    m -= 1;
                obj->f6c = m;
                break;
            }
            default:
                break;
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }

    unsigned __int64 key = FUN_0027b020(f.name2);
    obj->FUN_00304740(FUN_002f2750((unsigned int)key, (unsigned int)(key >> 32)));
    if (obj->b50) {
        obj->f20->FUN_00306300();
        obj->b68 = 0;
        obj->b69 = 0;
    }
    *out = obj;
    outId->lo = f.savedName->lo;
    outId->hi = f.savedName->hi;
}
