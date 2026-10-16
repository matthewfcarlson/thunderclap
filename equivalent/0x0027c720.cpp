// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 10/10)
// pure3d::LegacySkeletonLoader::vfunc_5 @ 0x0027c720
#include "gen/pure3d.h"
#include "decls/address.h"

struct Stream_27c720 {
    char FUN_002647e0(void* dest, unsigned count, unsigned size, int flag);
};

struct Reader_27c720 {
    char pad[0x284];
    Stream_27c720* stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
    int FUN_00266c30();
};

struct NameField_27c720 {
    void FUN_0027b040(const char* name);
};

struct Skeleton_27c720 {
    char pad0[8];
    NameField_27c720 name;
    char pad9[0x18 - 9];
    char* matrices;
    char pad1c[8];
    unsigned __int64* hashes;
    unsigned short* parents;
    Skeleton_27c720* FUN_0027bee0(int nJoints, int a, int b);
    void FUN_0027b270();
};

void* FUN_00263ea0(unsigned int size);
void FUN_0028fcc0(const char* fmt, const char* name);

struct Frame_27c720 {
    char pad0[3];
    unsigned char len;
    int w10;
    int w14;
    int w18;
    int w1c;
    int w20;
    int w24;
    int w28;
    int w2c;
    char name[0x100];
    char jointName[0x100];
};

void pure3d::LegacySkeletonLoader::vfunc_5(void* __p0, void* __p1, void* __p2, int unused) { Skeleton_27c720 ** out = (Skeleton_27c720 **)__p0; unsigned long long * outId = (unsigned long long *)__p1; Reader_27c720 * r = (Reader_27c720 *)__p2;

    Frame_27c720 f;

    r->stream->FUN_002647e0(&f.len, 1, 1, 1);
    unsigned int n = f.len;
    r->stream->FUN_002647e0(f.name, n, 1, 1);
    f.name[n] = 0;
    r->stream->FUN_002647e0(&f.w18, 1, 4, 1);
    r->stream->FUN_002647e0(&f.w10, 1, 4, 1);
    int nJoints = f.w10;
    if (nJoints < 1)
        FUN_0028fcc0("LegacySkeletonLoader - skipping skeleton: '%s' because nJoints < 1\n", f.name);

    void* mem = FUN_00263ea0(0x50);
    Skeleton_27c720* skel = 0;
    if (mem)
        skel = ((Skeleton_27c720*)mem)->FUN_0027bee0(nJoints, 0, 0);
    skel->name.FUN_0027b040(f.name);

    if (r->FUN_002669f0()) {
        f.w10 = 0;
        f.w14 = 0;
        int off8 = 0;
        do {
            r->FUN_00266a30();
            if (r->FUN_00266c30() == 0x4501) {
                r->stream->FUN_002647e0(&f.len, 1, 1, 1);
                unsigned int m = f.len;
                r->stream->FUN_002647e0(f.jointName, m, 1, 1);
                f.jointName[m] = 0;
                skel->hashes[off8 / 8] = FUN_002672f0(f.jointName, 0, 0);
                r->stream->FUN_002647e0(&f.w18, 1, 4, 1);
                *(unsigned short*)((char*)skel->parents + f.w10) = (unsigned short)f.w18;
                r->stream->FUN_002647e0(&f.w2c, 1, 4, 1);
                r->stream->FUN_002647e0(&f.w1c, 1, 4, 1);
                r->stream->FUN_002647e0(&f.w28, 1, 4, 1);
                r->stream->FUN_002647e0(&f.w20, 1, 4, 1);
                r->stream->FUN_002647e0(&f.w24, 1, 4, 1);
                r->stream->FUN_002647e0(skel->matrices + f.w14, 0x10, 4, 1);
                off8 += 8;
                f.w10 += 2;
                f.w14 += 0x40;
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }

    skel->FUN_0027b270();
    *out = skel;
    *outId = FUN_002672f0(f.name, 0, 0);
}
