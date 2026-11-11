// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00312d50..0x003137d0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f2588117 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f2588117 {} using namespace fn_f2588117;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f2588117 {
class Obj {
  public:
    char pad[0x2004];
    char flag;
    char gap[15];
    int a, b, c, d, e, f, g;
    Obj();
};
} // namespace fn_f2588117
void* __cdecl operator new(size_t);
namespace fn_f2588117 {
struct Elem_312db0 {
    char d[24];
    Elem_312db0() throw();
};
class BufMgr {
  public:
    char pad[0x2020];
    int cap;
    Elem_312db0* buf1;
    void* buf2;
    void* buf3;
    void Resize(int n);
};
struct Vec3_312fa0 { float x,y,z; };
struct Bounds_312fa0 {
 char pad[0x2004];
 unsigned char dirty;
 char pad2[3];
 Vec3_312fa0 inverse;
 Vec3_312fa0 maximum;
 void FUN_00312fa0(const Vec3_312fa0* value);
};
struct V3_3130a0 {
    float x, y, z;
};
struct V3Pair {
    V3_3130a0 a;
    V3_3130a0 b;
};
class Scaler_3130a0 {
public:
    char pad0[0x2008];
    V3_3130a0 scale;               // 0x2008
    void FUN_003130a0(V3Pair *pairs, int count);
};
struct Box_3132d0 {
    float minx, miny, minz;
    float maxx, maxy, maxz;
};
class HashGrid {
public:
    unsigned short table[0x1000];
    short* parent;
    void FUN_003132d0(Box_3132d0* boxes, int count);
};
} // namespace fn_f2588117
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *__cdecl memset(void *dst, int value, unsigned int n);
#endif
namespace fn_f2588117 {
struct Ids_313450 {
    short *table;                   // +0x2000 (relative to the owner)
    char enabled;                   // +0x2004
    char pad05[3];
};
class Table_313450 {
public:
    int FUN_00313450(int count);
    void FUN_003130a0(int a, int count);
    void FUN_003132d0(int a, int count);

    char slots[0x2000];
    Ids_313450 ids;                        // +0x2000
    char pad2008[0x2024 - 0x2008];
    int param;                      // +0x2024
    int limit;                      // +0x2028
    short *spare;                   // +0x202c
};
class SubCollisionDetector {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    int a, b, c, d;
    char pad[0x20];
    char x, y;
    int z;
    SubCollisionDetector();
};
extern void* hulk_at_004322f8;
struct Order { int largest; int middle; int smallest; };
struct Ranking {
    int best;
    int others[3];
};
extern "C" void __stdcall FUN_00313540(void *, float, float, float);


// 0x00312d50 FUN_00312d50 (53 B): matches/0x00312d50.cpp
// sym: ??0Obj@fn_f2588117@@QAE@XZ
Obj::Obj() {
    flag = 0;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    g = 0;
}


// 0x00312db0 FUN_00312db0 (141 B): matches/0x00312db0.cpp
// sym: ?Resize@BufMgr@fn_f2588117@@QAEXH@Z
void BufMgr::Resize(int n) {
    if (cap >= n)
        return;
    Elem_312db0* o = buf1;
    cap = n;
    operator delete(o);
    operator delete(buf2);
    operator delete(buf3);
    buf1 = new Elem_312db0[n];
    buf2 = operator new(n * 2);
    buf3 = operator new(n * 2);
}

} // namespace fn_f2588117

