// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002e5a70..0x002e6550 (kind game, layer engine, confidence medium), dominant class pure3d::VertexAnimKeyFrame
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f411a916 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f411a916 {} using namespace fn_f411a916;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f411a916 {
extern void* g_vt_2e5a70[];
extern void* g_b_2e5a70[];
} // namespace fn_f411a916
void operator delete(void*);
namespace fn_f411a916 {
struct S_2e5a70 {
    void Fini() throw();
};
struct E_2e5a70 {
    char pad[4];
    S_2e5a70 s;
    char pad2[7];
};
struct VE {
    E_2e5a70* b;
    E_2e5a70* e;
    E_2e5a70* c;
    void Fini() throw() {
        if (b) {
            E_2e5a70* p = b;
            E_2e5a70* end = e;
            while (p != end) {
                p->s.Fini();
                p++;
            }
            operator delete(b);
        }
    }
};
struct VP {
    void* b;
    char pad[8];
    void Fini() throw() {
        if (b)
            operator delete(b);
    }
};
class VertexAnimKeyFrame_2e5a70 {
  public:
    void* vptr;
    char pad[0x10];
    void* m14;
    char pad2[8];
    void* m20;
    char pad3[0x2c - 0x24];
    VP a[4];
    VE v[2];
    void f();
};
extern "C" void *FUN_0008d690(unsigned int size);
struct Quad_2e5b20 {
    unsigned short s[4];
    void FUN_002c6d30();
    void FUN_002c6d50();
};
struct ElemC {
    unsigned int id;
    Quad_2e5b20 q;
};
struct ElemF {
    unsigned int id;
    float v[2];
};
struct ElemV {
    unsigned int id;
    float v[3];
};
struct VecC {
    ElemC *begin;
    ElemC *end;
    int pad8;
    char FUN_002e5700(unsigned int n, const ElemC *def);
};
struct VecF {
    ElemF *begin;
    ElemF *end;
    int pad8;
    char FUN_002e56a0(unsigned int n, const ElemF *def);
};
struct VecV {
    ElemV *begin;
    ElemV *end;
    int pad8;
    char FUN_002e5640(unsigned int n, const ElemV *def);
};
class VertexAnimKeyFrame_2e5b20 {
public:
    virtual void v0();
    char pad04[4];
    unsigned int f08;
    unsigned int f0c;
    unsigned int flags;
    VecV pos;
    VecV nrm;
    VecF vu0;
    VecF vu1;
    VecF vu2;
    VecF vu3;
    VecC clr0;
    VecC clr1;
    VertexAnimKeyFrame_2e5b20 *FUN_002e5a10();
};
struct Frame_2e5b20 {
    VertexAnimKeyFrame_2e5b20 *mesh;       // 8
    unsigned int c12; // 12
    unsigned int remain;
    unsigned int c20, c24, c28, c32, c36, c40;
    unsigned int u44;
    unsigned int t48, t52, t56, t60, t64, t68, t72, t76, t80, t84, t88, t92, t96, t100;
    ElemC clr1; // 104
    union {
        ElemC e12;
        ElemF f12;
        ElemV e16;
    } d;
};
extern "C" void* __cdecl FUN_0008d6d0(unsigned int size);
extern "C" void __cdecl FUN_002e59b0(void* data, unsigned int count, int value);
void thunk_FUN_00267090(hulk_intptr);
struct Obj_2e6210 {
    int a;
    int b;
};
extern "C" void __cdecl FUN_002e61c0(int *, int *);
} // namespace fn_f411a916
inline void* operator new(size_t, void* p) throw() { return p; }
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memset(void* dst, int c, unsigned int n);
#endif
namespace fn_f411a916 {
class RefCounted_2e6340 {
public:
    virtual void AddRef();
    virtual void Release();
    int pad04;
    int id;
};
struct Track {
    RefCounted_2e6340** begin;
    RefCounted_2e6340** end;
    int cap;
};
struct KeyVec {
    unsigned int* begin;
    unsigned int* end;
    int cap;
};
struct TrackVec {
    Track* begin;
    Track* end;
    int cap;
};
struct Parent;
} // namespace fn_f411a916
namespace pure3d {
class VertexAnimKeyFrameList_2e6340 {
public:
    virtual void v0();
    int field04;
    KeyVec keys;
    TrackVec tracks;

