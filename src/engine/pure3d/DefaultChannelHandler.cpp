// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028e0c0..0x0028edb0 (kind game, layer engine, confidence medium), dominant class pure3d::DefaultChannelHandler
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fc71db16 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fc71db16 {} using namespace fn_fc71db16;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fc71db16 {
void *__cdecl FUN_0008d690(unsigned int size);
struct Stream {
    int FUN_002647e0(void *buf, int count, int size, int flag);
};
class Reader {
public:
    char pad0[0x284];
    Stream *stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
};
struct Prim_28e160 {
    char pad00[4];
    int f4;
    int f8;
    char padc[8];
    void *f14;
    void *f18;
};
struct Parent_28e160;
struct Frame_28e160 {
    int l14, l10, lc, l8, l4;
};
struct Mem_28e160 {
    Prim_28e160 *FUN_0028c0b0(int count, Parent_28e160 *p);
    Prim_28e160 *FUN_0028d150(int count, Parent_28e160 *p);
    Prim_28e160 *FUN_0028d490(int count, Parent_28e160 *p);
    Prim_28e160 *FUN_0028d750(int count, Parent_28e160 *p);
    Prim_28e160 *FUN_0028dae0(int count, Parent_28e160 *p);
};
struct Parent_28e160 {
};
} // namespace fn_fc71db16
inline void* operator new(size_t, void* p) {
    return p;
}
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memmove(void*, const void*, unsigned);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memset(void*, int, unsigned);
#endif
namespace fn_fc71db16 {
void* Alloc_0008d690(hulk_uintptr n);
class ChannelHandler_28e9b0 {
  public:
    ChannelHandler_28e9b0() { a = 0; }
    virtual void f0();
    int a;
};
class DefaultChannelHandler_28e9b0 : public ChannelHandler_28e9b0 {
  public:
    virtual void f0();
};
class NonCopyable_28e9b0 {
  public:
    NonCopyable_28e9b0() { a = 0; }
    virtual void f0();
    int a;
};
class ChannelLoader : public NonCopyable_28e9b0 {
  public:
    ChannelLoader();
    virtual void f0();
    int count;
    DefaultChannelHandler_28e9b0* tbl[16];
};
struct Channel_28ec30 { unsigned FUN_00266c30(); };
} // namespace fn_fc71db16
namespace pure3d {
struct DefaultChannelHandler_nv_28ec30 {
    int FUN_0028c580(Channel_28ec30*,void*,void*);
    int FUN_0028c6b0(Channel_28ec30*,void*,void*);
    int FUN_0028c7e0(Channel_28ec30*,void*,void*);
    int FUN_0028c910(Channel_28ec30*,void*,void*);
    int FUN_0028e160(Channel_28ec30*,void*,void*);
    int FUN_0028cd80(Channel_28ec30*,void*,void*);
    int FUN_0028ea80(Channel_28ec30*,void*,void*);
    int FUN_0028ceb0(Channel_28ec30*,void*,void*);
    int FUN_0028cfd0(Channel_28ec30*,void*,void*);
};
}


// 0x0028e0c0 pure3d::QuaternionChannel::vfunc_0 (30 B): matches/0x0028e0c0.cpp
// sym: ??_GQuaternionChannel@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::QuaternionChannel::~QuaternionChannel() {}


// 0x0028e0e0 pure3d::StringChannel::vfunc_0 (30 B): matches/0x0028e0e0.cpp
// sym: ??_GStringChannel@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::StringChannel::~StringChannel() {}


// 0x0028e100 pure3d::EntityChannel::vfunc_0 (30 B): matches/0x0028e100.cpp
// sym: ??_GEntityChannel@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::EntityChannel::~EntityChannel() {}


// 0x0028e120 pure3d::BoolChannel::vfunc_0 (30 B): matches/0x0028e120.cpp
// sym: ??_GBoolChannel@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::BoolChannel::~BoolChannel() {}


// 0x0028e140 pure3d::ColourChannel::vfunc_0 (30 B): matches/0x0028e140.cpp
// sym: ??_GColourChannel@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::ColourChannel::~ColourChannel() {}