// 0x00312ed0 FUN_00312ed0 (200 B): equivalent/0x00312ed0.cpp
// sym: ?FUN_00312ed0@Groups_312ed0@owners@@QAEHHPAF@Z
// STATUS: equivalent (tools/equiv.py level 3: 44 inputs, branch coverage 16/16)
// FUN_00312ed0 @ 0x00312ed0
int owners::Groups_312ed0::FUN_00312ed0(int count, short* output) {
    unsigned int bytes = (unsigned int)count * 2;
    unsigned char* dest = (unsigned char*)output;
    for (unsigned int b=0; b<bytes; ++b) dest[b]=255;
    int groups=0;
    for(int i=0;i<count;++i) {
        short* p=parents;
        int root=i;
        int next=p[i];
        while(next!=root) { root=next; next=p[root]; }
        p[i]=(short)root;
        int representative=parents[i];
        if(representative!=i) {
            int label=output[representative];
            if(label==-1) { label=groups++; output[representative]=(short)label; }
            output[i]=(short)label;
        }
    }
    bytes=(unsigned int)groups*2;
    dest=(unsigned char*)parents;
    for(unsigned int b=0;b<bytes;++b) dest[b]=255;
    for(int i=0;i<count;++i) {
        int label=output[i];
        short previous=parents[label];
        output[i]=previous;
        parents[label]=(short)i;
    }
    return groups;
}

namespace fn_f2588117 {

// 0x00312fa0 FUN_00312fa0 (191 B): equivalent/0x00312fa0.cpp
// sym: ?FUN_00312fa0@Bounds_312fa0@fn_f2588117@@QAEXPBUVec3_312fa0@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 6/6)
// FUN_00312fa0 @ 0x00312fa0
void Bounds_312fa0::FUN_00312fa0(const Vec3_312fa0* value) {
 dirty = 1;
 if(value->x > maximum.x) maximum.x = value->x;
 if(value->y > maximum.y) maximum.y = value->y;
 if(value->z > maximum.z) maximum.z = value->z;
 volatile float halfY = 0.5f * maximum.y; // the original stores these two halves (rounded) in its frame
 volatile float halfZ = 0.5f * maximum.z;
 float resultZ = 1.0f / halfZ;
 inverse.x = 1.0f / (0.5f * maximum.x);
 inverse.z = resultZ;
 inverse.y = 1.0f / halfY;
}


// 0x003130a0 FUN_003130a0 (545 B): equivalent/0x003130a0.cpp
// sym: ?FUN_003130a0@Scaler_3130a0@fn_f2588117@@QAEXPAUV3Pair@2@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_003130a0 @ 0x003130a0
void Scaler_3130a0::FUN_003130a0(V3Pair *pairs, int count)
{
    for (int i = 0; i < count; ++i) {
        V3Pair *p = &pairs[i];
        float ax = p->a.x * scale.x;
        float ay = scale.y * p->a.y;
        float az = p->a.z * scale.z;
        p->a.z = az;
        p->a.x = ax;
        p->a.y = ay;

        float bx = scale.x * p->b.x;
        float by = p->b.y * scale.y;
        float bz = p->b.z * scale.z;
        p->b.z = bz;
        p->b.x = bx;
        p->b.y = by;
    }
}


// 0x003132d0 FUN_003132d0 (369 B): equivalent/0x003132d0.cpp
// sym: ?FUN_003132d0@HashGrid@fn_f2588117@@QAEXPAUBox_3132d0@2@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 26/26)
// FUN_003132d0 @ 0x003132d0
void HashGrid::FUN_003132d0(Box_3132d0* boxes, int count)
{
    for (int i = 0; i < count; i++) {
        Box_3132d0* b = &boxes[i];
        for (int x = (int)(__int64)b->minx; x <= (int)(__int64)b->maxx; x++) {
            for (int y = (int)(__int64)b->miny; y <= (int)(__int64)b->maxy; y++) {
                for (int z = (int)(__int64)b->minz; z <= (int)(__int64)b->maxz; z++) {
                    int h = (((z << 4) ^ y) << 4) ^ x;
                    int slot = (h ^ (h >> 12)) & 0xfff;
                    unsigned short entry = table[slot];
                    if (entry == 0xffff) {
                        table[slot] = (unsigned short)(__int64)i;
                    } else {
                        int other = (short)entry;
                        short* u = parent;
                        int ri = i;
                        for (int p = u[ri]; p != ri; p = u[ri])
                            ri = p;
                        u[i] = (short)(__int64)ri;
                        u = parent;
                        int ro = other;
                        for (int p = u[ro]; p != ro; p = u[ro])
                            ro = p;
                        u[other] = (short)(__int64)ro;
                        u = parent;
                        u[u[other]] = u[u[i]];
                    }
                }
            }
        }
    }
}


// 0x00313450 FUN_00313450 (125 B): matches/0x00313450.cpp
// sym: ?FUN_00313450@Table_313450@fn_f2588117@@QAEHH@Z
// FUN_00313450 @ 0x00313450
int Table_313450::FUN_00313450(int count) {
    if (count < 2) {
        return 0;
    }
    memset(this, -1, 0x2000);
    ids.table = spare;
    for (int i = 0; i < count; i++) {
        ids.table[i] = (short)i;
    }
    if (ids.enabled) {
        FUN_003130a0(param, count);
    }
    FUN_003132d0(param, count);
    return ((owners::Groups_312ed0 *)&ids)->FUN_00312ed0(count, (short *)(hulk_uintptr)(int)limit);
}


// 0x00313500 FUN_00313500 (36 B): matches/0x00313500.cpp
// sym: ??0SubCollisionDetector@fn_f2588117@@QAE@XZ
SubCollisionDetector::SubCollisionDetector() : a(0), b(0), c(0), d(0), x(0), y(0), z(3) {}


// 0x00313530 FUN_00313530 (7 B): matches/0x00313530.cpp
// sym: @FUN_00313530@4
// Same code shape as 0x001b6820 (propagated; names are from that function)
extern "C" void __fastcall FUN_00313530(void* self) {
    *(void**)self = &hulk_at_004322f8;
}


// 0x00313540 FUN_00313540 (260 B): equivalent/0x00313540.cpp
// sym: _FUN_00313540@16
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 27/28, incomplete)
// FUN_00313540 @ 0x00313540
extern "C" void __stdcall FUN_00313540(void * out, float a, float b, float c)
{
    if (a == b && a == c) {
        ((Order *)out)->largest = 0;
        ((Order *)out)->middle = 1;
        ((Order *)out)->smallest = 2;
        return;
    }
    int largest;
    if (a >= b && a >= c) largest = 0;
    else if (b >= c && b >= a) largest = 1;
    else largest = 2;
    ((Order *)out)->largest = largest;
    int smallest;
    if (a < b && a < c) smallest = 0;
    else if (b < c && b < a) smallest = 1;
    else smallest = 2;
    ((Order *)out)->smallest = smallest;
    if (largest != 0 && smallest != 0) ((Order *)out)->middle = 0;
    else if (largest != 1 && smallest != 1) ((Order *)out)->middle = 1;
    else ((Order *)out)->middle = 2;
}


