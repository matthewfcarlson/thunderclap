// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001aedb0..0x001b3020 (kind game, layer game, confidence high), dominant class AICollisionSolverAgent
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7cf5713 {
#define TREE_TU_END }
namespace fn_f7cf5713 {} using namespace fn_f7cf5713;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f7cf5713 {
struct Rec {
    int id, idx;
    float x, y, z;
    Rec* parent;
    float g, h;
    char closed;
    char pad21[3];
    int last;
    void FUN_001ad2b0(Ctx* d);
};
struct ANode {
    char hdr[0x10];
    Rec rec;
};
struct Map;
struct BNode {
    char hdr[0x10];
    ANode* an;
    Map* map;
};
struct Map {
    char pad0[0x14];
    int size;
    BNode* FUN_00230ea0();
    void FUN_00230de0(void* node);
    void* FUN_00230ba0(void* cmp, void* key);
    void* FUN_00230be0(void* cmp, void* key);
    void FUN_00230c30(void* node, void* cmp, void* parent);
};
struct Iter {
    int tile, cur, idx, flag;
    void FUN_001ad7d0(Ctx* d);
};
extern "C" int __cdecl FUN_001ad4d0(void*, void*);
extern "C" int __cdecl FUN_001ad4f0(void*, void*);
extern "C" int __cdecl FUN_001aea70(void*, void*);
extern "C" int __cdecl FUN_001aeae0(void*, void*);
char __cdecl FUN_001ad730(int tile, Ctx* d);
extern "C" void* FUN_0008d6d0(unsigned int size);
void thunk_FUN_00267090(void* p);
struct SearchState {
    float candidateCost;
    Map* savedMap;
    int processed;
    ANode* candidateNode;
    Map* candidateMap;
    ANode* currentNode;
    hulk_intptr currentMapValue;
    void* openEntry;
    Map* savedOpenMap;
    Iter neighbors;
    Iter start;
    int startExtra;
    Rec candidate;
};
struct Pair_1af150 {
    union {
        int first;
        float value;
    };
    int second;
};
struct Key_1af150 {
    int w[10];
};
struct Node {
  public:
    unsigned int x;
    unsigned int y;
    unsigned int z;
    void* group;
    unsigned int index;
    char _m_pad_14[0x4];
    float value;
    char _m_pad_1c[0x8];
    int id;
};
struct Map_1af150 {
    int link[6];
    void FUN_00230f50(void (*fn)(void *, void *), void *param);
    Pair_1af150 *FUN_001ae9e0(Pair_1af150 *out, const Key_1af150 *key);
    Pair_1af150 *FUN_001aecb0(Pair_1af150 *out, const Pair_1af150 *key);
};
struct Frame_1af150 {
    Pair_1af150 pair1;      // 0x00
    Map_1af150 mapB;        // 0x08
    int gap1;        // 0x20
    Map_1af150 mapA;        // 0x24
    int gap2;        // 0x3c
    Key_1af150 k;           // 0x40
    int z28;         // 0x68
    int z2c;         // 0x6c
    int z30;         // 0x70
    int u34;         // 0x74
    int gap3;        // 0x78
    Pair_1af150 pair2;      // 0x7c
};
extern "C" void FUN_001ad560(void *node, void *param);
extern "C" void FUN_001ad550(void *node, void *param);
extern "C" void * __cdecl FUN_001aedb0(void *, void *, void *, void *, int *);
extern "C" char FUN_001ad5c0(Owner *o, Node *n);
struct Vec3_1af2b0 {
    float x, y, z;
};
struct Elem_1af2b0 {
    int id;
    int idx;
    Vec3_1af2b0 pos;
};
struct ElemVec_1af2b0 {
    Elem_1af2b0 *begin;
    Elem_1af2b0 *end;
    Elem_1af2b0 *cap;
};
struct Rec_1af2b0 {
    int ids[3];
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
};
struct Reg_1af2b0 {
    Rec_1af2b0 *FUN_001b57a0(int id);
};
struct Info_1af2b0 {
    Vec3_1af2b0 v;
    Reg_1af2b0 *reg;
    int id;
};
struct Out_1af2b0 {
    int first;
    ElemVec_1af2b0 vec;
    int pad10;
    Reg_1af2b0 *reg;
};
struct Query_1af2b0 {
    Reg_1af2b0 *reg;
    unsigned want;
    unsigned alpha;
    unsigned extra;
};
struct Target_1af2b0 {
    Vec3_1af2b0 pos;
    char pad[4];
    int id;
};
struct Frame_1af2b0 {
    Vec3_1af2b0 tmp;
    Query_1af2b0 q;
    Elem_1af2b0 x1;
    Elem_1af2b0 x2;
};
struct Owner_1af2b0 {
    int pad0;
    int f4;
    hulk_freg FUN_001af2b0(Info_1af2b0 *info, Target_1af2b0 *pos, float scale, float alpha, Out_1af2b0 *out, unsigned a6, unsigned a7);
};
extern "C" Vec3_1af2b0 *__cdecl FUN_001acdd0(Vec3_1af2b0 *out, Reg_1af2b0 *reg, int id);
float __cdecl FUN_001af150(ElemVec_1af2b0 *vec, Elem_1af2b0 *b, Elem_1af2b0 *a, Query_1af2b0 *q, unsigned a6);
struct Point_1af540 { unsigned int x,y,z; };
struct Collection_1af540 { unsigned int reserved; char* begin; char* end; };
extern "C" bool __cdecl FUN_001ae3f0(Node*,Collection_1af540*);
struct Host_1af540 {
 hulk_freg FUN_001af2b0(Node*,Node*,void*,void*,Collection_1af540*,void*,void*);
 bool FUN_001af540(Node*,Node*,void*,void*,Collection_1af540*,Point_1af540*,void*,void*,void*);
};
struct Vec_1af650 { unsigned x,y,z; };
struct Query_1af650 { void FUN_001b6000(Vec_1af650*, unsigned*, int*); };
} // namespace fn_f7cf5713
struct World { char pad[16]; Query_1af650* query; };
namespace fn_f7cf5713 {
struct ArgSlots_1af650 { int index; unsigned status; };
struct Frame_1af650 {
 Vec_1af650 first; unsigned firstExtra; int firstId;
 Vec_1af650 second; unsigned secondExtra; int secondId;
};
struct Vec3_1af770 {
    float x, y, z;
};
struct Vec6 {
    Vec3_1af770 a, b;
};
struct Job_1af770 {
    unsigned char kind;
    unsigned char started;
    char pad02[2];
    Vec3_1af770 f04;
    Vec3_1af770 f10;
    Vec3_1af770 f1c;
    int f28;
    int f2c;
    Vec6 f30;
    Vec3_1af770 f48;
    int f54;
    int result;
    int f5c;
};
class JobQueue {
  public:
    char pad00[0x18];
    Job_1af770** head;
    Job_1af770** tail;
    Job_1af770** begin;
    Job_1af770** end;
    int FUN_001af650(Vec3_1af770* a, Vec3_1af770* b, Vec3_1af770* c, int d, int e, Vec6* f, Vec3_1af770* g, int* h, int i);
    void FUN_001af770();
};
struct V {
    float x, y, z;
};
struct M_1af890 {
    char pad[8];
    V* items;
};
struct S_1af890 {
};
struct T_1af890 {
    char p0[0x44];
    M_1af890* mgr;
    char p1[4];
    S_1af890 sub;
    char p2[0x7f];
    char flag;
    V Get(unsigned short i);
};
class Obj_1afa60 {
  public:
    char pad[0x3a];
    char value;
    char Get();
};
} // namespace fn_f7cf5713
extern "C" __int64 __cdecl FUN_0027b020(float);
namespace fn_f7cf5713 {
struct Obj_1afb80 {
    char pad[12];
    int type;
};
struct Callee_1afb80 {
    void Fnf_0003aaf0(Obj_1afb80*);
};
struct Host_1afb80 {
    char pad[8];
    Callee_1afb80* sub;
};
struct Candidate_1afdc0;
struct Owner_1afdc0;
struct Group_1afdc0 {
    char pad[0x1b0];
    unsigned id;
};
struct Link_1afdc0 {
};
struct Entity {
    char p0[0x114];
    unsigned identity;
    char p118[4];
    Group_1afdc0* group;
    char p120[8];
    Link_1afdc0* link;
    unsigned relatedIdentity;
    char p130[0x18];
    Entity* parent;
    char p14c[0x1e8];
    Entity* related;
    void FUN_001d82d0();
};
struct Candidate_1afdc0 {
    char p0[8];
    Entity* entity;
    unsigned type;
};
struct Owner_1afdc0 {
    float FUN_00015a20();
    Entity* FUN_00015a30();
    void FUN_00015a40(Candidate_1afdc0*, unsigned, unsigned);
};
struct Context {
    char pad[8];
    Owner_1afdc0* owner;
};
class Inner_1afe70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual int f6(int, int, int, int, int);
};
struct Holder_1afe70 {
    char pad[8];
    Inner_1afe70* p;
};
struct Owner_1b0180 {
    char pad[0x148];
    void* mLink;
};
struct Obj_1b0180 {
    char pad[8];
    Owner_1b0180* mOwner;
    int mType;
};
struct Handle_1b0180 {
    char pad[0x18];
    Obj_1b0180* mObj;
};
struct Detail { char pad[0x14]; int value; };
struct Object {
  public:
    char _m_pad_0[0x11c];
    Detail* detail;
    bool FUN_001af540(Vec_1af650*,Vec_1af650*,unsigned,unsigned,unsigned,Vec_1af650*,unsigned*,int*,unsigned);
    unsigned FUN_001ae450(unsigned,Vec_1af650*,unsigned,int);
    unsigned target(Vec_1af650* start,Vec_1af650* end,unsigned* value,unsigned a4,unsigned a5,unsigned a6,Vec_1af650* output,unsigned a8,unsigned a9);
};
extern "C" int __cdecl FUN_00044500(int);
extern void* hulk_at_0041d830[];
class CollisionSolverAgent_1b02e0 {
  public:
    void Destroy_002f8820(); // FUN_00236d60, __thiscall, this in ecx
};
class AICollisionSolverAgent_1b02e0 : public CollisionSolverAgent_1b02e0 {
  public:
    AICollisionSolverAgent_1b02e0* vfunc_5(signed char flags);
};
} // namespace fn_f7cf5713
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int atexit(void (*)());
#endif
namespace fn_f7cf5713 {
struct Key_1b0310 {
    unsigned lo;
    unsigned hi;
    void FUN_0027af00();
};
extern "C" void FUN_00363fd0();
bool FUN_00044500(void *p);
struct Inner_1b0310 {
    char pad0[0x14];
    void *f14;
};
struct Attacker_1b0310 {
    char pad0[0x11c];
    Inner_1b0310 *f11c;
};
struct Victim {
    char pad0[0x230];
    float f230;
    int FUN_001d64a0();
};
struct V3_1b1080 {
    float x, y, z;
};
struct Mover_1b1080 {
};
struct Core_1b1080 {
    unsigned __int64 FUN_001d4f70();
};
extern "C" float __cdecl FUN_000186b0(float *value, float *lo, float *hi);
struct Slots_1b1080 {
    float hi;
    float lo;
    float d;
};
struct Obj_1b1080 {
    char pad0[0xe8];
    char clampFlag;
    char pade9[3];
    Core_1b1080 *core;
    char padf0[0x148 - 0xf0];
    int blocked;
    float FUN_001d8160();
};
class Item {
  public:
    char Valid_001d7300();
    int Value_001d64a0();
};
class Owner {
  public:
    char Do_001b0260(int, int);
    char Run(hulk_intptr x, Item* p);
};
class Function_1b1640 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Function_1b16b0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};


