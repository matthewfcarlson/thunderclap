// STATUS: equivalent (tools/equiv.py level 3: 174 inputs, branch coverage 48/48)
// pure3d::SkeletonLoader::vfunc_5 @ 0x0027c140
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// equiv-conv: FUN_0027b340 eax
#include "compat/ptr.h"
#include "decls/address.h"
void *thunk_FUN_0008d690(unsigned int size);
void *FUN_0008d690(unsigned int size);
void *FUN_0008d6d0(unsigned int size);
extern "C" int __cdecl FUN_0028fcc0(const char *fmt, ...);
unsigned int FUN_0027b340(const char *s);

struct Name8_27c140 {
    void FUN_0027b040(const char *name);
};

struct Stream {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Loader_27c140 {
    char pad0[0x284];
    Stream *stream;
    char FUN_002669f0();
    void FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
    void FUN_000f9600(char *buf);
};

struct Elem_27c140 {
    char pad0[8];
    unsigned int idLo;
    unsigned int idHi;
    int *arr10;
    int f14;
    int f18;
    int f1c;
    int f20;
};

struct Info_27c140 {
    void *skel;
    unsigned int f4;
    char **names8;
    unsigned int fc;
    char **names10;
    char **names14;
};

struct Skeleton {
    char pad0[8];
    Name8_27c140 name;
    char pad9[0x18 - 9];
    char *mats;
    char pad1c[0x24 - 0x1c];
    char *ids;
    char *parents;
    Info_27c140 *info;
    char pad30[4];
    char *arrA;
    char pad38[0x44 - 0x38];
    char *arrB;
    Skeleton *FUN_0027bee0(int a, int b, int c);
    void FUN_0027b270();
};

class SkeletonLoader {
public:
    char pad0[0x14];
    char b14;
    void F(Skeleton **out, unsigned __int64 *outId, Loader_27c140 *ld, int unused);
};

static char *DupStr(const char *src)
{
    const char *p = src;
    while (*p)
        p++;
    unsigned int n = (unsigned int)(p - src) + 1;
    char *dst = (char *)FUN_0008d6d0(n);
    char *d = dst;
    const char *q = src;
    char c;
    do {
        c = *q++;
        *d++ = c;
    } while (c);
    return dst;
}

void SkeletonLoader::F(Skeleton **out, unsigned __int64 *outId, Loader_27c140 *ld, int unused)
{
    struct Frame {
        char pad0c[2];
        unsigned char len1;
        unsigned char len2;
        int v10, v14, v18, v1c, v20, v24, v28, v2c, v30, v34, v38, v3c, v40, v44, v48, v4c, v50, v54;
        char N[0x100];
        char N2[0x100];
        char N3[0x100];
        char N4[0x100];
    } fr;

    ld->stream->FUN_002647e0(&fr.len1, 1, 1, 1);
    int len = fr.len1;
    ld->stream->FUN_002647e0(fr.N, len, 1, 1);
    fr.N[len] = 0;
    ld->stream->FUN_002647e0(&fr.v38, 1, 4, 1);
    ld->stream->FUN_002647e0(&fr.v1c, 1, 4, 1);
    ld->stream->FUN_002647e0(&fr.v10, 1, 4, 1);
    ld->stream->FUN_002647e0(&fr.v18, 1, 4, 1);
    unsigned int nJoints = fr.v1c;
    if (nJoints < 1) {
        FUN_0028fcc0("SkeletonLoader - skipping skeleton: '%s' because nJoints out of range: %d\n", fr.N, nJoints);
        return;
    }
    Skeleton *raw = (Skeleton *)thunk_FUN_0008d690(0x50);
    Skeleton *sk = 0;
    if (raw)
        sk = raw->FUN_0027bee0(nJoints, fr.v10, fr.v18);
    fr.v24 = (hulk_intptr)sk;
    sk->name.FUN_0027b040(fr.N);
    Info_27c140 *sp = 0;
    fr.v14 = 0;
    if (b14) {
        Info_27c140 *p = (Info_27c140 *)FUN_0008d690(0x18);
        if (p) {
            p->f4 = 0;
            p->names8 = 0;
            p->fc = 0;
            p->names10 = 0;
            p->names14 = 0;
            sp = p;
            p->skel = sk;
            fr.v14 = (hulk_intptr)sp;
        }
        sp->f4 = FUN_0027b340(fr.N);
        sp->names8 = (char **)FUN_0008d6d0(nJoints * 4);
        unsigned int b2 = fr.v10;
        if (b2 != 0) {
            sp->fc = b2;
            sp->names10 = (char **)FUN_0008d6d0(b2 * 4);
        }
        unsigned int b3 = fr.v18;
        if (b3 != 0)
            sp->names14 = (char **)FUN_0008d6d0(b3 * 4);
        sk->info = sp;
        sp = 0;
    }
    if (ld->FUN_002669f0()) {
        fr.v10 = 0;
        fr.v18 = 0;
        fr.v1c = 0;
        fr.v20 = 0;
        fr.v28 = 0;
        fr.v2c = 0;
        fr.v34 = 0;
        fr.v30 = 0;
        do {
            ld->FUN_00266a30();
            if (ld->FUN_00266c30() == 0x23001) {
                ld->stream->FUN_002647e0(&fr.len1, 1, 1, 1);
                int n = fr.len1;
                ld->stream->FUN_002647e0(fr.N2, n, 1, 1);
                fr.N2[n] = 0;
                unsigned __int64 h = FUN_002672f0(fr.N2, 0, 0);
                char *ids = sk->ids;
                *(unsigned int *)(ids + fr.v30) = (unsigned int)h;
                *(unsigned int *)(ids + fr.v30 + 4) = (unsigned int)(h >> 32);
                ld->stream->FUN_002647e0(&fr.v44, 1, 4, 1);
                *(unsigned short *)(sk->parents + fr.v34) = (unsigned short)fr.v44;
                ld->stream->FUN_002647e0(sk->mats + fr.v2c, 0x10, 4, 1);
                Info_27c140 *s2 = (Info_27c140 *)fr.v14;
                if (s2) {
                    char *dup = DupStr(fr.N2);
                    *(char **)((char *)s2->names8 + fr.v28) = dup;
                }
                fr.v30 += 8;
                fr.v34 += 2;
                fr.v2c += 0x40;
                fr.v28 += 4;
            } else if (ld->FUN_00266c30() == 0x23002) {
                Elem_27c140 *e = (Elem_27c140 *)(sk->arrA + fr.v20);
                ld->stream->FUN_002647e0(&fr.len2, 1, 1, 1);
                int n = fr.len2;
                ld->stream->FUN_002647e0(fr.N3, n, 1, 1);
                fr.N3[n] = 0;
                unsigned __int64 h = FUN_002672f0(fr.N3, 0, 0);
                e->idLo = (unsigned int)h;
                e->idHi = (unsigned int)(h >> 32);
                ld->stream->FUN_002647e0(&fr.v3c, 1, 4, 1);
                unsigned int cnt = fr.v3c;
                if (cnt != 0) {
                    unsigned int j = 0;
                    do {
                        ld->stream->FUN_002647e0(&fr.v4c, 1, 4, 1);
                        e->arr10[j + 1] = fr.v4c;
                        j++;
                    } while (j < cnt);
                }
                Info_27c140 *s2 = (Info_27c140 *)fr.v14;
                if (s2) {
                    char *dup = DupStr(fr.N3);
                    *(char **)((char *)s2->names10 + fr.v1c) = dup;
                }
                fr.v20 += 0x18;
                fr.v1c += 4;
            } else if (ld->FUN_00266c30() == 0x23003) {
                Elem_27c140 *e = (Elem_27c140 *)(sk->arrB + fr.v18);
                ld->FUN_000f9600(fr.N4);
                unsigned __int64 h = FUN_002672f0(fr.N4, 0, 0);
                e->idLo = (unsigned int)h;
                e->idHi = (unsigned int)(h >> 32);
                ld->stream->FUN_002647e0(&fr.v48, 1, 4, 1);
                e->f18 = fr.v48;
                ld->stream->FUN_002647e0(&fr.v50, 1, 4, 1);
                e->f1c = fr.v50;
                ld->stream->FUN_002647e0(&fr.v54, 1, 4, 1);
                e->f20 = fr.v54;
                ld->stream->FUN_002647e0(&fr.v40, 1, 4, 1);
                unsigned int cnt = fr.v40;
                if (cnt != 0) {
                    unsigned int j = 0;
                    do {
                        ld->stream->FUN_002647e0(&fr.v38, 1, 4, 1);
                        e->arr10[j + 1] = fr.v38;
                        j++;
                    } while (j < cnt);
                }
                Info_27c140 *s2 = (Info_27c140 *)fr.v14;
                if (s2) {
                    char *dup = DupStr(fr.N4);
                    *(char **)((char *)s2->names14 + fr.v10) = dup;
                }
                fr.v18 += 0x28;
                fr.v10 += 4;
            } else {
                FUN_0028fcc0("SkeletonLoader - skipping unknown subchunk: '0x%X'\n", ld->FUN_00266c30());
            }
            ld->FUN_00266be0();
        } while (ld->FUN_002669f0());
    }
    sk->FUN_0027b270();
    *out = sk;
    *outId = FUN_002672f0(fr.N, 0, 0);
}