namespace fn_fc71db16 {

// 0x0028e160 FUN_0028e160 (2075 B): equivalent/0x0028e160.cpp
// sym: ?FUN_0028e160@fn_fc71db16@@YGPAUPrim_28e160@1@PAVReader@1@HPAUParent_28e160@1@@Z @e744502806f8 @w2e580b65e337
// STATUS: equivalent (tools/equiv.py level 3: 20158 inputs, branch coverage 84/84)
// FUN_0028e160 @ 0x0028e160
Prim_28e160 *__stdcall FUN_0028e160(Reader *R, int unused, Parent_28e160 *parent)
{
    Frame_28e160 f;
    Reader *Rr = R;
    Parent_28e160 *par = parent;
    int *pcount = (int *)&R;        // the first argument slot is reused for counts
    int *pval = (int *)&parent;     // and the third for the chunk values
    int count;
    Prim_28e160 *obj;
    int id = Rr->FUN_00266c30() - 0x121105;
    if ((unsigned int)id > 0xf)
        return 0;
    if (id == 0) {
        Rr->stream->FUN_002647e0(&f.l10, 1, 4, 1);
        Rr->stream->FUN_002647e0(&f.l14, 1, 4, 1);
        Rr->stream->FUN_002647e0(pcount, 1, 4, 1);
        count = *pcount;
        if (par == 0) {
            Mem_28e160 *m = (Mem_28e160 *)FUN_0008d690(0x1c);
            obj = m ? m->FUN_0028c0b0(count, 0) : 0;
        } else {
            Mem_28e160 *m = ((Mem_28e160 *)((owners::C_2888c0 *)par)->FUN_002888c0(0x1c, 7));
            obj = m ? m->FUN_0028c0b0(count, par) : 0;
        }
        obj->f8 = f.l14;
        Rr->stream->FUN_002647e0(obj->f14, count, 2, 1);
        Rr->stream->FUN_002647e0(obj->f18, count * 4, 4, 1);
        if (f.l10 != 1) {
            // The original unrolls this loop 4x and keeps the unrolled part's
            // bound in the dead `parent` slot, which the chunk loop below
            // later uses as its read buffer (a read from a closed stream
            // leaves it unwritten, and obj->f4 then gets this bound).
            if (count >= 4)
                *pval = (int)(((unsigned int)(count - 4) >> 2) + 1) * 4;
            for (unsigned int i = 0; i < (unsigned int)count; i++) {
                int *p = (int *)((char *)obj->f18 + i * 16);
                f.l10 = p[0];
                f.lc = p[1];
                int e2 = p[2];
                f.l4 = p[3];
                p = (int *)((char *)obj->f18 + i * 16);
                p[0] = f.lc;
                f.l8 = e2;
                ((float *)p)[1] = *(float *)&f.l8;
                ((float *)p)[2] = *(float *)&f.l4;
                ((float *)p)[3] = *(float *)&f.l10;
            }
        }
    } else if (id == 12) {
        Rr->stream->FUN_002647e0(&f.l14, 1, 4, 1);
        Rr->stream->FUN_002647e0(&f.l10, 1, 4, 1);
        Rr->stream->FUN_002647e0(pcount, 1, 4, 1);
        count = *pcount;
        if (par == 0) {
            Mem_28e160 *m = (Mem_28e160 *)FUN_0008d690(0x1c);
            obj = m ? m->FUN_0028d150(count, 0) : 0;
        } else {
            Mem_28e160 *m = ((Mem_28e160 *)((owners::C_2888c0 *)par)->FUN_002888c0(0x1c, 7));
            obj = m ? m->FUN_0028d150(count, par) : 0;
        }
        obj->f8 = f.l10;
        Rr->stream->FUN_002647e0(obj->f14, count, 2, 1);
        Rr->stream->FUN_002647e0(obj->f18, count * 4, 2, 1);
        if (f.l14 != 1) {
            for (unsigned int i = 0; i < (unsigned int)count; i++) {
                unsigned int lo = ((unsigned int *)obj->f18)[i * 2];
                f.lc = ((unsigned int *)obj->f18)[i * 2 + 1];
                unsigned short *w = (unsigned short *)obj->f18;
                w[i * 4 + 0] = (unsigned short)(lo >> 16);
                w[i * 4 + 1] = (unsigned short)f.lc;
                w[i * 4 + 2] = (unsigned short)((unsigned int)f.lc >> 16);
                w[i * 4 + 3] = (unsigned short)lo;
                f.l10 = lo;
            }
        }
    } else if (id == 13) {
        Rr->stream->FUN_002647e0(pcount, 1, 4, 1);
        Rr->stream->FUN_002647e0(&f.l10, 1, 4, 1);
        Rr->stream->FUN_002647e0(pcount, 1, 4, 1);
        count = *pcount;
        if (par == 0) {
            Mem_28e160 *m = (Mem_28e160 *)FUN_0008d690(0x1c);
            obj = m ? m->FUN_0028d490(count, 0) : 0;
        } else {
            Mem_28e160 *m = ((Mem_28e160 *)((owners::C_2888c0 *)par)->FUN_002888c0(0x1c, 7));
            obj = m ? m->FUN_0028d490(count, par) : 0;
        }
        obj->f8 = f.l10;
        Rr->stream->FUN_002647e0(obj->f14, count, 2, 1);
        Rr->stream->FUN_002647e0(obj->f18, count * 3, 2, 1);
    } else if (id == 14) {
        Rr->stream->FUN_002647e0(pcount, 1, 4, 1);
        Rr->stream->FUN_002647e0(&f.l10, 1, 4, 1);
        Rr->stream->FUN_002647e0(pcount, 1, 4, 1);
        count = *pcount;
        if (par == 0) {
            Mem_28e160 *m = (Mem_28e160 *)FUN_0008d690(0x1c);
            obj = m ? m->FUN_0028d750(count, 0) : 0;
        } else {
            Mem_28e160 *m = ((Mem_28e160 *)((owners::C_2888c0 *)par)->FUN_002888c0(0x1c, 7));
            obj = m ? m->FUN_0028d750(count, par) : 0;
        }
        obj->f8 = f.l10;
        Rr->stream->FUN_002647e0(obj->f14, count, 2, 1);
        Rr->stream->FUN_002647e0(obj->f18, count, 4, 1);
    } else if (id == 15) {
        Rr->stream->FUN_002647e0(pcount, 1, 4, 1);
        Rr->stream->FUN_002647e0(&f.l10, 1, 4, 1);
        Rr->stream->FUN_002647e0(pcount, 1, 4, 1);
        count = *pcount;
        if (par == 0) {
            Mem_28e160 *m = (Mem_28e160 *)FUN_0008d690(0x1c);
            obj = m ? m->FUN_0028dae0(count, 0) : 0;
        } else {
            Mem_28e160 *m = ((Mem_28e160 *)((owners::C_2888c0 *)par)->FUN_002888c0(0x1c, 7));
            obj = m ? m->FUN_0028dae0(count, par) : 0;
        }
        obj->f8 = f.l10;
        Rr->stream->FUN_002647e0(obj->f14, count, 2, 1);
        Rr->stream->FUN_002647e0(obj->f18, count * 3, 1, 1);
    } else {
        return 0;
    }
    while (Rr->FUN_002669f0()) {
        if (Rr->FUN_00266a30() == 0x121110) {
            Rr->stream->FUN_002647e0(pcount, 1, 4, 1);
            Rr->stream->FUN_002647e0(pval, 1, 4, 1);
            obj->f4 = *pval;
        }
        Rr->FUN_00266be0();
    }
    return obj;
}


// 0x0028e9b0 FUN_0028e9b0 (105 B): matches/0x0028e9b0.cpp
// sym: ??0ChannelLoader@fn_fc71db16@@QAE@XZ
ChannelLoader::ChannelLoader() {
    count = 0;
    memset(tbl, 0, 64);
    DefaultChannelHandler_28e9b0* h = new (Alloc_0008d690(8)) DefaultChannelHandler_28e9b0;
    if (h) {
        memmove(&tbl[1], &tbl[0], count << 2);
        tbl[0] = h;
        h->f0();
        count++;
    }
}

} // namespace fn_fc71db16