// 0x001aedb0 FUN_001aedb0 (913 B): equivalent/0x001aedb0.cpp
// sym: _FUN_001aedb0 @f29d6cd4ddd7 @w3573d9ce50b8
// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 33/34, incomplete)
// FUN_001aedb0 @ 0x001aedb0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
extern "C" void * FUN_001aedb0(void * visited, void * open_, void * goal, void * context, int* result) {
    Map * open = (Map *)open_;
    SearchState state;
    BNode* front = open->FUN_00230ea0();
    if (front->an->rec.id == ((Rec *)goal)->id)
        return (Rec *)(&open->FUN_00230ea0()->an->rec);

    front = open->FUN_00230ea0();
    state.start.tile = front->an->rec.id;
    state.start.idx = -1;
    state.start.flag = (unsigned char)FUN_001ad730(state.start.tile, ((Ctx *)context));
    state.start.FUN_001ad7d0(((Ctx *)context));
    if (!open->size)
        return (Rec *)0;

    state.processed = 0;
    for (;;) {
        if (state.processed++ == 0x80)
            return (Rec *)0;

        BNode* front = open->FUN_00230ea0();
        state.currentNode = front->an;
        state.currentMapValue = (hulk_intptr)front->map;
        front = open->FUN_00230ea0();
        state.savedMap = open;
        open->FUN_00230de0(front);
        thunk_FUN_00267090(front);

        state.neighbors.tile = state.currentNode->rec.id;
        state.neighbors.idx = -1;
        state.neighbors.flag = (unsigned char)FUN_001ad730(state.neighbors.tile, ((Ctx *)context));
        state.neighbors.FUN_001ad7d0(((Ctx *)context));
        while (state.neighbors.idx != -1) {
            state.candidate.id = state.neighbors.cur;
            *(int*)&state.candidate.x = state.start.idx;
            *(int*)&state.candidate.y = state.start.flag;
            *(int*)&state.candidate.z = state.startExtra;
            state.candidate.parent = 0;
            state.candidate.g = 0;
            state.candidate.h = 0;
            state.candidate.last = 0;
            state.candidate.idx = state.neighbors.idx;
            *(int*)&state.candidate.closed = 0;

            bool newlyCreated = true;
            void* insertionPoint = ((Map *)visited)->FUN_00230be0((void*)FUN_001ad4f0, &state.candidate);
            ANode* allocated = 0;
            if (insertionPoint) {
                allocated = (ANode*)FUN_0008d6d0((int)sizeof(ANode));
                if (allocated)
                    allocated->rec = state.candidate;
                ((Map *)visited)->FUN_00230c30(allocated, (void*)FUN_001ad4d0, insertionPoint);
                state.candidateNode = allocated;
                state.candidateMap = ((Map *)visited);
            } else {
                state.candidateNode = 0;
                state.candidateMap = 0;
            }
            if (allocated) {
                allocated->rec.FUN_001ad2b0(((Ctx *)context));
            } else {
                state.candidateNode = (ANode*)((Map *)visited)->FUN_00230ba0((void*)FUN_001ad4f0, &state.candidate);
                state.candidateMap = ((Map *)visited);
                newlyCreated = false;
            }

            ANode* candidate = state.candidateNode;
            Rec* next = &candidate->rec;
            Rec* current = &state.currentNode->rec;
            double dx = current->x - next->x;
            double dy = current->y - next->y;
            double dz = current->z - next->z;
            state.candidateCost = (float)(sqrt(dz * dz + dy * dy + dx * dx) + current->g);
            if (newlyCreated || state.candidateCost < next->g) {
                next->idx = state.candidate.idx;
                if (!newlyCreated && !next->closed) {
                    state.openEntry = open->FUN_00230ba0((void*)FUN_001aeae0, &state.candidateNode);
                    if (state.openEntry) {
                        open->FUN_00230de0(state.openEntry);
                        thunk_FUN_00267090(state.openEntry);
                    }
                }
                next->g = state.candidateCost;
                next->parent = current;
                double ex = next->x - ((Rec *)goal)->x;
                double ey = next->y - ((Rec *)goal)->y;
                double ez = next->z - ((Rec *)goal)->z;
                next->h = (float)(sqrt(ez * ez + ey * ey + ex * ex) * 1.5f + state.candidateCost);
                if (next->id == ((Rec *)goal)->id) {
                    *result = state.start.idx;
                    state.candidateNode->rec.last = state.start.idx;
                    return (Rec *)(&state.candidateNode->rec);
                }
                void* position = open->FUN_00230be0((void*)FUN_001aeae0, &state.candidateNode);
                if (position) {
                    BNode* entry = (BNode*)FUN_0008d6d0((int)sizeof(BNode));
                    if (entry) {
                        entry->an = state.candidateNode;
                        entry->map = state.candidateMap;
                    }
                    open->FUN_00230c30(entry, (void*)FUN_001aea70, position);
                }
                next->closed = 0;
            }
            state.neighbors.FUN_001ad7d0(((Ctx *)context));
        }
        state.currentNode->rec.closed = 1;
        if (!open->size)
            return (Rec *)0;
    }
}


// 0x001af150 FUN_001af150 (347 B): equivalent/0x001af150.cpp
// sym: ?FUN_001af150@fn_f7cf5713@@YAMPAVOwner@1@PBHHHPAH@Z @f95221df5a8b @wf11004da24b9
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 4/4)
// FUN_001af150 @ 0x001af150
float FUN_001af150(Owner *o, const int *in, int c, int d, int *outId)
{
    Frame_1af150 f;
    ((owners::X_230b60 *)&(f.mapA))->FUN_00230b60();
    ((owners::X_230b60 *)&(f.mapB))->FUN_00230b60();
    f.k.w[0] = in[0];
    f.k.w[1] = in[1];
    f.k.w[2] = in[2];
    f.k.w[3] = in[3];
    f.k.w[4] = in[4];
    f.k.w[5] = 0;
    f.k.w[6] = 0;
    f.k.w[7] = 0;
    f.z2c = 0;
    f.z30 = 0;
    f.k.w[8] = f.u34;
    f.k.w[9] = -1;
    Pair_1af150 *p = f.mapA.FUN_001ae9e0(&f.pair1, &f.k);
    f.mapB.FUN_001aecb0(&f.pair2, p);
    f.pair1.first = -1;
    Node *n = ((Node *)FUN_001aedb0((Map_1af150 *)(&f.mapA), (Map_1af150 *)(&f.mapB), (void *)(hulk_uintptr)(int)c, (void *)(hulk_uintptr)(int)d, (int *)(Pair_1af150 *)(&f.pair1)));
    if (n == 0) {
        f.mapB.FUN_00230f50(FUN_001ad560, &f.mapB);
        f.mapA.FUN_00230f50(FUN_001ad550, &f.mapA);
        return 0.0f;
    }
    *outId = n->id;
    if (!FUN_001ad5c0(o, n)) {
        f.mapB.FUN_00230f50(FUN_001ad560, &f.mapB);
        f.mapA.FUN_00230f50(FUN_001ad550, &f.mapA);
        return 0.0f;
    }
    f.pair1.value = n->value;
    f.mapB.FUN_00230f50(FUN_001ad560, &f.mapB);
    f.mapA.FUN_00230f50(FUN_001ad550, &f.mapA);
    return f.pair1.value;
}


// 0x001af2b0 FUN_001af2b0 (656 B): equivalent/0x001af2b0.cpp
// sym: ?FUN_001af2b0@Owner_1af2b0@fn_f7cf5713@@QAEMPAUInfo_1af2b0@2@PAUTarget_1af2b0@2@MMPAUOut_1af2b0@2@II@Z @92f68b66c8f8 @w03001a9ea364
// STATUS: equivalent (tools/equiv.py level 3: 18162 inputs, branch coverage 26/26)
// FUN_001af2b0 @ 0x001af2b0
hulk_freg Owner_1af2b0::FUN_001af2b0(Info_1af2b0 *info, Target_1af2b0 *pos, float scale, float alpha, Out_1af2b0 *out, unsigned a6, unsigned a7)
{
    Frame_1af2b0 fr;
    unsigned want = (unsigned)(int)(scale * 0.7f * 32.0f);
    out->reg = info->reg;
    out->first = f4;

    Rec_1af2b0 *rec = info->reg->FUN_001b57a0(info->id);
    if (!rec)
        return 1.0f;

    int best = 0;
    unsigned top = 0;
    if (rec->b0 > 0)
        top = rec->b0;
    if (rec->b1 > top) {
        best = 1;
        top = rec->b1;
    }
    if (rec->b2 > top) {
        best = 2;
        top = rec->b2;
    }

    if (top < want) {
        out->reg = info->reg;
        out->vec.end = out->vec.begin;
        int id = rec->ids[best];
        if (id != -1) {
            Vec3_1af2b0 *p = FUN_001acdd0(&fr.tmp, info->reg, id);
            Vec3_1af2b0 v = *p;
            if (out->vec.end < out->vec.cap) {
                Elem_1af2b0 *e = out->vec.end;
                out->vec.end = e + 1;
                if (e) {
                    e->id = id;
                    e->idx = best;
                    e->pos = v;
                }
            }
            int id2 = info->id;
            Vec3_1af2b0 *p2 = FUN_001acdd0(&fr.tmp, info->reg, id2);
            Vec3_1af2b0 v2 = *p2;
            if (out->vec.end < out->vec.cap) {
                Elem_1af2b0 *e = out->vec.end;
                out->vec.end = e + 1;
                if (e) {
                    e->id = id2;
                    e->idx = -1;
                    e->pos = v2;
                }
            }
        }
        return 1.0f;
    }

    fr.q.reg = info->reg;
    fr.q.want = want;
    fr.q.alpha = (unsigned)(int)(alpha * 255.0f);
    fr.q.extra = a7;
    fr.x1.id = pos->id;
    fr.x1.idx = -1;
    fr.x1.pos.x = pos->pos.x * 3.0f;
    fr.x1.pos.y = pos->pos.y * 3.0f;
    fr.x1.pos.z = pos->pos.z * 3.0f;
    fr.x2.id = info->id;
    fr.x2.idx = -1;
    fr.x2.pos.x = info->v.x * 3.0f;
    fr.x2.pos.y = info->v.y * 3.0f;
    fr.x2.pos.z = info->v.z * 3.0f;
    float r = FUN_001af150(&out->vec, &fr.x2, &fr.x1, &fr.q, a6);
    if (r == 0.0f)
        return r;
    Elem_1af2b0 *e = out->vec.begin;
    if (e != out->vec.end) {
        do {
            e->pos.x = e->pos.x * 0.333333343f;
            e->pos.y = e->pos.y * 0.333333343f;
            e->pos.z = e->pos.z * 0.333333343f;
            e++;
        } while (e != out->vec.end);
    }
    Elem_1af2b0 *b = out->vec.begin;
    b->pos = pos->pos;
    return r;
}


// 0x001af540 FUN_001af540 (269 B): equivalent/0x001af540.cpp
// sym: ?FUN_001af540@Host_1af540@fn_f7cf5713@@QAE_NPAUNode@2@0PAX1PAUCollection_1af540@2@PAUPoint_1af540@2@111@Z @6a70fb61b326 @w3b2e3fd73832
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 16/16)
// FUN_001af540 @ 0x001af540
bool Host_1af540::FUN_001af540(Node* a, Node* b, void* c, void* d, Collection_1af540* list, Point_1af540* output, void* unused, void* h, void* i) {
 if (a->group && b->group) {
  if(a->group != b->group) { output->x=a->x; output->y=a->y; output->z=a->z; return false; }
  if(a->index != b->index) {
   float result=FUN_001af2b0(a,b,c,d,list,h,i);
   if(result==0.0f) {
    if(FUN_001ae3f0(a,list)) return true;
    output->x=a->x; output->y=a->y; output->z=a->z; return false;
   }
   if((unsigned int)((int)(list->end-list->begin)/20)>=2) return true;
   list->end=list->begin; return false;
  }
 } else { if(FUN_001ae3f0(a,list)) return true; }
 output->x=b->x; output->y=b->y; output->z=b->z; return false;
}


// 0x001af650 FUN_001af650 (280 B): equivalent/0x001af650.cpp
// sym: ?target@Object@fn_f7cf5713@@QAEIPAUVec_1af650@2@0PAIIII0II@Z @87e77635296d @w363714f334f2
// STATUS: equivalent (tools/equiv.py level 3: 6665 inputs, branch coverage 4/4)
// FUN_001af650 @ 0x001af650
unsigned Object::target(Vec_1af650* start,Vec_1af650* end,unsigned* value,unsigned a4,unsigned a5,unsigned a6,Vec_1af650* output,unsigned a8,unsigned a9) {
 Frame_1af650 f;
 Vec_1af650* from=start;
 f.first=*start;
 f.firstExtra=0; f.firstId=-1;
 DAT_004dd700->query->FUN_001b6000(&f.first,&f.firstExtra,&f.firstId);
 f.second=*end;
 f.secondExtra=0; f.secondId=-1;
 DAT_004dd700->query->FUN_001b6000(&f.second,&f.secondExtra,&f.secondId);
 // The found index and the status live in the dead start/end argument slots; the callee
 // gets a pointer to them.
 ArgSlots_1af650* slots=(ArgSlots_1af650*)&start;
 slots->status=2;
 if(f.firstId==-1) return slots->status;
 slots->index=-1;
 if(FUN_001af540(&f.first,&f.second,*value,a4,a6,output,&a6,&slots->index,a9))
   return FUN_001ae450(a6,output,0,slots->index);
 output->x=from->x; output->y=from->y; output->z=from->z;
 return slots->status;
}