    VertexAnimKeyFrameList_2e6340()
    {
        field04 = 0;
        keys.begin = 0;
        keys.end = 0;
        tracks.begin = 0;
        tracks.end = 0;
    }

    void FUN_002e5330(int key, unsigned int* index);
};
}
namespace fn_f411a916 {
struct Reader {
  public:
    char _m_pad_0[0x284];
    Stream* stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
};
struct Stream {
  public:
    char _m_pad_0[0x284];
    Reader *reader;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};
class KeyFrameLoader {
public:
    RefCounted_2e6340* FUN_002e5b20(Reader* r, Parent* parent);
    pure3d::VertexAnimKeyFrameList_2e6340* FUN_002e6340(Reader* r, Parent* parent);
};


// 0x002e5a70 FUN_002e5a70 (163 B): matches/0x002e5a70.cpp
// sym: ?f@VertexAnimKeyFrame_2e5a70@fn_f411a916@@QAEXXZ
void VertexAnimKeyFrame_2e5a70::f() {
    vptr = g_vt_2e5a70;
    {
        VE* p = v + 2;
        int n = 2;
        do {
            --p;
            p->Fini();
        } while (--n);
    }
    {
        VP* p = a + 4;
        int n = 4;
        do {
            --p;
            p->Fini();
        } while (--n);
    }
    if (m20)
        operator delete(m20);
    if (m14)
        operator delete(m14);
    vptr = g_b_2e5a70;
}


// 0x002e5b20 FUN_002e5b20 (1596 B): equivalent/0x002e5b20.cpp
// sym: ?FUN_002e5b20@fn_f411a916@@YGPAVVertexAnimKeyFrame_2e5b20@1@PAUStream@1@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 223 inputs, branch coverage 60/62, incomplete)
// FUN_002e5b20 @ 0x002e5b20
VertexAnimKeyFrame_2e5b20 *__stdcall FUN_002e5b20(Stream *s, int unused)
{
    Frame_2e5b20 f;
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.t88), (hulk_intptr)1, 4, (hulk_intptr)1);
    void *mem = FUN_0008d690((int)sizeof(VertexAnimKeyFrame_2e5b20));
    VertexAnimKeyFrame_2e5b20 *m;
    if (mem != 0) {
        m = ((VertexAnimKeyFrame_2e5b20 *)mem)->FUN_002e5a10();
        f.mesh = m;
    } else {
        f.mesh = 0;
        m = f.mesh;
    }
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.u44), (hulk_intptr)1, 4, (hulk_intptr)1);
    m->f08 = f.u44;
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.u44), (hulk_intptr)1, 4, (hulk_intptr)1);
    m->f0c = f.u44;
    while (s->FUN_002669f0()) {
        int id = s->FUN_00266a30() - 0x10f00;
        if (id == 0) {
            ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.t100), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.t80), (hulk_intptr)1, 4, (hulk_intptr)1);
            if (f.t80 == 0x534f50) {
                ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.u44), (hulk_intptr)1, 4, (hulk_intptr)1);
                unsigned int n = f.u44;
                m->pos.FUN_002e5640(n, &f.d.e16);
                if (n > 0) {
                    unsigned int rem = f.u44;
                    unsigned int i = 0;
                    do {
                        ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.t88), (hulk_intptr)1, 4, (hulk_intptr)1);
                        m->pos.begin[i].id = f.t88;
                        ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(m->pos.begin[i].v), (hulk_intptr)3, 4, (hulk_intptr)1);
                        i++;
                    } while (--rem != 0);
                }
                m->flags |= 0x10;
            } else if (f.t80 == 0x4c4d524e) {
                ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.c40), (hulk_intptr)1, 4, (hulk_intptr)1);
                unsigned int n = f.c40;
                m->nrm.FUN_002e5640(n, &f.d.e16);
                if (n > 0) {
                    unsigned int rem = f.c40;
                    unsigned int i = 0;
                    do {
                        ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.t84), (hulk_intptr)1, 4, (hulk_intptr)1);
                        m->nrm.begin[i].id = f.t84;
                        ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(m->nrm.begin[i].v), (hulk_intptr)3, 4, (hulk_intptr)1);
                        i++;
                    } while (--rem != 0);
                }
                m->flags |= 0x20;
            }
        } else if (id == 1) {
            ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.t96), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.t60), (hulk_intptr)1, 4, (hulk_intptr)1);
            if (f.t60 == 0x325655) {
                ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.c32), (hulk_intptr)1, 4, (hulk_intptr)1);
                unsigned int n = f.c32;
                m->vu2.FUN_002e56a0(n, &f.d.f12);
                if (n > 0) {
                    f.remain = f.c32;
                    unsigned int i = 0;
                    do {
                        ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.t72), (hulk_intptr)1, 4, (hulk_intptr)1);
                        m->vu2.begin[i].id = f.t72;
                        ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(m->vu2.begin[i].v), (hulk_intptr)2, 4, (hulk_intptr)1);
                        i++;
                        f.remain--;
                    } while (f.remain != 0);
                }
                m->flags |= 4;
            } else if (f.t60 == 0x305655) {
                ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.c28), (hulk_intptr)1, 4, (hulk_intptr)1);
                unsigned int n = f.c28;
                m->vu0.FUN_002e56a0(n, &f.d.f12);
                if (n > 0) {
                    f.remain = f.c28;
                    unsigned int i = 0;
                    do {
                        ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.t68), (hulk_intptr)1, 4, (hulk_intptr)1);
                        m->vu0.begin[i].id = f.t68;
                        ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(m->vu0.begin[i].v), (hulk_intptr)2, 4, (hulk_intptr)1);
                        i++;
                        f.remain--;
                    } while (f.remain != 0);
                }
                m->flags |= 1;
            } else if (f.t60 == 0x315655) {
                ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.c24), (hulk_intptr)1, 4, (hulk_intptr)1);
                unsigned int n = f.c24;
                m->vu1.FUN_002e56a0(n, &f.d.f12);
                if (n > 0) {
                    f.remain = f.c24;
                    unsigned int i = 0;
                    do {
                        ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.t64), (hulk_intptr)1, 4, (hulk_intptr)1);
                        m->vu1.begin[i].id = f.t64;
                        ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(m->vu1.begin[i].v), (hulk_intptr)2, 4, (hulk_intptr)1);
                        i++;
                        f.remain--;
                    } while (f.remain != 0);
                }
                m->flags |= 2;
            } else if (f.t60 == 0x335655) {
                ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.c36), (hulk_intptr)1, 4, (hulk_intptr)1);
                unsigned int n = f.c36;
                m->vu3.FUN_002e56a0(n, &f.d.f12);
                if (n > 0) {
                    f.remain = f.c36;
                    unsigned int i = 0;
                    do {
                        ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.t76), (hulk_intptr)1, 4, (hulk_intptr)1);
                        m->vu3.begin[i].id = f.t76;
                        ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(m->vu3.begin[i].v), (hulk_intptr)2, 4, (hulk_intptr)1);
                        i++;
                        f.remain--;
                    } while (f.remain != 0);
                }
                m->flags |= 8;
            }
        } else if (id == 2) {
            ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.t92), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.t48), (hulk_intptr)1, 4, (hulk_intptr)1);
            if (f.t48 == 0x30524c43) {
                ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.c20), (hulk_intptr)1, 4, (hulk_intptr)1);
                f.d.e12.q.FUN_002c6d30();
                unsigned int n = f.c20;
                m->clr0.FUN_002e5700(n, &f.d.e12);
                f.d.e12.q.FUN_002c6d50();
                if (n > 0) {
                    f.remain = f.c20;
                    unsigned int i = 0;
                    do {
                        ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.t56), (hulk_intptr)1, 4, (hulk_intptr)1);
                        m->clr0.begin[i].id = f.t56;
                        ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&m->clr0.begin[i].q), (hulk_intptr)4, 2, (hulk_intptr)1);
                        i++;
                        f.remain--;
                    } while (f.remain != 0);
                }
                m->flags |= 0x40;
            } else if (f.t48 == 0x31524c43) {
                ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.c12), (hulk_intptr)1, 4, (hulk_intptr)1);
                f.clr1.q.FUN_002c6d30();
                unsigned int n = f.c12;
                m->clr1.FUN_002e5700(n, &f.clr1);
                f.clr1.q.FUN_002c6d50();
                if (n > 0) {
                    f.remain = f.c12;
                    unsigned int i = 0;
                    do {
                        ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.t52), (hulk_intptr)1, 4, (hulk_intptr)1);
                        m->clr1.begin[i].id = f.t52;
                        ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&m->clr1.begin[i].q), (hulk_intptr)4, 2, (hulk_intptr)1);
                        i++;
                        f.remain--;
                    } while (f.remain != 0);
                }
                m->flags |= 0x80;
            }
        }
        s->FUN_00266be0();
    }
    return m;
}

} // namespace fn_f411a916