// 0x0028ec30 pure3d::DefaultChannelHandler::vfunc_4 (282 B): equivalent/0x0028ec30.cpp
// sym: ?vfunc_4@DefaultChannelHandler@pure3d@@UAEHHHH@Z @5f9577ff195b @w2f353f5ab810
// STATUS: equivalent (tools/equiv.py level 3: 20024 inputs, branch coverage 12/12)
// pure3d::DefaultChannelHandler::vfunc_4 @ 0x0028ec30
int pure3d::DefaultChannelHandler::vfunc_4(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { Channel_28ec30 * c = (Channel_28ec30 *)__p0; void * a = (void *)__p1; void * b = (void *)__p2;

unsigned index = c->FUN_00266c30() - 0x121100;
if(index > 20) return 0;
switch(index) {
case 14: return ((DefaultChannelHandler_nv_28ec30*)this)->FUN_0028c580(c,a,b);
case 0: return ((DefaultChannelHandler_nv_28ec30*)this)->FUN_0028c6b0(c,a,b);
case 1: return ((DefaultChannelHandler_nv_28ec30*)this)->FUN_0028c7e0(c,a,b);
case 2: case 3: case 4: return ((DefaultChannelHandler_nv_28ec30*)this)->FUN_0028c910(c,a,b);
case 5: case 17: case 18: case 19: case 20: return ((DefaultChannelHandler_nv_28ec30*)this)->FUN_0028e160(c,a,b);
case 6: return ((DefaultChannelHandler_nv_28ec30*)this)->FUN_0028cd80(c,a,b);
case 7: return ((DefaultChannelHandler_nv_28ec30*)this)->FUN_0028ea80(c,a,b);
case 8: return ((DefaultChannelHandler_nv_28ec30*)this)->FUN_0028ceb0(c,a,b);
case 9: return ((DefaultChannelHandler_nv_28ec30*)this)->FUN_0028cfd0(c,a,b);
default: return 0;
}
}