// 0x001af770 FUN_001af770 (247 B): equivalent/0x001af770.cpp
// sym: ?FUN_001af770@JobQueue@fn_f7cf5713@@QAEXXZ @7fd743928fcf @wabc5e084ba76
// STATUS: equivalent (tools/equiv.py level 3: 63 inputs, branch coverage 22/22)
// FUN_001af770 @ 0x001af770
void JobQueue::FUN_001af770() {
    hulk_intptr count;
    if (head > tail)
        count = (tail - begin) + (end - head);
    else
        count = tail - head;
    bool started = false;
    for (int i = 0; i < count; i++) {
        if (started)
            break;
        Job_1af770* job = *head;
        if (!(tail < end))
            tail = head;
        head = head + 1;
        if (head == end)
            head = begin;
        if (job->kind == 1) {
            job->started = 1;
            job->result = FUN_001af650(&job->f04, &job->f10, &job->f1c, job->f28, job->f2c, &job->f30, &job->f48, &job->f54, job->f5c);
            started = true;
        }
        if (tail < end) {
            if (tail)
                *tail = job;
            tail = tail + 1;
            if (tail == end)
                tail = begin;
            if (head == tail)
                tail = tail + (end - begin);
        }
    }
}


// 0x001af890 FUN_001af890 (121 B): matches/0x001af890.cpp
// sym: ?Get@T_1af890@fn_f7cf5713@@QAE?AUV@2@G@Z
V T_1af890::Get(unsigned short i) {
    if (flag) {
        V t;
        ((owners::Mat_22c2b0 *)&sub)->FUN_0022c2b0((float *)(V *)(&mgr->items[i]), (float *)(V *)(&t));
        return t;
    }
    return mgr->items[i];
}


// 0x001afa60 FUN_001afa60 (4 B): matches/0x001afa60.cpp
// sym: ?Get@Obj_1afa60@fn_f7cf5713@@QAEDXZ
char Obj_1afa60::Get() {
    return value;
}


// 0x001afa70 FUN_001afa70 (20 B): matches/0x001afa70.cpp
// sym: ?FUN_001afa70@fn_f7cf5713@@YAXHH@Z
// data: gA_1afa70 = DAT_004c3704, gB_1afa70 = DAT_004c3700
void __cdecl FUN_001afa70(int a, int b) {
    (*(int*)&DAT_004c3704) = b;
    (*(int*)&DAT_004c3700) = a;
}


// 0x001afa90 FUN_001afa90 (20 B): matches/0x001afa90.cpp
// sym: _FUN_001afa90
// data: g1_1afa90 = DAT_004c3708, g2_1afa90 = DAT_004c370c
extern "C" void FUN_001afa90(float a, float b) {
    DAT_004c370c = b;
    DAT_004c3708 = a;
}


// 0x001afab0 FUN_001afab0 (20 B): matches/0x001afab0.cpp
// sym: _FUN_001afab0
// data: hulk_at_004c3710 = DAT_004c3710, hulk_at_004c3714 = DAT_004c3714
extern "C" void __cdecl FUN_001afab0(int b, int a) {
    *(__int32*)((hulk_intptr)((char*)&DAT_004c3714)) = a;
    *(__int32*)((hulk_intptr)((char*)&DAT_004c3710)) = b;
}


// 0x001afad0 FUN_001afad0 (35 B): matches/0x001afad0.cpp
// sym: ?FUN_001afad0@fn_f7cf5713@@YAXMM@Z
// data: gRate = DAT_004c3740, gTime = DAT_004e1810
void __cdecl FUN_001afad0(float a, float b) {
    (*(__int64*)&DAT_004e1810) = FUN_0027b020(a);
    (*(float*)&DAT_004c3740) = b;
}

} // namespace fn_f7cf5713

// 0x001afb00 FUN_001afb00 (80 B): equivalent/0x001afb00.cpp
// sym: ?FUN_001afb00@Obj_1afb00@owners@@QAEMXZ @e9bc92d8f2c8 @wd3176a297025
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 12/12)
// FUN_001afb00 @ 0x001afb00
float owners::Obj_1afb00::FUN_001afb00() { if (value < (*(float*)&DAT_003f32e0)) { switch (FUN_001d64a0()) { case 0: return DAT_004c3728; case 2: case 6: return DAT_004c371c; case 3: case 7: return DAT_004c3720; case 4: return DAT_004c3724; case 5: return DAT_004c3718; default: return (*(float*)&DAT_003f32e0); } } return value; }

namespace fn_f7cf5713 {

// 0x001afb80 FUN_001afb80 (31 B): matches/0x001afb80.cpp
// sym: ?target@fn_f7cf5713@@YGHPAUHost_1afb80@1@PAUObj_1afb80@1@@Z
int __stdcall target(Host_1afb80* a, Obj_1afb80* b) {
    if (b->type == 5)
        a->sub->Fnf_0003aaf0(b);
    return 1;
}

} // namespace fn_f7cf5713

// 0x001afba0 FUN_001afba0 (543 B): equivalent/0x001afba0.cpp [wrapped: conflict: World]
// sym: ?FUN_001afba0@fn_001afba0@@YGHPAUController_1afba0@1@PAUHit_1afba0@1@HHM@Z @1c5385709714 @w58d9af4cf15c
namespace fn_001afba0 {
// STATUS: equivalent (tools/equiv.py level 3: 3055 inputs, branch coverage 42/42)
// FUN_001afba0 @ 0x001afba0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Vec3_1afba0 {
    float x, y, z;
};

struct Probe_1afba0 {
    hulk_freg FUN_000111f0();
};

struct Stats_1afba0 {
    char pad0[0x3a];
    char flag3a;
    char pad3b[0xb8 - 0x3b];
    float f_b8;
    Probe_1afba0 *FUN_00012f50(Vec3_1afba0 *out);
};

struct Region_1afba0 {
    char pad0[0x1b0];
    int id;
};

struct Anchor_1afba0 {
    char pad0[0x1b0];
    int id;
};

struct Holder_1afba0 {
    char pad0[0x11c];
    Anchor_1afba0 *anchor;
    char pad120[0x1b88 - 0x120];
    float stamp;
};

struct Gadget_1afba0 {
    char FUN_001d4e30();
};

struct Hit_1afba0;

struct Target_1afba0 {
    char pad0[8];
    int f8;
    char pad0c[0xec - 0xc];
    Gadget_1afba0 *gadget;
    char pad0f0[0x114 - 0xf0];
    int f114;
    char pad118[0x148 - 0x118];
    Holder_1afba0 *holder;
    char pad14c;
    char f14d;
    char pad14e[0x1c9 - 0x14e];
    char f1c9;
    char FUN_001d6a80();
    void FUN_001d82d0();
    void FUN_001d74c0(int a, int b, float c, int d);
    void FUN_001d7510();
};

struct Hit_1afba0 {
    char pad0[8];
    Target_1afba0 *target;
    int type;
    char pad10[0x6c - 0x10];
    int f6c;
};

struct Fx_1afba0 {
    void FUN_00083320(int a, int b, float t, int one, Probe_1afba0 *p, int zero);
};

struct Sys4c {
};

struct Clock_1afba0 {
    float FUN_00086080();
};

struct Cue_1afba0 {
    void FUN_001ec980(int id, const char *name);
};

struct Slot20_1afba0 {
    char pad0[0x124];
    int id;
};

struct World {
    char pad0[0x20];
    Slot20_1afba0 *slot20;
    char pad24[0x34 - 0x24];
    Cue_1afba0 *cue;
    char pad38[0x4c - 0x38];
    Sys4c *sys;
    char pad50[0x58 - 0x50];
    Clock_1afba0 *clock;
};


struct Body_1afba0 {
    char pad0[0x11c];
    Anchor_1afba0 *anchor;
    char pad120[0x128 - 0x120];
    Target_1afba0 *owner;
    int f12c;
    char pad130[0x334 - 0x130];
    Body_1afba0 *other;
};

struct Fighter_1afba0 {
    char pad0[0x20];
    Stats_1afba0 *stats;
    float FUN_00014580();
    Body_1afba0 *FUN_00013ec0();
    void FUN_0001a710(Hit_1afba0 *hit, int a, int b);
};

struct Controller_1afba0 {
    char pad0[8];
    Fighter_1afba0 *fighter;
};

int __stdcall FUN_001afba0(Controller_1afba0 *ctl, Hit_1afba0 *hit, int a, int b, float t)
{
    Vec3_1afba0 tmp;

    if (hit->type != 5)
        return 1;

    Fighter_1afba0 *f = ctl->fighter;
    if (f->FUN_00014580() < t)
        return 1;

    Body_1afba0 *body = f->FUN_00013ec0();
    if (body->owner != 0) {
        if (((Hit_1afba0 *)((owners::C_1d72e0 *)(body->owner))->FUN_001d72e0()) == hit)
            return 1;
    }

    Target_1afba0 *tgt = hit->target;
    Holder_1afba0 *h = tgt->holder;
    if (h != 0) {
        if (DAT_004dd700 != 0)
            h->stamp = DAT_004dd700->clock->FUN_00086080();
        if (body->anchor->id == tgt->holder->anchor->id)
            return 1;
    }

    if (f->stats->flag3a) {
        if (tgt->gadget->FUN_001d4e30())
            return 1;
        if (tgt->f1c9)
            return 1;
    }

    int cur = tgt->f114;
    if (cur == body->f12c)
        return 1;
    if (body->other != 0) {
        if (cur == body->other->f12c)
            return 1;
    }

    Stats_1afba0 *st = f->stats;
    if (st->f_b8 > 0.0f || st->FUN_00012f50(&tmp)->FUN_000111f0() > 0.0f)
        tgt->FUN_001d82d0();

    if (tgt->f14d) {
        if (((Hit_1afba0 *)((owners::C_1d72e0 *)tgt)->FUN_001d72e0())->f6c == 0) {
            Fx_1afba0 *fx = ((Fx_1afba0 *)((owners::Obj_7ad00 *)(DAT_004dd700->sys))->FUN_0007ad00((hulk_intptr)(&tgt->f8)));
            if (fx != 0) {
                Probe_1afba0 *p = f->stats->FUN_00012f50(&tmp);
                fx->FUN_00083320(a, b, t, 1, p, 0);
                DAT_004dd700->cue->FUN_001ec980(DAT_004dd700->slot20->id, "punch");
            }
        }
    }

    if (tgt->FUN_001d6a80()) {
        Stats_1afba0 *st2 = f->stats;
        if (st2->f_b8 > 0.0f || st2->FUN_00012f50(&tmp)->FUN_000111f0() > 0.0f) {
            tgt->FUN_001d74c0(0, 0, 10.0f, 1);
            tgt->FUN_001d7510();
        }
    }

    f->FUN_0001a710(hit, a, b);
    return 1;
}
} // namespace fn_001afba0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f7cf5713 {

// 0x001afdc0 FUN_001afdc0 (175 B): matches/0x001afdc0.cpp
// sym: ?FUN_001afdc0@fn_f7cf5713@@YGHPAUContext@1@PAUCandidate_1afdc0@1@IIM@Z
int __stdcall FUN_001afdc0(Context* context, Candidate_1afdc0* candidate, unsigned a, unsigned b, float threshold) {
    if (candidate->type == 5) {
        Owner_1afdc0* owner = context->owner;
        if (!(owner->FUN_00015a20() < threshold)) {
            Entity* source = owner->FUN_00015a30();
            if (source->link && ((Candidate_1afdc0 *)((owners::C_1d72e0 *)(source->link))->FUN_001d72e0()) == candidate)
                return 1;
            Entity* target = candidate->entity;
            if (target->parent && source->group->id == target->parent->group->id)
                return 1;
            unsigned identity = target->identity;
            if (identity == source->relatedIdentity)
                return 1;
            Entity* related = source->related;
            if (related && identity == related->relatedIdentity)
                return 1;
            target->FUN_001d82d0();
            owner->FUN_00015a40(candidate, a, b);
        }
    }
    return 1;
}