// 0x002e6160 FUN_002e6160 (94 B): equivalent/0x002e6160.cpp
// sym: ?FUN_002e6160@Buffer_2e6160@owners@@QAE_NIH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002e6160 @ 0x002e6160
bool owners::Buffer_2e6160::FUN_002e6160(unsigned int count, hulk_intptr value) {
    if (data) return false;
    if (count) {
        void* p = FUN_0008d6d0(count * 12);
        data = p;
        if (p) {
            end = (char*)p + count * 12;
            FUN_002e59b0(p, count, ((int)value));
            return true;
        }
    }
    data = 0;
    end = 0;
    return false;
}

namespace fn_f411a916 {

// 0x002e61c0 FUN_002e61c0 (41 B): matches/0x002e61c0.cpp
// sym: _FUN_002e61c0
extern "C" void FUN_002e61c0(int* first, int* last) {
    for (; first != last; first += 3) {
        if (*first != 0)
            thunk_FUN_00267090(*first);
    }
}

} // namespace fn_f411a916

// 0x002e61f0 pure3d::VertexAnimKeyFrame::vfunc_2 (30 B): matches/0x002e61f0.cpp
// sym: ??_GVertexAnimKeyFrame@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::VertexAnimKeyFrame::~VertexAnimKeyFrame() {}