// 0x00313650 FUN_00313650 (362 B): equivalent/0x00313650.cpp
// sym: ?FUN_00313650@fn_f2588117@@YGXPAURanking@1@PBM@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 32/32)
// FUN_00313650 @ 0x00313650
void __stdcall FUN_00313650(Ranking *out, const float *v)
{
    if (v[0] >= v[1] && v[0] >= v[2] && v[0] >= v[3]) {
        out->best = 0;
        FUN_00313540((int *)(out->others), v[1], v[2], v[3]);
        out->others[0] = out->others[0] + 1;
        out->others[1] = out->others[1] + 1;
        out->others[2] = out->others[2] + 1;
    } else if (v[1] >= v[0] && v[1] >= v[2] && v[1] >= v[3]) {
        out->best = 1;
        FUN_00313540((int *)(out->others), v[0], v[2], v[3]);
        for (int i = 0; i < 3; i++) {
            if (out->others[i] > 0) out->others[i]++;
        }
    } else if (v[2] >= v[0] && v[2] >= v[1] && v[2] >= v[3]) {
        out->best = 2;
        FUN_00313540((int *)(out->others), v[0], v[1], v[3]);
        for (int i = 0; i < 3; i++) {
            if (out->others[i] > 1) out->others[i]++;
        }
    } else {
        out->best = 3;
        FUN_00313540((int *)(out->others), v[0], v[1], v[2]);
        for (int i = 0; i < 3; i++) {
            if (out->others[i] > 2) out->others[i]++;
        }
    }
}

} // namespace fn_f2588117