// 0x001afe70 FUN_001afe70 (40 B): matches/0x001afe70.cpp
// sym: ?target@fn_f7cf5713@@YGHPAUHolder_1afe70@1@HHHHH@Z
int __stdcall target(Holder_1afe70* self, int a, int b, int c, int d, int e) {
    return self->p->f6(b, a, c, d, e);
}

} // namespace fn_f7cf5713

// 0x001afea0 FUN_001afea0 (165 B): equivalent/0x001afea0.cpp [wrapped: conflict: World]
// sym: ?FUN_001afea0@fn_001afea0@@YGHTLinkArg@1@HTHolderArg@1@HHHH@Z @26e4fdb29899 @w9933891a1bf4
namespace fn_001afea0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001afea0 @ 0x001afea0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Entry_1afea0 {
    char pad0[0x16];
    unsigned char flags;        // 0x16
    char pad17;
};

struct EntryTable_1afea0 {
    char pad0[0x18];
    Entry_1afea0 *entries;             // 0x18
};

struct Owner_1afea0 {
    char pad0[0x44];
    EntryTable_1afea0 *table;          // 0x44
};

struct Link_1afea0 {
    char pad0[0x14];
    int f14;                    // 0x14
    bool FUN_002f8e10(Owner_1afea0 **ownerOut, unsigned short *indexOut);
};

struct Current;

struct Actor_1afea0 {
    char pad0[0x334];
    Current *cur334;            // 0x334
    Current *cur338;            // 0x338
    bool FUN_000373d0();
    void FUN_00038e80(int a, int b, int c, int d, int e, int f);
};

struct Holder_1afea0 {
    char pad0[8];
    Actor_1afea0 *actor;               // 0x08
};

struct Focus_1afea0 {
    char pad0[0x124];
    Current *current;           // 0x124
};

struct World {
    char pad0[0x20];
    Focus_1afea0 *focus;               // 0x20
};

// the original reuses the stack slots of args 1 and 3 as out-parameters
union LinkArg {
    Link_1afea0 *link;
    unsigned int word;
    unsigned short index;
};

union HolderArg {
    Holder_1afea0 *holder;
    Owner_1afea0 *owner;
};

int __stdcall FUN_001afea0(LinkArg a1, int a2, HolderArg a3, int a4, int a5, int a6, int a7)
{
    Link_1afea0 *link = a1.link;
    Actor_1afea0 *actor = a3.holder->actor;
    if (actor->FUN_000373d0()) {
        Current *cur = DAT_004dd700->focus->current;
        bool skip = false;
        if ((Actor_1afea0 *)cur != actor && actor->cur338 != cur && actor->cur334 != cur) {
            a3.owner = 0;
            a1.word = 0;
            if (link->FUN_002f8e10(&a3.owner, &a1.index)) {
                if ((a3.owner->table->entries[a1.index].flags & 8) != 0)
                    skip = true;
            }
        }
        if (!skip)
            actor->FUN_00038e80(a2, a4, link->f14, a5, a6, a7);
    }
    return 1;
}
} // namespace fn_001afea0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001aff50 FUN_001aff50 (315 B): equivalent/0x001aff50.cpp [wrapped: conflict: World]
// sym: ?FUN_001aff50@fn_001aff50@@YGHHPAUHolder_1aff50@1@H0HHPAUV3_1aff50@1@H@Z @89729d9c4618 @w217829d803e6
namespace fn_001aff50 {
// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 24/24)
// FUN_001aff50 @ 0x001aff50
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct V3_1aff50 { float x, y, z; };

struct Actor_1aff50;

struct Holder_1aff50 {
    char pad[8];
    Actor_1aff50* actor;
};

struct Actor_1aff50 {
    char FUN_000373d0();
    void FUN_00038e80(int id, Holder_1aff50* other, int mode, int arg, V3_1aff50* dir, int flags);
    char pad0[0x128];
    int f128;
    char pad1[0x334 - 0x12c];
    Actor_1aff50* a334;
    Actor_1aff50* a338;
    char pad2[0x1b88 - 0x33c];
    float f1b88;
    char pad3[0x20b0 - 0x1b8c];
    int f20b0;
};

struct Clock_1aff50 {
    float FUN_00086080();
};

struct World {
    char pad[0x58];
    Clock_1aff50* clock;
};


int __stdcall FUN_001aff50(int a1, Holder_1aff50* h2, int a3, Holder_1aff50* h4, int a5, int a6, V3_1aff50* dir, int a8)
{
    Actor_1aff50* a = h2->actor;
    Actor_1aff50* b = h4->actor;

    if (DAT_004dd700 != 0)
        a->f1b88 = DAT_004dd700->clock->FUN_00086080();

    if (!a->FUN_000373d0())
        return 1;
    if (!b->FUN_000373d0())
        return 1;
    if (a == b)
        return 1;
    if (a->f20b0 != 0)
        return 1;
    if (b->f20b0 != 0)
        return 1;
    if (a->a338 == b)
        return 1;
    if (a->a334 == b)
        return 1;

    if (a->f128 != 0 || b->f128 == 0) {
        a->FUN_00038e80(a1, h4, -1, a6, dir, a8);
        if (b->f128 == 0 && a->f128 != 0)
            return 1;
    }
    V3_1aff50 neg;
    neg.x = dir->x * -1.0f;
    neg.y = dir->y * -1.0f;
    neg.z = dir->z * -1.0f;
    b->FUN_00038e80(a3, h2, -1, a5, &neg, a8);
    return 1;
}
} // namespace fn_001aff50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001b0090 FUN_001b0090 (136 B): equivalent/0x001b0090.cpp [wrapped: conflict: World]
// sym: ?UnitUpdate@fn_001b0090@@YGHPAUUnit_1b0090@1@HPAUCtx_1b0090@1@@Z @f46792e36299 @wfb38303250d9
namespace fn_001b0090 {
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 18/18)
// FUN_001b0090 @ 0x001b0090
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Info_1b0090 { char pad[0x6c]; int blocked; };
struct Mgr_1b0090 {  };
struct World { char pad[0x4c]; Mgr_1b0090* mgr; };
struct Level_1b0090 { char pad[0x50]; char flag; };
struct Ctx_1b0090 { char pad[0x74]; Level_1b0090* level; };
struct Unit_1b0090 {
 char pad0[8]; int key;
 char pad1[0xe8 - 0xc]; char hit;
 char pad2[0x114 - 0xe9]; int v114;
 char pad3[0x148 - 0x118]; int v148;
 char v14c; char v14d;
 bool FUN_001d7300();
 bool FUN_001d6a80();
 void FUN_001d7510();
};
int __stdcall UnitUpdate(Unit_1b0090* u, int unused, Ctx_1b0090* ctx) {
 if (u->FUN_001d7300()
     && ((Info_1b0090 *)((owners::C_1d72e0 *)u)->FUN_001d72e0())->blocked == 0
     && u->v114 == 0 && u->v148 == 0 && !u->v14d
     && !u->FUN_001d6a80()) {
  if (!u->v14c || !((owners::C_79950 *)(DAT_004dd700->mgr))->FUN_00079950((hulk_intptr)(&u->key)))
   u->FUN_001d7510();
 }
 if (ctx->level->flag) u->hit = 1;
 return 0;
}
} // namespace fn_001b0090
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001b0180 AICollisionSolverAgent::vfunc_10 (131 B): matches/0x001b0180.cpp
// sym: ?vfunc_10@AICollisionSolverAgent@@UAE_NPAX0@Z
bool AICollisionSolverAgent::vfunc_10(void* __p0, void* __p1) { Handle_1b0180 * a = (Handle_1b0180 *)__p0; Handle_1b0180 * b = (Handle_1b0180 *)__p1;

    Obj_1b0180* x = a->mObj;
    Obj_1b0180* y = b->mObj;
    if (!x || !y)
        return false;
    int tx = x->mType;
    int ty = y->mType;
    if (tx == 2) {
        if (ty != 5)
            return false;
    }
    if (ty == 2) {
        if (tx != 5)
            return false;
    } else if (tx == 5 && ty == 1) {
        Owner_1b0180* o = x->mOwner;
        if (o && o->mLink && o->mLink == (void*)y->mOwner)
            return false;
    } else if (ty == 5 && tx == 1) {
        Owner_1b0180* o = y->mOwner;
        if (o && o->mLink && o->mLink == (void*)x->mOwner)
            return false;
    }
    return true;
}


// 0x001b0210 AICollisionSolverAgent::vfunc_11 (66 B): matches/0x001b0210.cpp [wrapped: conflict: AICollisionSolverAgent]
// sym: ?vfunc_11@AICollisionSolverAgent@fn_001b0210@@QAEEPAUInput@2@@Z
namespace fn_001b0210 {
struct AgentState {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual int vfunc_6();
};
struct Checker {
    unsigned char FUN_001d7300();
};
struct Object {
    char pad[8];
    Checker* check;
    int kind;
};
struct Input {
    char pad[0x18];
    Object* object;
    char pad2[4];
    AgentState* state;
};
struct AICollisionSolverAgent {
    unsigned char vfunc_11(Input* input);
};
unsigned char AICollisionSolverAgent::vfunc_11(Input* input) {
    unsigned char result = 1;
    AgentState* state = input->state;
    if (state) {
        int value = state->vfunc_6();
        result = (value == 0 || value == 8) ? 0 : result;
    }
    if (input->object->kind == 5 && !input->object->check->FUN_001d7300())
        return 0;
    return result;
}
} // namespace fn_001b0210

namespace fn_f7cf5713 {

// 0x001b0260 FUN_001b0260 (59 B): equivalent/0x001b0260.cpp
// sym: ?FUN_001b0260@fn_f7cf5713@@YGHPAUObject@1@H@Z @16a4c9648eb9 @w2367c9933d07
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 5/5)
// FUN_001b0260 @ 0x001b0260
int __stdcall FUN_001b0260(Object* object, int kind) { switch (kind) { case 1: case 5: return 1; case 2: case 3: case 4: case 6: case 7: case 10: case 12: return FUN_00044500(object->detail->value); default: return (kind - 1) & ~255; } }

} // namespace fn_f7cf5713

// 0x001b02c0 FUN_001b02c0 (29 B): matches/0x001b02c0.cpp
// sym: ?FUN_001b02c0@Obj_1b02c0@owners@@QAEHXZ
int owners::Obj_1b02c0::FUN_001b02c0() {
    if (a && b)
        return 1;
    return 0;
}

namespace fn_f7cf5713 {

// 0x001b02e0 AICollisionSolverAgent::vfunc_2 (36 B): matches/0x001b02e0.cpp
// sym: ?vfunc_5@AICollisionSolverAgent_1b02e0@fn_f7cf5713@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
AICollisionSolverAgent_1b02e0* AICollisionSolverAgent_1b02e0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041d830;
    Destroy_002f8820();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001b0310 FUN_001b0310 (316 B): equivalent/0x001b0310.cpp
// sym: ?FUN_001b0310@fn_f7cf5713@@YAMPAUAttacker_1b0310@1@PAUVictim@1@@Z @1cee0d62186a @wadc80b5b10ac
// STATUS: equivalent (tools/equiv.py level 3: 3029 inputs, branch coverage 23/23)
// FUN_001b0310 @ 0x001b0310
// equiv-conv: FUN_001b0310 esi edi
float FUN_001b0310(Attacker_1b0310 *atk, Victim *vic)
{
    float v;
    if (atk != 0) {
        if ((DAT_004e1800 & 1) == 0) {
            DAT_004e1800 |= 1;
            (*(Key_1b0310*)((char*)&DAT_004e17c0 + 56)).FUN_0027af00();
            atexit(FUN_00363fd0);
        }
        ((owners::Target_27b040 *)&((*(Key_1b0310*)((char*)&DAT_004e17c0 + 56))))->FUN_0027b040((hulk_uintptr)"no_thrown_damage");
        if (((int)((owners::Obj_36e40 *)atk)->FUN_00036e40((hulk_uintptr)(Key_1b0310 *)(((Key_1b0310*)((char*)&DAT_004e17c0 + 56))))) != 0)
            return (*(float*)&DAT_003f32e0);
    }
    v = vic->f230;
    if (v >= (*(float*)&DAT_003f32e0))
        return v;
    switch (vic->FUN_001d64a0()) {
    case 2:
    case 6:
        return FUN_00044500(atk->f11c->f14) ? DAT_004c3700 : DAT_004c3704;
    case 3:
    case 7:
    case 10:
        return FUN_00044500(atk->f11c->f14) ? DAT_004c3708 : DAT_004c370c;
    case 4:
    case 11:
        return FUN_00044500(atk->f11c->f14) ? DAT_004c3710 : DAT_004c3714;
    case 5:
        return FUN_00044500(atk->f11c->f14) ? DAT_004c36f8 : DAT_004c36fc;
    }
    return v;
}

} // namespace fn_f7cf5713