namespace fn_f411a916 {

// 0x002e6210 FUN_002e6210 (32 B): matches/0x002e6210.cpp
// sym: ?target@fn_f411a916@@YIXPAUObj_2e6210@1@@Z
// Same code shape as 0x002907f0 (propagated; names are from that function)
void __fastcall target(Obj_2e6210* self) {
    if (self->a) {
        FUN_002e61c0((int *)(hulk_uintptr)(int)(self->a), (int *)(hulk_uintptr)(int)(self->b));
        g(self->a);
    }
}

} // namespace fn_f411a916

// 0x002e6270 FUN_002e6270 (208 B): equivalent/0x002e6270.cpp [wrapped: conflict: core::IRefCount; pure3d::VertexAnimKeyFrameList]
// sym: ??1VertexAnimKeyFrameList@pure3d@fn_002e6270@@QAE@XZ
namespace fn_002e6270 {
// STATUS: equivalent (tools/equiv.py level 3: 37 inputs, branch coverage 18/20, incomplete)
// FUN_002e6270 @ 0x002e6270
void __cdecl FUN_0008d340(void*) throw();
namespace core { struct IRefCount { virtual void slot0() throw(); virtual void slot1() throw(); ~IRefCount() throw() {} }; }
struct Item_2e6270 { virtual void slot0() throw(); virtual void slot1() throw(); };
struct Group_2e6270 { Item_2e6270** begin; Item_2e6270** end; Item_2e6270** capacity; };
namespace pure3d {
struct VertexAnimKeyFrameList : core::IRefCount {
 unsigned int refs; int* begin; int* end; int* capacity;
 Group_2e6270* groups; Group_2e6270* groupsEnd; Group_2e6270* groupsCapacity;
 virtual void slot0() throw(); virtual void slot1() throw();
 ~VertexAnimKeyFrameList() throw();
};
VertexAnimKeyFrameList::~VertexAnimKeyFrameList() throw() {
 unsigned int count=(unsigned int)(end-begin);
 for(unsigned int i=0;i<count;++i) {
  unsigned int n=(unsigned int)(groups[i].end-groups[i].begin);
  for(unsigned int j=0;j<n;++j) {
   Item_2e6270** slot=&groups[i].begin[j];
   if(*slot) { (*slot)->slot1(); *slot=0; }
  }
 }
 Group_2e6270* p=groups;
 if(p) {
  Group_2e6270* stop=groupsEnd;
  while(p!=stop) { if(p->begin) FUN_0008d340(p->begin); ++p; }
  FUN_0008d340(groups);
 }
 if(begin) FUN_0008d340(begin);
}
}
} // namespace fn_002e6270