// 0x001b0470 FUN_001b0470 (268 B): equivalent/0x001b0470.cpp [wrapped: conflict: FUN_00044500]
// sym: _FUN_001b0470 @2d96542271b1 @w6a87c1c2ef14
namespace fn_001b0470 {
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 11/11)
// FUN_001b0470 @ 0x001b0470
// FUN_001b0470 @ 0x001b0470
struct Item_1b0470 {
    int FUN_001d64a0();
};
struct State_1b0470 {
    char reserved[0x14];
    int value;
};
struct Actor_1b0470 {
    char reserved[0x11c];
    State_1b0470* state;
    float FUN_001b0310();
    void FUN_00043ae0(int, int, float, int, float, int, int, int, int);
};
// equiv-conv: FUN_001b0310 esi edi
float FUN_001b0310(Actor_1b0470 *self, Item_1b0470 *item);
extern bool __cdecl FUN_00044500(int);

// equiv-conv: FUN_001b0470 eax ecx stack
extern "C" float __cdecl FUN_001b0470(Item_1b0470* item, Actor_1b0470* self, int argument)
{
    float result = FUN_001b0310(self, item);
    int identifier = ((int)((owners::C_1d72e0 *)item)->FUN_001d72e0());
    unsigned int type = (unsigned int)item->FUN_001d64a0() - 2;
    if (type <= 9) {
        float angle = 90.0f;
        switch (type) {
        case 0: case 4:
            angle = FUN_00044500(self->state->value) ? 10.0f : 90.0f;
            break;
        case 2: case 9:
            angle = FUN_00044500(self->state->value) ? 90.0f : 100.0f;
            break;
        case 6: case 7:
            return result;
        }
        self->FUN_00043ae0(identifier, argument, angle, 0, result, 0, 0, 1, 0);
    }
    return result;
}
} // namespace fn_001b0470


// 0x001b05a0 FUN_001b05a0 (2190 B): equivalent/0x001b05a0.cpp [wrapped: macros; helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_001b05a0@fn_001b05a0@@YGHPAUEntity@1@PAUHitObj_1b05a0@1@PAUContact_1b05a0@1@@Z @8d92bc67fe0d @w3043d7848822
namespace fn_001b05a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3142 inputs, branch coverage 127/134, incomplete)
// FUN_001b05a0 @ 0x001b05a0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)


struct V3_1b05a0 {
    float x, y, z;
    void FUN_0022d180();
};
extern "C" float __cdecl FUN_000186b0(float* v, float* lo, float* hi);
void __cdecl FUN_00224d70(float angle, V3_1b05a0* axis);
static float AbsF(float v) {
    union {
        float f;
        unsigned int u;
    } c;
    c.f = v;
    c.u &= 0x7fffffff;
    return c.f;
}
struct Tri_1b05a0 {
    char pad00[0x16];
    unsigned char b16;
    char pad17[1];
};
struct Mesh44 {
    char pad00[0x18];
    Tri_1b05a0* tris;
};
struct Geo {
    char pad00[0x44];
    Mesh44* f44;
    void FUN_001af890(V3_1b05a0* out, int idx);
};
struct Entity;
struct Info_1b05a0 {
    char pad00[0x18];
    void* f18;
};
struct Contact_1b05a0 {
    char pad00[0xc];
    Info_1b05a0* info;
    char pad10[4];
    int f14;
    V3_1b05a0 n;
    int f24;
    char pad28[4];
    V3_1b05a0 p;
    V3_1b05a0 q;
    char FUN_002f8e10(Geo** geo, unsigned int* idx);
};
struct Ent114Body {
    char pad00[8];
    unsigned int f8, fc;
    char pad10[0x12c - 0x10];
    int f12c;
    char pad130[0x138 - 0x130];
    int f138;
    void FUN_00038e80(int a, void* hit, int b, V3_1b05a0* p, V3_1b05a0* n, int c);
};
struct Ent114 {
    char pad00[8];
    Ent114Body* f8;
    int kind;
};
struct Reg4c {
    char FUN_00079950(void* pos);
    int FUN_00079800(void* pos);
    void FUN_0007ba60(int i);
    struct Sparks* FUN_0007ad00(void* pos);
};
struct Sparks {
    void FUN_00083320(V3_1b05a0* q, V3_1b05a0* n, int c, int d, V3_1b05a0* z, int e);
};
struct Grid38 {
    void FUN_001f6cd0(Tri_1b05a0* tri, Geo* geo, V3_1b05a0* q, V3_1b05a0* n, V3_1b05a0* dir, int mode,
                      float r1, float r2, int* out, int z);
};
struct Grid34 {
};
struct World {
    char pad00[0x20];
    struct Holder_1b05a0* f20;
    char pad24[0x34 - 0x24];
    Grid34* f34;
    Grid38* f38;
    char pad3c[0x4c - 0x3c];
    Reg4c* f4c;
};
struct Holder_1b05a0 {
    char pad00[0x124];
    Entity* cur;
};
struct HitObj_1b05a0 {
    char pad00[0xc];
    int kind;
};
struct Body72 {
    char pad00[0x20];
    float f20;
    char pad24[0x34 - 0x24];
    float f34;
};
struct Obj1d72_1b05a0 {
    char pad00[0x50];
    V3_1b05a0 v50;
    char pad5c[0x6c - 0x5c];
    int f6c;
    struct Ob70* f70;
    struct Ob74* f74;
};
struct Ob74 {
    char pad00[0x20];
    Body72* f20;
};
struct Ob70 {
};
struct Chk {
    int FUN_001d5e80(int a);
};
struct Dummy964 {
    hulk_freg FUN_000787e0(int a, float b);
};
extern "C" Dummy964* __cdecl FUN_000964d0();
struct Entity {
    char pad00[8];
    char pos8[0x38];
    int f40;
    char pad44[0xec - 0x44];
    Chk* fec;
    char padf0[0x114 - 0xf0];
    Ent114* f114;
    char pad118[0x12c - 0x118];
    int f12c;
    char pad130[0x134 - 0x130];
    int f134;
    char pad138[0x148 - 0x138];
    Entity* other;
    char b14c, b14d;
    char pad14e[0x1c9 - 0x14e];
    char b1c9;
    char pad1ca[0x1fc - 0x1ca];
    int f1fc;
    char pad200[0x218 - 0x200];
    float f218;
    char pad21c[0x248 - 0x21c];
    int f248;
    char pad24c[0x334 - 0x24c];
    Entity *ign334, *ign338;
    void FUN_001d6ac0(int a);
    char FUN_001d6a80();
    int FUN_001d64a0();
    char FUN_001d6980();
    V3_1b05a0* FUN_001d6b40();
    void FUN_00035660(V3_1b05a0* out);
    char FUN_000373d0();
    float FUN_001d8160();
    void FUN_0027d4f0(int a);
    void FUN_001d69f0(V3_1b05a0* out);
    void FUN_001d8cd0();
    void FUN_001d7510();
    void FUN_001d6ec0(int a, int b, int c);
    void FUN_00038e80(int a, HitObj_1b05a0* hit, int b, V3_1b05a0* p, V3_1b05a0* n, int c);
};
int __stdcall FUN_001b05a0(Entity* self, HitObj_1b05a0* hit, Contact_1b05a0* c) {
#define world DAT_004dd700
    // Scratch vectors are reused by the contact, particle, and collision queries.
    struct Scratch {
        float upper;
        union {
            unsigned int triangleIndex;
            int particleResult;
        } index;
        float lower;
        float radius;
        V3_1b05a0 direction;
        V3_1b05a0 normal;
        V3_1b05a0 point;
    } s;
    if (AbsF(c->n.y) <= 1e-05f) {
        if (c->q.y <= 0.2f) {
            Geo* geo = 0;
            s.index.triangleIndex = 0;
            if (!c->FUN_002f8e10(&geo, &s.index.triangleIndex))
                return 1;
            Tri_1b05a0* tri = &geo->f44->tris[(unsigned short)s.index.triangleIndex];
            s.upper = 1000.0f;
            hulk_freg maximum = -1000.0f;
            unsigned short* vertices = (unsigned short*)((char*)tri + 0x10);
            for (int k = 0; k < 3; ++k) {
                geo->FUN_001af890(&s.normal, vertices[k]);
                if (s.normal.y < s.upper)
                    s.upper = s.normal.y;
                if (s.normal.y > maximum)
                    maximum = s.normal.y;
            }
            if (!(maximum - s.upper > 1.0f))
                return 1;
        } else
            self->FUN_001d6ac0(1);
    }
    if (self->FUN_001d6a80())
        return 1;
    Entity* current = world->f20->cur;
    Entity* other = self->other;
    bool checkTriangle = other ? (other != current && other->ign338 != current && other->ign334 != current)
                               : !((char)((owners::Obj_1d4e40 *)(self->fec))->FUN_001d4e40());
    if (checkTriangle) {
        Geo* geo = 0;
        unsigned int index = 0;
        if (c->FUN_002f8e10(&geo, &index)) {
            Tri_1b05a0* tri = &geo->f44->tris[(unsigned short)index];
            if (tri->b16 & 8)
                return 1;
        }
    }
    if (other && other->FUN_000373d0()) {
        if (hit != c->info->f18) {
            s.direction.x = c->n.x * -1.0f;
            s.direction.y = c->n.y * -1.0f;
            s.direction.z = c->n.z * -1.0f;
            s.normal = c->q;
        } else {
            s.normal = c->p;
            s.direction = c->n;
        }
        other->FUN_00038e80(other->f12c, hit, c->f14, &s.normal, &s.direction, c->f24);
        return 1;
    }
    if (self->f114 && self->f134 == 0 && self->FUN_001d64a0() != 5) {
        Ent114* owner = self->f114;
        if (owner->kind == 1) {
            Ent114Body* body = owner->f8;
            if (body->f8 == (*(unsigned int*)&DAT_004dc0e0) &&
                body->fc == (*(unsigned int*)((char*)&DAT_004dc0e0 + 4)) && !(body->f138 > 0))
                body->FUN_00038e80(body->f12c, hit, c->f14, &c->q, &c->n, c->f24);
        }
    }
    bool tryParticle = true;
    if (!self->f114) {
        if (self->b14d)
            tryParticle = false;
        else if (self->FUN_001d6980())
            tryParticle = false;
    }
    if (tryParticle) {
        Ent114Body* body = 0;
        if (self->f114 && self->f114->kind == 1) {
            body = self->f114->f8;
            if (body->f8 != (*(unsigned int*)&DAT_004dc0e0) ||
                body->fc != (*(unsigned int*)((char*)&DAT_004dc0e0 + 4)))
                body = 0;
        }
        char registered = 0;
        if (self->b14c)
            registered = world->f4c->FUN_00079950(&self->pos8);
        if (body || !registered) {
            V3_1b05a0* previous = self->FUN_001d6b40();
            V3_1b05a0* position = ((V3_1b05a0 *)((owners::Thing_1d6b30 *)self)->FUN_001d6b30());
            s.direction.x = position->x - previous->x;
            s.direction.y = position->y - previous->y;
            s.direction.z = position->z - previous->z;
            hulk_freg threshold = 15.0f;
            double speedSquared;
            if (body) {
                ((Entity*)body)->FUN_00035660(&s.normal);
                speedSquared = s.normal.z * s.normal.z + s.normal.y * s.normal.y + s.normal.x * s.normal.x;
                threshold = 64.0f;
            } else {
                Obj1d72_1b05a0* state = ((Obj1d72_1b05a0 *)((owners::C_1d72e0 *)self)->FUN_001d72e0());
                V3_1b05a0* velocity = &state->v50;
                speedSquared =
                    velocity->x * velocity->x + velocity->y * velocity->y + velocity->z * velocity->z;
            }
            if (speedSquared > threshold && s.direction.z * s.direction.z + s.direction.y * s.direction.y +
                                                    s.direction.x * s.direction.x >
                                                2.0f) {
                Geo* geo = 0;
                unsigned int index = 0;
                if (c->FUN_002f8e10(&geo, &index)) {
                    Tri_1b05a0* tri = &geo->f44->tris[(unsigned short)index];
                    if (tri && !(tri->b16 & 8)) {
                        ((owners::Target_1d6ad0 *)self)->FUN_001d6ad0((int *)(V3_1b05a0 *)(self->FUN_001d6b40()));
                        s.upper = 2.0f;
                        s.lower = 0.5f;
                        s.radius = self->FUN_001d8160() * 0.01f;
                        s.lower = FUN_000186b0(&s.radius, &s.lower, &s.upper);
                        s.point = c->q;
                        s.normal = c->n;
                        if (self->fec->FUN_001d5e80(self->f40) == 3) {
                            s.radius = FUN_000964d0()->FUN_000787e0(0, 360.0f);
                            s.direction.x = (*(float*)&DAT_004c3754);
                            s.direction.y = (*(float*)&DAT_004c3758);
                            s.direction.z = (*(float*)&DAT_004c375c);
                            FUN_00224d70(s.radius, &s.direction);
                        } else {
                            if (body)
                                ((Entity*)body)->FUN_00035660(&s.direction);
                            else
                                s.direction = ((Obj1d72_1b05a0 *)((owners::C_1d72e0 *)self)->FUN_001d72e0())->v50;
                            s.direction.FUN_0022d180();
                        }
                        s.index.particleResult = 0;
                        world->f38->FUN_001f6cd0(tri, geo, &s.point, &s.normal, &s.direction, 8, s.lower,
                                                 s.lower, &s.index.particleResult, 0);
                        ((owners::Crusher_1ebea0 *)(world->f34))->FUN_001ebea0((const char *)(hulk_uintptr)(int)(s.index.particleResult), (hulk_intptr)(Entity *)self);
                    }
                }
            }
        }
    }
    if (self->b1c9 && self->f1fc != 0 && self->fec->FUN_001d5e80(self->f40) == 4 && !(self->f218 < 10.0f))
        self->FUN_0027d4f0(9);
    if (hit->kind != 5 && self->b1c9) {
        Obj1d72_1b05a0* state = ((Obj1d72_1b05a0 *)((owners::C_1d72e0 *)self)->FUN_001d72e0());
        V3_1b05a0* velocity = &state->v50;
        if (velocity->x * velocity->x + velocity->y * velocity->y + velocity->z * velocity->z > 25.0f) {
            bool activate = false;
            if (self->fec->FUN_001d5e80(self->f40) != 3)
                activate = true;
            else {
                Obj1d72_1b05a0* state2 = ((Obj1d72_1b05a0 *)((owners::C_1d72e0 *)self)->FUN_001d72e0());
                s.normal.x = s.normal.y = s.normal.z = 0;
                if (state2->f70)
                    ((owners::Thing_16fc60 *)(state2->f70))->FUN_0016fc60((int *)(V3_1b05a0 *)(&s.normal));
                else
                    self->FUN_001d69f0(&s.normal);
                hulk_freg height = 0.0f;
                if (state2->f74 && state2->f74->f20)
                    height = state2->f74->f20->f34;
                hulk_freg contactHeight = (void*)state2 == c->info->f18 ? c->q.y : c->p.y;
                hulk_freg delta = contactHeight - (s.normal.y - height);
                if (!(height * 0.75f > delta) && !(AbsF(c->n.y) > 0.3f))
                    activate = true;
            }
            if (activate) {
                self->f248 = 1;
                self->FUN_001d8cd0();
            }
        }
    }
    if (self->b14c && world->f4c->FUN_00079950(&self->pos8)) {
        if (!(AbsF(c->n.y - 1.0f) <= 1e-05f)) {
            self->FUN_001d7510();
            Reg4c* registry = world->f4c;
            int id = registry->FUN_00079800(&self->pos8);
            if (id != -1) {
                registry->FUN_0007ba60(id);
                if (((owners::Thing_7a820 *)registry)->FUN_0007a820(id) > DAT_004c3734)
                    self->FUN_001d6ec0((int)DAT_004c372c, 0, 0);
            }
        }
    }
    if (self->b14d) {
        void* contactOwner = c->info->f18;
        s.normal = (void*)((Obj1d72_1b05a0 *)((owners::C_1d72e0 *)self)->FUN_001d72e0()) == contactOwner ? c->q : c->p;
        Sparks* sparks = world->f4c->FUN_0007ad00(&self->pos8);
        if (sparks) {
            s.point.x = s.point.y = s.point.z = 0;
            sparks->FUN_00083320(&s.normal, &c->n, c->f24, 0, &s.point, 0);
            if (((Obj1d72_1b05a0 *)((owners::C_1d72e0 *)self)->FUN_001d72e0())->f6c == 0)
                return 1;
        }
    }
    self->FUN_0027d4f0(8);
    return 0;
}
} // namespace fn_001b05a0
#undef world
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001b0e30 FUN_001b0e30 (361 B): equivalent/0x001b0e30.cpp [wrapped: conflict: World]
// sym: ?FUN_001b0e30@fn_001b0e30@@YGHPAUCtx_1b0e30@1@PAUEntity@1@PBM2H@Z @29392fe4909c @w2e0c95319071
namespace fn_001b0e30 {
// STATUS: equivalent (tools/equiv.py level 3: 3033 inputs, branch coverage 23/23)
// FUN_001b0e30 @ 0x001b0e30
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)


struct Target_1b0e30 {
    void FUN_00081690(const float *a, const float *b, int c, int flag, float *outPos);
};

struct Ctx_1b0e30 {
    char pad0[8];
    Target_1b0e30 *target;
};

struct Handler_1b0e30 {
    void FUN_0001b510(Ctx_1b0e30 *ctx, const float *a, const float *b, int mode);
};

struct Chain3_1b0e30 { char pad0[0x12c]; void *f12c; };
struct Chain2_1b0e30 { char pad0[0x124]; Chain3_1b0e30 *next; };
struct World { char pad0[0x20]; Chain2_1b0e30 *next; };

class Owner_1b0e30 {
public:
    char pad0[0x114];
    void *f114;
    char pad118[0x134 - 0x118];
    Handler_1b0e30 *handler;
    void FUN_001d82d0();
    void FUN_0001a710(Ctx_1b0e30 *ctx, const float *a, const float *b);
};

struct Dist {
    hulk_freg FUN_000111f0();
};

struct Info_1b0e30 {
    char pad0[8];
    int key1;
    int key2;
};

struct Entity {
    char pad0[8];
    Owner_1b0e30 *owner;
    int state;
    char pad10[0x50 - 0x10];
    Dist dist;
    char pad51[0x74 - 0x51];
    Info_1b0e30 *info;
};

struct Frame_1b0e30 {
    union { char b; int w; } flag;
    float v[3];
};

int __stdcall FUN_001b0e30(Ctx_1b0e30 *ctx, Entity *ent, const float *a3, const float *a4, int a5) {
    Info_1b0e30 *info = ent->info;
    Frame_1b0e30 f;
    f.v[0] = 0; f.v[1] = 0; f.v[2] = 0;
    f.flag.b = 0;
    if (info->key1 == (*(int*)&DAT_004e2198) && info->key2 == DAT_004e219c) {
        unsigned int bits = ((const unsigned int *)a4)[1] & 0x7fffffff;
        float absY = *(float *)&bits;
        if (absY <= 1e-5f && a3[1] <= 0.2f)
            return 1;
    } else {
        switch (ent->state) {
        case 1:
        case 4:
            return 1;
        case 3:
            ent->owner->FUN_0001a710(ctx, a3, a4);
            return 1;
        case 5: {
            Owner_1b0e30 *o = ent->owner;
            if (o->handler != 0) {
                o->handler->FUN_0001b510(ctx, a3, a4, 2);
                return 1;
            }
            if (o->f114 != 0) {
                if (o->f114 == DAT_004dd700->next->next->f12c) return 1;
            }
            if (ent->dist.FUN_000111f0() > 4.0f) {
                f.flag.b = 1;
                f.v[0] = a4[0]; f.v[1] = a4[1]; f.v[2] = a4[2];
            }
            o->FUN_001d82d0();
            break;
        }
        default:
            break;
        }
    }
    ctx->target->FUN_00081690(a3, a4, a5, f.flag.w, f.v);
    return 1;
}
} // namespace fn_001b0e30
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001b0fb0 AICollisionSolverAgent::vfunc_9 (193 B): equivalent/0x001b0fb0.cpp [wrapped: conflict: AICollisionSolverAgent; World]
// sym: ?vfunc_9@AICollisionSolverAgent@fn_001b0fb0@@QAEHPAUContact_1b0fb0@2@PAX@Z @7ab44b4bea03 @w9f10429d0524
namespace fn_001b0fb0 {
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 7/8, incomplete)
// AICollisionSolverAgent::vfunc_9 @ 0x001b0fb0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Vec_1b0fb0 { float x,y,z; hulk_freg FUN_0022d110(); };
struct Body_1b0fb0 { char pad[0x14c]; unsigned char enabled; };
struct Contact_1b0fb0 { char pad0[8]; Body_1b0fb0* body; int type; char pad1[0x40]; Vec_1b0fb0 velocity; };
struct Manager_1b0fb0 { bool FUN_00079950(void*); };
struct World { char pad[0x4c]; Manager_1b0fb0* manager; };

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif

class AICollisionSolverAgent { public: int vfunc_9(Contact_1b0fb0*, void*); };
int AICollisionSolverAgent::vfunc_9(Contact_1b0fb0* contact, void*) {
 if(contact->type == 5 && contact->body->enabled) {
  if(!DAT_004dd700->manager->FUN_00079950((char*)contact->body + 8)) {
   Vec_1b0fb0 v = contact->velocity;
   if (!(sqrt((double)v.z*v.z + (double)v.x*v.x + (double)v.y*v.y) < 100.0f)) {
    v.FUN_0022d110();
    contact->velocity.x = v.x * 100.0f;
    contact->velocity.y = v.y * 100.0f;
    contact->velocity.z = v.z * 100.0f;
   }
  }
 }
 return 0;
}
} // namespace fn_001b0fb0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f7cf5713 {

// 0x001b1080 FUN_001b1080 (488 B): equivalent/0x001b1080.cpp
// sym: ?FUN_001b1080@fn_f7cf5713@@YGHPAUObj_1b1080@1@PAUMover_1b1080@1@PAUV3_1b1080@1@H@Z @f197f32ed3bc @w96a14723d9a9
// STATUS: equivalent (tools/equiv.py level 3: 20047 inputs, branch coverage 18/20, incomplete)
// FUN_001b1080 @ 0x001b1080
int __stdcall FUN_001b1080(Obj_1b1080 *obj, Mover_1b1080 *mover, V3_1b1080 *out, int a4)
{
    if (obj->core->FUN_001d4f70() == (*(unsigned __int64*)&DAT_004e1828)) {
        out->x = 0.0f;
        out->y = 0.0f;
        out->z = 0.0f;
        return 0;
    }
    V3_1b1080 v;
    ((owners::C_35660 *)mover)->FUN_00035660((int *)(V3_1b1080 *)(&v));
    hulk_freg vlen2 = v.z * v.z + v.y * v.y + v.x * v.x;
    V3_1b1080 w = *out;
    Slots_1b1080 s;
    s.d = sqrt(vlen2);
    if (!(s.d >= 0.01f))
        return 0;
    hulk_freg dot = w.z * v.z + w.y * v.y + w.x * v.x;
    hulk_freg wlen = sqrt(w.z * w.z + w.y * w.y + w.x * w.x);
    hulk_freg c = dot / (wlen * s.d);
    if (c >= -1.0f && c <= 1.0f) {
        s.d = c;
    } else {
        s.d = 1.0f;
        if (!(c > 1.0f))
            s.d = -1.0f;
    }
    if (!(FUN_00018a20(s.d) < 1.57079637f))
        return 0;
    if (obj->blocked) {
        out->x = 0.0f;
        out->y = 0.0f;
        out->z = 0.0f;
        return 0;
    }
    s.d = obj->FUN_001d8160();
    s.hi = 10000.0f;
    s.lo = 1.0f;
    FUN_000186b0(&s.d, &s.lo, &s.hi);
    if (obj->clampFlag && s.d < 200.0f)
        s.d = 200.0f;
    hulk_freg inv = 1.0f / sqrt(s.d);
    out->x = out->x * inv;
    out->y = out->y * inv;
    out->z = out->z * inv;
    return 0;
}

} // namespace fn_f7cf5713