namespace fn_f411a916 {

// 0x002e6340 FUN_002e6340 (518 B): equivalent/0x002e6340.cpp
// sym: ?FUN_002e6340@KeyFrameLoader@fn_f411a916@@QAEPAVVertexAnimKeyFrameList_2e6340@pure3d@@PAUReader@2@PAUParent@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 34 inputs, branch coverage 19/24, incomplete)
// FUN_002e6340 @ 0x002e6340
pure3d::VertexAnimKeyFrameList_2e6340* KeyFrameLoader::FUN_002e6340(Reader* r, Parent* parent)
{
    struct Frame {
        unsigned int scratch;
        unsigned int count;
        unsigned int offset;
        pure3d::VertexAnimKeyFrameList_2e6340* list;
        KeyFrameLoader* self;
        __int64 zeroFill;
        unsigned int spare;
        unsigned int counts[512];
    } f;

    f.self = this;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.scratch), (hulk_intptr)1, 4, (hulk_intptr)1);

    f.list = 0;
    void* mem = FUN_0008d690((int)sizeof(pure3d::VertexAnimKeyFrameList_2e6340));
    if (mem)
        f.list = new (mem) pure3d::VertexAnimKeyFrameList_2e6340();

    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.count), (hulk_intptr)1, 4, (hulk_intptr)1);

    unsigned int n = f.count;
    f.scratch = 0;
    ((owners::Buffer_2e16f0 *)&(f.list->keys))->FUN_002e16f0(n, (void *)(&f.scratch));
    f.zeroFill = 0;
    ((owners::Buffer_2e6160 *)&(f.list->tracks))->FUN_002e6160(n, (hulk_intptr)(&f.zeroFill));
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(f.list->keys.begin), (hulk_intptr)n, 4, (hulk_intptr)1);

    f.offset = 0;
    for (f.scratch = n; f.scratch != 0; f.scratch--, f.offset += sizeof(Track)) {
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.count), (hulk_intptr)1, 4, (hulk_intptr)1);
        Track* track = (Track*)((char*)f.list->tracks.begin + f.offset);
        if (track->begin == 0) {
            if (f.count == 0) {
                track->begin = 0;
                track->end = 0;
            } else {
                unsigned int bytes = f.count * 4;
                RefCounted_2e6340** p = (RefCounted_2e6340**)FUN_0008d6d0(bytes);
                track->begin = p;
                if (p == 0) {
                    track->begin = 0;
                    track->end = 0;
                } else {
                    track->end = (RefCounted_2e6340**)((char*)p + bytes);
                    for (unsigned int k = f.count; k != 0; k--, p++)
                        new (p) RefCounted_2e6340*(0);
                }
            }
        }
    }

    memset(f.counts, 0, sizeof(f.counts));
    f.scratch = 0;
    while (r->FUN_002669f0()) {
        if (r->FUN_00266a30() == 0x121306) {
            RefCounted_2e6340* obj = f.self->FUN_002e5b20(r, parent);
            f.list->FUN_002e5330(obj->id, &f.scratch);
            unsigned int* used = &f.counts[f.scratch];
            RefCounted_2e6340** slot = &f.list->tracks.begin[f.scratch].begin[*used];
            obj->AddRef();
            if (*slot)
                (*slot)->Release();
            *slot = obj;
            (*used)++;
        }
        r->FUN_00266be0();
    }
    return f.list;
}

} // namespace fn_f411a916