// 0x001b1270 FUN_001b1270 (822 B): equivalent/0x001b1270.cpp [wrapped: conflict: World]
// sym: ?FUN_001b1270@fn_001b1270@@YGHPAUActor_1b1270@1@0PAUVec3_1b1270@1@PAUContact_1b1270@1@PAUBody_1b1270@1@3@Z @38a30be177e0 @w80687297f4e2
namespace fn_001b1270 {
// STATUS: equivalent (tools/equiv.py level 3: 3066 inputs, branch coverage 56/56)
// FUN_001b1270 @ 0x001b1270
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Vec3_1b1270 {
    float x, y, z;
};

struct Body_1b1270 {
    char pad00[0x50];
    Vec3_1b1270 vel;
};

struct Contact_1b1270 {
    char pad00[0x18];
    Vec3_1b1270 f18;
    char pad24[0x2c - 0x24];
    Vec3_1b1270 f2c;
    Vec3_1b1270 f38;
};

struct Slot_1b1270 {
    unsigned __int64 FUN_001d4f70();
    int FUN_001d5e80(int id);
};

struct Joint_1b1270 {
    char FUN_001b6e90(Body_1b1270* other);
};

struct Sink_1b1270 {
    void FUN_001cbd10(const char* name);
};

struct World {
    char pad00[0x30];
    Sink_1b1270* sink;
};


struct Actor_1b1270 {
    char pad00[0x40];
    int id;
    char pad44[0xec - 0x44];
    Slot_1b1270* slot;
    char padf0[0x118 - 0xf0];
    int f118;
    char pad11c[0x1a4 - 0x11c];
    Joint_1b1270 joint;
    char pad1a4[0x1c9 - 0x1a4 - sizeof(Joint_1b1270)];
    char flag;
    int FUN_001d73f0();
    hulk_freg FUN_001d6670();
    void FUN_001d66b0(Vec3_1b1270* a, Vec3_1b1270* b);
    void FUN_001d6ec0(int a, int b, int c);
    void FUN_001d8d90(int v);
    void FUN_001d71e0(int v);
};

extern "C" int __cdecl FUN_0034483c();

int __stdcall FUN_001b1270(Actor_1b1270* a, Actor_1b1270* b, Vec3_1b1270* v, Contact_1b1270* c, Body_1b1270* bodyA, Body_1b1270* bodyB)
{
    if (!(v->x * v->x + v->y * v->y + v->z * v->z > 25.0f))
        return 0;
    if (a->joint.FUN_001b6e90(bodyB))
        return 0;
    if (!a->flag && !b->flag)
        return 0;
    float sqA = bodyA->vel.x * bodyA->vel.x + bodyA->vel.y * bodyA->vel.y + bodyA->vel.z * bodyA->vel.z;
    float sqB = bodyB->vel.x * bodyB->vel.x + bodyB->vel.y * bodyB->vel.y + bodyB->vel.z * bodyB->vel.z;
    int owner = ((int)((owners::C_1d72e0 *)b)->FUN_001d72e0());
    if (!(sqA > 25.0f) && !(sqB > 25.0f))
        return 0;
    if (owner != 0) {
        ((owners::Thing_1b6e60 *)&(a->joint))->FUN_001b6e60((hulk_intptr)(Body_1b1270 *)bodyB);
        ((owners::Thing_1b6e60 *)&(b->joint))->FUN_001b6e60((hulk_intptr)(Body_1b1270 *)bodyA);
    }
    if (a->slot->FUN_001d4f70() == (*(unsigned __int64*)&DAT_004e1828) || b->slot->FUN_001d4f70() == (*(unsigned __int64*)&DAT_004e1828))
        DAT_004dd700->sink->FUN_001cbd10("golf_stroke");
    Actor_1b1270* heavy = sqA > sqB ? a : b;
    float mult = ((owners::Obj_1afb00 *)heavy)->FUN_001afb00();
    int aN = a->FUN_001d73f0();
    int bN = b->FUN_001d73f0();
    float fA = a->FUN_001d6670();
    if (a->flag && bN <= -10)
        fA = 0.1f;
    float fB = b->FUN_001d6670();
    if (b->flag && aN <= -10)
        fB = 0.1f;

    int kA = a->slot->FUN_001d5e80(a->id);
    bool is3A = kA == 3;
    bool is2A = kA == 2;
    a->FUN_001d6ec0((int)(fA * mult), b->f118, 0);
    if (b->flag)
        b->FUN_001d66b0(&c->f38, &c->f18);

    int kB = b->slot->FUN_001d5e80(b->id);
    bool is3B = kB == 3;
    bool is2B = kB == 2;
    b->FUN_001d6ec0((int)(fB * mult), a->f118, 0);
    if (a->flag) {
        Vec3_1b1270 neg = c->f18;
        neg.x = neg.x * -1.0f;
        neg.y = neg.y * -1.0f;
        neg.z = neg.z * -1.0f;
        a->FUN_001d66b0(&c->f2c, &neg);
    }
    if (!is3A && !is2A && bN > -10) {
        a->FUN_001d8d90(0);
        a->FUN_001d71e0(0);
    }
    if (!is3B && !is2B && aN > -10) {
        b->FUN_001d8d90(0);
        b->FUN_001d71e0(0);
    }
    return 0;
}
} // namespace fn_001b1270
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f7cf5713 {

// 0x001b15b0 FUN_001b15b0 (49 B): matches/0x001b15b0.cpp
// sym: ?Run@Owner@fn_f7cf5713@@QAEDHPAVItem@2@@Z
char Owner::Run(hulk_intptr x, Item* p) {
    char ok = p->Valid_001d7300();
    if (!ok)
        return ok;
    return Do_001b0260(x, p->Value_001d64a0());
}

} // namespace fn_f7cf5713

// 0x001b15f0 FUN_001b15f0 (76 B): matches/0x001b15f0.cpp [wrapped: conflict: Function2]
// sym: ??0Function2@fn_001b15f0@@QAE@PBDP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001b15f0 {
// Method2's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.

typedef unsigned char u8;
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
u8 __cdecl query_001d04d0(const char*);
class Function_1b15f0 : public CtorV_001d0480 {
  public:
    Function_1b15f0(const char* n) : CtorV_001d0480(n, 2) { }
};
class Function2 : public Function_1b15f0 {
  public:
    virtual bool Fnf_001d04c0(int, int);
    ScriptMemberFn data;
    Function2(const char*, ScriptMemberFn);
};
Function2::Function2(const char* n, ScriptMemberFn d) : Function_1b15f0(n) {
    data = d;
    retType = query_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = query_001d04d0(((const char*)&DAT_0048e128));
    argTypes[1] = query_001d04d0(((const char*)&DAT_0048e128));
}
} // namespace fn_001b15f0


// 0x001b1640 Function2<void,float,float>::vfunc_2 (20 B): matches/0x001b1640.cpp
// sym: ?vfunc_2@?$Function2@XMM@@UAEXPAX00@Z
template <> void Function2<void, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr x = (hulk_intptr)__p0; unsigned int * p = (unsigned int *)__p1; hulk_intptr y = (hulk_intptr)__p2;

    (*(void (**)(float, float))&this->f_1c)(*(float*)p, *((float*)p + 1));
}


// 0x001b1660 FUN_001b1660 (76 B): matches/0x001b1660.cpp [wrapped: conflict: Function2]
// sym: ??0Function2@fn_001b1660@@QAE@PAX0@Z
namespace fn_001b1660 {
// data: strA = DAT_0048e100, strB = DAT_0048e0f0, strC = DAT_0048e128

char __cdecl GetFlag_001d04d0(const char*);
class Function_1b1660 {
  public:
    virtual void* Fnf_001b16f0(int);
    Function_1b1660(void*, int);
    char pad[20];
};
class Function2 : public Function_1b1660 {
  public:
    virtual bool Fng_001d04c0(int, int);
    Function2(void*, void*);
    char flag18[4];
    void* target;
};
Function2::Function2(void* a, void* b) : Function_1b1660(a, 2) {
    target = b;
    flag18[0] = GetFlag_001d04d0(((const char*)&DAT_0048e100));
    ((char*)this)[0x10] = GetFlag_001d04d0(((const char*)&DAT_0048e0f0));
    ((char*)this)[0x11] = GetFlag_001d04d0(((const char*)&DAT_0048e128));
}
} // namespace fn_001b1660


// 0x001b16b0 Function2<void,const_char_*,float>::vfunc_2 (20 B): matches/0x001b16b0.cpp
// sym: ?vfunc_2@?$Function2@XMM@@UAEXPAX00@Z
// Same code shape as 0x001b1640 (propagated; names are from that function)
template <> void Function2<void, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr x = (hulk_intptr)__p0; unsigned int * p = (unsigned int *)__p1; hulk_intptr y = (hulk_intptr)__p2;

    (*(void (**)(float, float))&this->f_1c)(*(float*)p, *((float*)p + 1));
}


// 0x001b16d0 Function2<void,float,float>::vfunc_0 (30 B): matches/0x001b16d0.cpp
// sym: ??_G?$Function2@XMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Function2<void, float, float>::~Function2() {}
#if defined(HULK_PTR64)
template class Function2<void, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1b16d0)
#endif


// 0x001b16f0 Function2<void,const_char_*,float>::vfunc_0 (30 B): matches/0x001b16f0.cpp
// sym: ??_G?$Function2@XPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Function2<void, const char *, float>::~Function2() {}
#if defined(HULK_PTR64)
template class Function2<void, const char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1b16f0)
#endif


// 0x001b1e90 FUN_001b1e90 (1738 B): equivalent/0x001b1e90.cpp [wrapped: conflict: World]
// sym: ?FUN_001b1e90@Self_1b1e90@fn_001b1e90@@QAEHPAUHolder_1b1e90@2@0HHTSlot5_1b1e90@2@M@Z @428df6ef6ccd @w1a7457e13bf8
namespace fn_001b1e90 {
// STATUS: equivalent (tools/equiv.py level 3: 20064 inputs, branch coverage 96/96)
// FUN_001b1e90 @ 0x001b1e90
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

typedef unsigned __int64 u64_1b1e90;

struct V3_1b1e90 {
    float x, y, z;
    hulk_freg FUN_000111f0();
};

struct Actor_1b1e90;

struct Holder_1b1e90 {
    char pad0[8];
    Actor_1b1e90 *actor;                  // 8
    char pad0c[0x50 - 0xc];
    V3_1b1e90 v50;                        // 0x50
    char pad5c[0x6c - 0x5c];
    int f6c;
};

struct Sub_1b1e90 {
    char pad0[0x12c];
    Holder_1b1e90 *f12c;
    char pad130[0x1d4d - 0x130];
    unsigned char b1d4d;
};

struct Id_1b1e90 {
    char pad0[8];
    u64_1b1e90 id;                        // 8
};

struct Aux_1b1e90 {
    char pad0[8];
    Id_1b1e90 *f08;
    int f0c;
};

struct Eff_1b1e90 {
    void FUN_0001b510(Holder_1b1e90 *a, int b, V3_1b1e90 *dir, int mode);
};

struct Pos_1b1e90 {
    float x, y, z;
};

struct Actor_1b1e90 {
    char pad0[8];
    V3_1b1e90 v8;                         // 8
    char pad14[0x114 - 0x14];
    Aux_1b1e90 *f114;
    char pad118[0x134 - 0x118];
    Eff_1b1e90 *f134;
    char pad138[0x148 - 0x138];
    Sub_1b1e90 *f148;
    unsigned char b14c;
    unsigned char b14d;
    char pad14e[0x1c9 - 0x14e];
    unsigned char b1c9;
    char pad1ca[0x1ed - 0x1ca];
    unsigned char b1ed;
    char pad1ee[0x1fc - 0x1ee];
    int f1fc;

    int FUN_001da540(Holder_1b1e90 *h, int v, V3_1b1e90 *dir, float s);
    int FUN_001d82d0();
    void FUN_001d6ec0(int a, int b, int c);
    char FUN_001d6a80();
    char FUN_001d7300();
    Pos_1b1e90 *FUN_001d6b40();
    void FUN_001d7810(V3_1b1e90 p);
    void FUN_0027d4f0(int a);
    struct Part_1b1e90 *FUN_001d77c0();
};

struct Part_1b1e90 {
    hulk_freg FUN_00018990();
};

struct Hit_1b1e90 {
    void FUN_00083320(int a, V3_1b1e90 *dir, float s, int flag, V3_1b1e90 *vec, int one);
};

struct Mon {
};

struct Fx_1b1e90 {
    void FUN_001ebd80(Actor_1b1e90 *a, const char *name, float v, int z);
};

struct World {
    char pad0[0x34];
    Fx_1b1e90 *f34;
    char pad38[0x4c - 0x38];
    Mon *f4c;
};

union Slot5_1b1e90 {
    V3_1b1e90 *dir;
    float mag;
    Mon *mon;
};

int __stdcall FUN_001aff50(Holder_1b1e90 *a1, Holder_1b1e90 *a2, Holder_1b1e90 *a3, Holder_1b1e90 *a4, int a5, int a6, V3_1b1e90 *a7, float a8);

class Self_1b1e90 {
public:
    int FUN_001b1710(Holder_1b1e90 *a1, Holder_1b1e90 *a2, Holder_1b1e90 *a3, int a4, V3_1b1e90 *a5, float a6);
    int FUN_001b1e90(Holder_1b1e90 *h1, Holder_1b1e90 *h2, hulk_intptr arg3, hulk_intptr arg4, Slot5_1b1e90 a5, float arg6);
};

struct Frame_1b1e90 {
    int result;                    // E-0x1c
    V3_1b1e90 n1;                         // E-0x18
    V3_1b1e90 n2;                         // E-0xc
};

int Self_1b1e90::FUN_001b1e90(Holder_1b1e90 *h1, Holder_1b1e90 *h2, hulk_intptr arg3, hulk_intptr arg4, Slot5_1b1e90 a5, float arg6)
{
    Frame_1b1e90 f;
    Actor_1b1e90 *B = h2->actor;
    Sub_1b1e90 *b148 = B->f148;
    Actor_1b1e90 *A = h1->actor;
    Sub_1b1e90 *a148 = A->f148;
    if (a148 != 0) {
        if (b148 != 0) {
            if (a148->b1d4d != 0 || b148->b1d4d != 0)
                return FUN_001aff50(h1, a148->f12c, h2, b148->f12c, arg3, arg4, a5.dir, arg6);
        } else {
            return FUN_001b1710(h1, a148->f12c, h2, arg3, a5.dir, arg6);
        }
    } else if (b148 != 0) {
        V3_1b1e90 *src = a5.dir;
        f.n1.x = src->x * -1.0f;
        f.n1.y = src->y * -1.0f;
        f.n1.z = src->z * -1.0f;
        return FUN_001b1710(h2, b148->f12c, h1, arg4, &f.n1, arg6);
    }

    f.result = 0;
    if (A->b1ed != 0) {
        if (B->b1ed != 0)
            return 1;
    }
    V3_1b1e90 *dir = a5.dir;
    if (A->b1c9 != 0 && A->f1fc != 0)
        f.result = A->FUN_001da540(h2, arg4, dir, arg6);
    if (B->b1c9 != 0 && B->f1fc != 0) {
        f.n1.x = dir->x * -1.0f;
        f.n1.y = dir->y * -1.0f;
        f.n1.z = dir->z * -1.0f;
        f.result = B->FUN_001da540(h1, arg3, &f.n1, arg6);
    }

    if (A->b14c != 0 || B->b14c != 0) {
        Mon *mon = DAT_004dd700->f4c;
        a5.mag = 0.0f;
        int ai = A->FUN_001d82d0();
        if (ai >= 0) {
            if (((owners::Thing_7a820 *)mon)->FUN_0007a820(ai) > 15.0f)
                a5.mag = ((owners::Obj_1afb00 *)A)->FUN_001afb00();
        }
        int bi = B->FUN_001d82d0();
        if (bi >= 0) {
            if (((owners::Thing_7a820 *)mon)->FUN_0007a820(bi) > 15.0f)
                a5.mag = ((owners::Obj_1afb00 *)B)->FUN_001afb00();
        }
        if (a5.mag > 0.0f) {
            int m = (int)a5.mag;
            A->FUN_001d6ec0(m, 0, 0);
            B->FUN_001d6ec0(m, 0, 0);
        }
    }

    if (A->b14d != 0 || B->b14d != 0) {
        a5.mon = DAT_004dd700->f4c;
        if (A->b14d != 0 && h1->f6c == 0) {
            Hit_1b1e90 *q = ((Hit_1b1e90 *)((owners::Obj_7ad00 *)(a5.mon))->FUN_0007ad00((hulk_intptr)(V3_1b1e90 *)(&A->v8)));
            if (q != 0) {
                if (h2->v50.FUN_000111f0() > 16.0f && B->b14d == 0)
                    q->FUN_00083320(arg3, dir, arg6, 1, &h2->v50, 1);
                else {
                    f.n1.x = 0.0f;
                    f.n1.y = 0.0f;
                    f.n1.z = 0.0f;
                    q->FUN_00083320(arg3, dir, arg6, 0, &f.n1, 1);
                }
            }
        }
        if (B->b14d != 0 && h2->f6c == 0) {
            Hit_1b1e90 *q = ((Hit_1b1e90 *)((owners::Obj_7ad00 *)(a5.mon))->FUN_0007ad00((hulk_intptr)(V3_1b1e90 *)(&B->v8)));
            if (q != 0) {
                if (h1->v50.FUN_000111f0() > 16.0f && A->b14d == 0) {
                    f.n1.x = -dir->x;
                    f.n1.y = -dir->y;
                    f.n1.z = -dir->z;
                    q->FUN_00083320(arg4, &f.n1, arg6, 1, &h1->v50, 1);
                } else {
                    f.n2.x = -dir->x;
                    f.n2.y = -dir->y;
                    f.n2.z = -dir->z;
                    f.n1.x = 0.0f;
                    f.n1.y = 0.0f;
                    f.n1.z = 0.0f;
                    q->FUN_00083320(arg4, &f.n2, arg6, 0, &f.n1, 1);
                }
            }
        }
    }

    if (A->FUN_001d6a80() && B->FUN_001d6a80())
        return 1;
    if (A->FUN_001d6a80()) {
        if (B->FUN_001d7300()) {
            f.n1.x = dir->x * arg6;
            f.n1.y = dir->y * arg6;
            f.n1.z = dir->z * arg6;
            Pos_1b1e90 *p = B->FUN_001d6b40();
            V3_1b1e90 t;
            t.x = f.n1.x + p->x;
            t.y = f.n1.y + p->y;
            t.z = f.n1.z + p->z;
            B->FUN_001d7810(t);
        }
        return 1;
    }
    if (B->FUN_001d6a80()) {
        if (A->FUN_001d7300()) {
            hulk_freg ns = -arg6;
            f.n1.x = dir->x * ns;
            f.n1.y = dir->y * ns;
            f.n1.z = dir->z * ns;
            Pos_1b1e90 *p = A->FUN_001d6b40();
            V3_1b1e90 t;
            t.x = f.n1.x + p->x;
            t.y = f.n1.y + p->y;
            t.z = f.n1.z + p->z;
            A->FUN_001d7810(t);
        }
        return 1;
    }

    if (A->f134 != 0)
        A->f134->FUN_0001b510(h2, arg4, dir, 2);
    if (B->f134 != 0) {
        f.n1.x = dir->x * -1.0f;
        f.n1.y = dir->y * -1.0f;
        f.n1.z = dir->z * -1.0f;
        B->f134->FUN_0001b510(h1, arg3, &f.n1, 2);
    }
    u64_1b1e90 want = (*(u64_1b1e90*)&DAT_004dc0e0);
    if (A->f114 != 0 && A->f114->f0c == 1 && A->f114->f08->id == want)
        return 1;
    if (B->f114 != 0 && B->f114->f0c == 1 && B->f114->f08->id == want)
        return 1;
    A->FUN_0027d4f0(7);
    B->FUN_0027d4f0(7);
    if (A->FUN_001d77c0()->FUN_00018990() > 5.0f)
        DAT_004dd700->f34->FUN_001ebd80(A, "impact_sml", 100.0f, 0);
    if (B->FUN_001d77c0()->FUN_00018990() > 5.0f)
        DAT_004dd700->f34->FUN_001ebd80(B, "impact_sml", 100.0f, 0);
    return f.result;
}
} // namespace fn_001b1e90
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001b2e50 FUN_001b2e50 (462 B): equivalent/0x001b2e50.cpp [wrapped: conflict: AICollisionSolverAgent; FUN_001afab0; Function; Function2]
// sym: ??0AICollisionSolverAgent@fn_001b2e50@@QAE@XZ @4fb0f4826ded @wa7951b050665
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_001b2e50 {
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// FUN_001b2e50 @ 0x001b2e50
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

extern "C" void* __cdecl FUN_0008d690(unsigned int size);
extern "C" void* __cdecl FUN_001d4c90();
extern "C++" __declspec(nothrow) void __cdecl FUN_001afa70(float, float);
extern "C++" __declspec(nothrow) void __cdecl FUN_001afa90(float, float);
extern "C++" __declspec(nothrow) void __cdecl FUN_001afab0(float, float);
extern "C++" __declspec(nothrow) void __cdecl FUN_001afad0(const char*, float);


template <class T> struct TypeName;
template <> struct TypeName<void> { static const char* get() { return ((const char*)&DAT_0048e100); } };
template <> struct TypeName<float> { static const char* get() { return ((const char*)&DAT_0048e128); } };
template <> struct TypeName<const char*> { static const char* get() { return ((const char*)&DAT_0048e0f0); } };

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) Function : public ScriptFunctionFields {
  public:
    virtual void f0();
    virtual void f1();
    void FUN_001d0480(const char*, int);
    Function(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class R, class A, class B>
class Function2 : public Function {
  public:
    typedef R (__cdecl *Fn)(A, B);
    Function2(const char* name, Fn f) : Function(name, 2) {
        fn = f;
        retType = FUN_001d04d0(TypeName<R>::get());
        argTypes[0] = FUN_001d04d0(TypeName<A>::get());
        argTypes[1] = FUN_001d04d0(TypeName<B>::get());
    }
    Fn fn;
};

struct Registry_1b2e50 { void FUN_001d3b70(const char*, void*); };

class __declspec(novtable) CollisionSolverAgent_1b2e50 {
  public:
    virtual void f0_00018b30();
    void FUN_002f8800();
    CollisionSolverAgent_1b2e50() { FUN_002f8800(); }
};

class AICollisionSolverAgent : public CollisionSolverAgent_1b2e50 {
  public:
    AICollisionSolverAgent();
    virtual void f1_00018b40();
    virtual void* f2_001b02e0(char);
    virtual void f3_002f7d00(int, int);
    virtual void f4_002f7d20(int, int);
    virtual int f5_001b2560(void*, void*);
    virtual int f6_001b0120(hulk_intptr, int, hulk_intptr, int, int, int, int, hulk_intptr, hulk_intptr);
    virtual int f7_001b2c90(void*, hulk_intptr);
    virtual int f8_002f8850(void*, int);
    virtual int f9_001b0fb0(void*, void*);
    virtual bool vfunc_10_001b0180(void*, void*);
    virtual char f11_001b0210(void*);
};

AICollisionSolverAgent::AICollisionSolverAgent() {
    Registry_1b2e50* reg = (Registry_1b2e50*)FUN_001d4c90();
    if (reg) {
        typedef Function2<void, float, float> FunctionFF;
        HULK_SIZE32(FunctionFF, 0x20);
        typedef Function2<void, const char*, float> FunctionSF;
        HULK_SIZE32(FunctionSF, 0x20);
        void* mem = FUN_0008d690((int)sizeof(Function2<void, float, float>));
        Function2<void, float, float>* a = 0;
        if (mem) a = new (mem) Function2<void, float, float>("phy_SetCharVsSmallPropDamage", FUN_001afa70);
        reg->FUN_001d3b70("phy_SetCharVsSmallPropDamage", a);
        mem = FUN_0008d690((int)sizeof(Function2<void, float, float>));
        Function2<void, float, float>* b = 0;
        if (mem) b = new (mem) Function2<void, float, float>("phy_SetCharVsLargePropDamage", FUN_001afa90);
        reg->FUN_001d3b70("phy_SetCharVsLargePropDamage", b);
        mem = FUN_0008d690((int)sizeof(Function2<void, float, float>));
        Function2<void, float, float>* c = 0;
        if (mem) c = new (mem) Function2<void, float, float>("phy_SetCharVsHeavyPropDamage", FUN_001afab0);
        reg->FUN_001d3b70("phy_SetCharVsHeavyPropDamage", c);
        mem = FUN_0008d690((int)sizeof(Function2<void, const char*, float>));
        Function2<void, const char*, float>* d = 0;
        if (mem) d = new (mem) Function2<void, const char*, float>("phy_SetElectrifiedDamage", FUN_001afad0);
        reg->FUN_001d3b70("phy_SetElectrifiedDamage", d);
    }
}
} // namespace fn_001b2e50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

