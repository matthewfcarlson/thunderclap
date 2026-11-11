// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024e9e0..0x0024f7f0 (kind game, layer engine, confidence high), dominant class audio::ChannelSendVolumeFadeBehaviour
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f983a9d8 {
#define TREE_TU_END }
namespace fn_f983a9d8 {} using namespace fn_f983a9d8;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f983a9d8 {
class SeqAction_24ea70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class SeqAction_24ea80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
    virtual void f5();
    virtual void f6();
};
extern "C" char print_00246f50(const char*, const char*, ...);
extern "C" char other_0025abb0(const char**, const char*);
struct Stream {
  public:
    char _m_pad_0[0x24];
    union { int depth; int indent; };
};
struct Writer_24ebe0 {
    Stream *stream;
};
char __cdecl FUN_00246f50(Stream *s, const char *text, ...);
extern "C" char __cdecl FUN_0025aab0(Writer_24ebe0 *w, int value);
} // namespace fn_f983a9d8
namespace pure3d {
class NonCopyable_24ece0 : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_24ece0* f2(unsigned char);
};
}
namespace fn_f983a9d8 {
void thunk_FUN_00267090(pure3d::NonCopyable_24ece0*);
} // namespace fn_f983a9d8
extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int) throw();
namespace fn_f983a9d8 {
class Key {
    __int64 n;

  public:
    Key(__int64 v) : n(v) {}
    operator void*() { return &n; }
};
class FUN_00240060 {
    char pad[12];

  public:
    ~FUN_00240060() throw();
};
class FUN_002605e0 {
  public:
    FUN_002605e0(FUN_00240060*, void*, int, int) throw();
    virtual void f();
};
class SeqEventChannelSendVolumesType_24ed10 : public FUN_002605e0 {
  public:
    SeqEventChannelSendVolumesType_24ed10() throw();
    virtual void f();
};
extern void* hulk_at_004298fc[];
class SeqActionChannelSendVolumes_24edb0 {
  public:
    void* vptr;
    SeqActionChannelSendVolumes_24edb0* f0(unsigned char flags);
};
extern unsigned int FUN_00246f50(unsigned int, const char*, ...);
const char g_fmt[] = "%s ";
struct Temp_24f010 {
    char pad[12];
    void Init_0023fac0();
    int Value();
    int Finish_0023fb00();
};
extern "C" unsigned char __cdecl FUN_0025bce0(int, Temp_24f010*);
extern int __cdecl Convert_002673a0(int, int);
struct Writer_24f070 {
    Stream *out;
};
char FUN_0024ebe0(Writer_24f070 *w, float *value);
extern unsigned int GetSize_00247800();
extern unsigned int* Allocate_00247530(unsigned int);
struct Owner_24f180 {
    char pad[0x40];
    unsigned int* data;
};
class SeqEventChannelSendVolumes;
class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventChannelSendVolumes* f4(unsigned char flags);
};
class SeqEventChannelSendVolumes : public SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventChannelSendVolumes* f4(unsigned char flags);
};
void FUN_00247550(void* g, SeqEventChannelSendVolumes* p);
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int color;
    unsigned key;
};
struct Tree_24f280 {
    Node* root;
    Node nil;
};
struct Holder_24f280 {
    int prefix;
    Node node;
};
extern "C" void FUN_00247d50(Tree_24f280* tree, Node* node);
extern "C" void FUN_00247da0(Tree_24f280* tree, Node* node);
extern "C" unsigned char __cdecl FUN_0025aad0(void*, const unsigned char*);
class SeqEvent_24f600 {
  public:
    bool vfunc_0_0025fd20(void*);
};
extern "C" bool FUN_0025abd0(void*, void*);
extern bool ReadB_0024f010(void*, void*);
extern bool ReadC_0024f4a0(void*, void*);

// 0x0024e9e0 audio::SeqEventChannelSendVolumesType::vfunc_0 (5 B): not yet verified
// 0x0024e9f0 audio::SeqEventChannelSendVolumesType::vfunc_1 (5 B): not yet verified

// 0x0024ea00 FUN_0024ea00 (6 B): matches/0x0024ea00.cpp
// sym: _FUN_0024ea00
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e6750: a static om type (records.h)
extern "C" int* FUN_0024ea00() {
    return &(*(int*)&DAT_004e6750);
}


// 0x0024ea10 audio::SeqEventChannelSendVolumes::vfunc_3 (6 B): matches/0x0024ea10.cpp
// sym: _FUN_0024ea10
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e6750: a static om type (records.h)
extern "C" int* FUN_0024ea10() {
    return &(*(int*)&DAT_004e6750);
}

} // namespace fn_f983a9d8

// 0x0024ea30 audio::SeqActionChannelSendVolumes::vfunc_6 (34 B): matches/0x0024ea30.cpp
// sym: ?vfunc_6@SeqActionChannelSendVolumes@audio@@UAEXH@Z
void audio::SeqActionChannelSendVolumes::vfunc_6(hulk_intptr ) {
    int i = this->f_0c;
    --i;
    if (i != 0) {
        i -= 3;
        if (i != 0) {
            --i;
            if (i == 0)
                this->f_0c = 0;
            return;
        }
    }
    this->f_0c = 2;
}


// 0x0024ea60 audio::SeqActionChannelSendVolumes::vfunc_2 (10 B): matches/0x0024ea60.cpp
// sym: ?vfunc_2@SeqActionChannelSendVolumes@audio@@UAEXHH@Z
void audio::SeqActionChannelSendVolumes::vfunc_2(int , int ) {
    this->f_0c = 1;
}


// 0x0024ea70 audio::SeqActionChannelSendVolumes::vfunc_3 (10 B): matches/0x0024ea70.cpp
// sym: ?vfunc_3@SeqActionChannelSendVolumes@audio@@UAEXH@Z
void audio::SeqActionChannelSendVolumes::vfunc_3(hulk_intptr ) {
    *(int*)((char*)this + 0xc) = 4;
}


// 0x0024ea80 audio::SeqActionChannelSendVolumes::vfunc_4 (10 B): matches/0x0024ea80.cpp
// sym: ?vfunc_4@SeqActionChannelSendVolumes@audio@@UAEXH@Z
void audio::SeqActionChannelSendVolumes::vfunc_4(int ) {
    *(int*)((char*)this + 0xc) = 5;
}


// 0x0024ea90 audio::SeqActionChannelSendVolumes::vfunc_5 (6 B): matches/0x0024ea90.cpp
// sym: ?vfunc_5@SeqActionChannelSendVolumes@audio@@UAEHH@Z
// Same code shape as 0x002514e0 (propagated; names are from that function)
int audio::SeqActionChannelSendVolumes::vfunc_5(int ) {
    return this->f_0c;
}

namespace fn_f983a9d8 {

// 0x0024eb60 FUN_0024eb60 (72 B): matches/0x0024eb60.cpp
// sym: ?target@fn_f983a9d8@@YADPAPBDPBD0@Z
// data: fmt = DAT_004298a8, newline = DAT_00422518
char target(const char** p, const char* s, const char** q) {
    const char* v = *p;
    if (print_00246f50(v, DAT_004298a8, s) && other_0025abb0(p, *q)) {
        v = *p;
        return print_00246f50(v, DAT_00422518);
    }
    return 0;
}


// 0x0024ebe0 FUN_0024ebe0 (133 B): equivalent/0x0024ebe0.cpp
// sym: ?FUN_0024ebe0@fn_f983a9d8@@YA_NPAUWriter_24ebe0@1@PBE@Z @da185ddb00d8 @wac889ecde655
// STATUS: equivalent (tools/equiv.py level 3: 377 inputs, branch coverage 10/10)
// FUN_0024ebe0 @ 0x0024ebe0
bool FUN_0024ebe0(Writer_24ebe0 *w, const unsigned char *bytes)
{
    if (!FUN_00246f50(w->stream, "\n[\n"))
        return false;
    w->stream->depth++;
    for (unsigned int i = 0; i < 4; i++) {
        if (!FUN_0025aab0(w, bytes[i]))
            return false;
        if (!FUN_00246f50(w->stream, "\n"))
            return false;
    }
    w->stream->depth--;
    return FUN_00246f50(w->stream, "\n]\n") != 0;
}

} // namespace fn_f983a9d8

// 0x0024ece0 om::DynBehaviour::vfunc_0 (31 B): matches/0x0024ece0.cpp
// sym: ?f2@NonCopyable_24ece0@pure3d@@UAEPAV12@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_24ece0* pure3d::NonCopyable_24ece0::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

namespace fn_f983a9d8 {

// 0x0024ed10 FUN_0024ed10 (86 B): matches/0x0024ed10.cpp
// sym: ??0SeqEventChannelSendVolumesType_24ed10@fn_f983a9d8@@QAE@XZ
SeqEventChannelSendVolumesType_24ed10::SeqEventChannelSendVolumesType_24ed10() throw()
    : FUN_002605e0(((FUN_00240060 *)((owners::String_23fc40 *)&(FUN_00240060()))->FUN_0023fc40("ChSendVol", (hulk_intptr)0)), Key(FUN_002672f0("SeqEventChannelSendVolumes", 0, 0)), (int)sizeof(AudioSeqEventChannelSendVolumes), (int)__alignof(AudioSeqEventChannelSendVolumes)) { HULK_SIZE32(AudioSeqEventChannelSendVolumes, 0x50); }

} // namespace fn_f983a9d8

// 0x0024ed70 audio::SeqEventChannelSendVolumesType::vfunc_2 (30 B): matches/0x0024ed70.cpp
// sym: ??_GSeqEventChannelSendVolumesType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventChannelSendVolumesType::~SeqEventChannelSendVolumesType() {}

namespace fn_f983a9d8 {

// 0x0024edb0 audio::SeqActionChannelSendVolumes::vfunc_0 (36 B): matches/0x0024edb0.cpp
// sym: ?f0@SeqActionChannelSendVolumes_24edb0@fn_f983a9d8@@QAEPAV12@E@Z
// data: g_pool_24edb0 = DAT_004e6700
SeqActionChannelSendVolumes_24edb0* SeqActionChannelSendVolumes_24edb0::f0(unsigned char flags) {
    vptr = hulk_at_004298fc;
    if (flags & 1)
        Free(((char*)&DAT_004e6700), this);
    return this;
}

} // namespace fn_f983a9d8

// 0x0024ee10 audio::ChannelSendVolumeFadeBehaviour::vfunc_0 (36 B): matches/0x0024ee10.cpp [wrapped: conflict: audio::ChannelSendVolumeFadeBehaviour; om::DynBehaviour]
// sym: ?vfunc_0@ChannelSendVolumeFadeBehaviour@audio@fn_0024ee10@@UAEPAV123@H@Z
namespace fn_0024ee10 {

extern "C" char DAT_0042991c[];
namespace om {
class DynBehaviour {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
} // namespace om
namespace audio {
class ChannelSendVolumeFadeBehaviour : public om::DynBehaviour {
  public:
    virtual ChannelSendVolumeFadeBehaviour* vfunc_0(int);
    virtual void vfunc_1();
};
} // namespace audio
extern "C++" __declspec(nothrow) void __cdecl FUN_00247550(void*, void*);
audio::ChannelSendVolumeFadeBehaviour* audio::ChannelSendVolumeFadeBehaviour::vfunc_0(int flag) {
    ChannelSendVolumeFadeBehaviour* p = this;
    *(hulk_intptr*)p = ((hulk_intptr)DAT_0042991c);
    if (flag & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e67b8), p);
    return p;
}
} // namespace fn_0024ee10


// 0x0024ee40 audio::ChannelSendVolumeFadeBehaviour::vfunc_1 (395 B): equivalent/0x0024ee40.cpp [wrapped: conflict: audio::ChannelSendVolumeFadeBehaviour; om::DynBehaviour]
// sym: ?vfunc_1@ChannelSendVolumeFadeBehaviour@audio@fn_0024ee40@@UAE_NHH@Z @40dd2c6adf01 @wccb46d1d7fd2
namespace fn_0024ee40 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 30/30)
// audio::ChannelSendVolumeFadeBehaviour::vfunc_1 @ 0x0024ee40

namespace om {
class DynBehaviour {
public:
    virtual void vfunc_0();
};
}

namespace audio {
class ChannelSendVolumeFadeBehaviour : public om::DynBehaviour {
public:
    virtual void vfunc_0();
    virtual bool vfunc_1(int unused, int elapsed);

    char pad4[0x14];
    int duration;                    // 0x18
    unsigned char *targets;          // 0x1c, byte targets 0..255
    float *current;                  // 0x20
};
}


bool audio::ChannelSendVolumeFadeBehaviour::vfunc_1(int unused, int elapsed)
{
    double step;
    if (duration == 0)
        step = (*(float*)&DAT_003f32dc);
    else
        step = (double)elapsed / (double)duration;

    int reached = 0;
    for (int i = 0; i < 64; i++) {
        float target = (float)targets[i] * 0.0039215689f;
        float *p = &current[i];
        double c = *p;
        if (c < target) {
            c = c + step;
            if (c >= target) {
                c = target;
                reached++;
            }
        } else {
            c = c - step;
            if (c <= target) {
                c = target;
                reached++;
            }
        }
        *p = (float)c;
    }
    return reached == 64;
}
} // namespace fn_0024ee40

namespace fn_f983a9d8 {

// 0x0024eff0 FUN_0024eff0 (28 B): matches/0x0024eff0.cpp
// sym: _FUN_0024eff0
extern "C" unsigned char FUN_0024eff0(unsigned int* stream, unsigned int text) {
    FUN_00246f50(*stream, g_fmt, text);
    return 0;
}


// 0x0024f010 FUN_0024f010 (81 B): matches/0x0024f010.cpp
// sym: ?Target@fn_f983a9d8@@YAEHPAH@Z
unsigned char Target(int a, int* out) {
    Temp_24f010 t;
    t.Init_0023fac0();
    unsigned char r = FUN_0025bce0(a, &t);
    if (out) {
        int x = t.Finish_0023fb00();
        *out = Convert_002673a0(x, 0);
    }
    ((owners::Str_240060 *)&t)->FUN_00240060();
    return r;
}


// 0x0024f070 FUN_0024f070 (131 B): equivalent/0x0024f070.cpp
// sym: ?FUN_0024f070@fn_f983a9d8@@YA_NPAUWriter_24f070@1@PAM@Z @070d6b942f34 @w9ad8981f9b26
// STATUS: equivalent (tools/equiv.py level 3: 383 inputs, branch coverage 10/10)
// FUN_0024f070 @ 0x0024f070
// Writes a 16-float matrix as "[ v v ... ]" lines to a text stream.
bool FUN_0024f070(Writer_24f070 *w, float *values)
{
    if (!FUN_00246f50(w->out, "\n[\n"))
        return false;
    w->out->indent++;
    for (unsigned int i = 0; i < 16; i++) {
        if (!FUN_0024ebe0(w, &values[i]))
            return false;
        if (!FUN_00246f50(w->out, "\n"))
            return false;
    }
    w->out->indent--;
    return FUN_00246f50(w->out, "\n]\n") != 0;
}


// 0x0024f180 FUN_0024f180 (53 B): matches/0x0024f180.cpp
// sym: ?FUN_0024f180@fn_f983a9d8@@YIPAIPAUOwner_24f180@1@@Z
unsigned int* __fastcall FUN_0024f180(Owner_24f180* self) {
    unsigned int* p = Allocate_00247530(GetSize_00247800());
    unsigned int* r;
    if (p) {
        for (int i = 0; i != 0x40; ++i)
            p[i] = 0x3f800000;
        r = p;
    } else {
        r = 0;
    }
    self->data = r;
    return r;
}

} // namespace fn_f983a9d8

// 0x0024f1c0 FUN_0024f1c0 (57 B): equivalent/0x0024f1c0.cpp [wrapped: conflict: audio::SeqEventChannelSendVolumes]
// sym: ??0SeqEventChannelSendVolumes@audio@fn_0024f1c0@@QAE@XZ @55e792334131 @wa76bf51ab9e0
namespace fn_0024f1c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0024f1c0 @ 0x0024f1c0
int __cdecl FUN_002673a0(const char *, int);
namespace audio { struct Base { Base(); virtual void method(); }; struct SeqEventChannelSendVolumes : Base { int unused; int volumes[16]; int count; int sound; SeqEventChannelSendVolumes(); virtual void method(); }; }
audio::SeqEventChannelSendVolumes::SeqEventChannelSendVolumes() : Base() { sound = FUN_002673a0("stitched", 0); count = 100; for (int i=0;i<16;++i) volumes[i]=0; }
} // namespace fn_0024f1c0

namespace fn_f983a9d8 {

// 0x0024f200 audio::SeqEventChannelSendVolumes::vfunc_4 (35 B): matches/0x0024f200.cpp
// sym: ?f4@SeqEventChannelSendVolumes@fn_f983a9d8@@UAEPAV12@E@Z
// data: hulk_at_004e6748 = DAT_004e6748
SeqEventChannelSendVolumes* SeqEventChannelSendVolumes::f4(unsigned char flags) {
    FUN_0025fd10((void*)(this));
    if (flags & 1) {
        FUN_00247550((void*)((hulk_intptr)(((char*)&DAT_004e6750))), this);
    }
    return this;
}

} // namespace fn_f983a9d8

// 0x0024f230 audio::SeqEventChannelSendVolumes::vfunc_2 (66 B): matches/0x0024f230.cpp [wrapped: conflict: audio::SeqEventChannelSendVolumes]
// sym: ?vfunc_2@SeqEventChannelSendVolumes@audio@fn_0024f230@@UAEXH@Z
inline void* operator new(size_t, void* p) {
    return p;
}
namespace fn_0024f230 {

/* size_t: tree_prelude.h */

void* __cdecl FUN_00247530(void*);
struct SeqActionChannelSendVolumes_24f230 {
    virtual void* f0_0024edb0(char);
    virtual void f1_0024f6a0(void*);
    virtual void f2_0024ea60(int, int);
    void* unknown;
    void* event;
    int zero;
    SeqActionChannelSendVolumes_24f230(void* e) : event(e), zero(0) {}
};
struct Channel {
    void FUN_0025dc20(SeqActionChannelSendVolumes_24f230*);
};
namespace audio {
struct SeqEventChannelSendVolumes {
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
void SeqEventChannelSendVolumes::vfunc_2(int arg) {
    void* memory = FUN_00247530(((char*)&DAT_004e6700));
    SeqActionChannelSendVolumes_24f230* action = memory ? new (memory) SeqActionChannelSendVolumes_24f230(this) : 0;
    ((Channel*)arg)->FUN_0025dc20(action);
}
} // namespace audio
} // namespace fn_0024f230

namespace fn_f983a9d8 {

// 0x0024f280 FUN_0024f280 (451 B): equivalent/0x0024f280.cpp
// sym: _FUN_0024f280 @a460e1f9d596 @we970f05d520a
// STATUS: equivalent (tools/equiv.py level 3: 169 inputs, branch coverage 39/40, incomplete)
// FUN_0024f280 @ 0x0024f280
// Red-black tree unique-key insert with rebalance. color: 1 = red, 0 = black.
extern "C" char FUN_0024f280(void * tree_, void * nodeArg_, const unsigned* keyPtr)
{
    Tree_24f280 * tree = (Tree_24f280 *)tree_;
    Holder_24f280 * nodeArg = (Holder_24f280 *)nodeArg_;
    Node* nil = &tree->nil;
    Node* node = &nodeArg->node;
    unsigned key = *keyPtr;
    Node* cur = tree->root;
    Node* parent = nil;

    while (cur != nil) {
        parent = cur;
        if (key < cur->key) {
            cur = cur->left;
        } else if (key == cur->key) {
            return 0;
        } else {
            cur = cur->right;
        }
    }

    node->parent = parent;
    if (parent == nil) {
        tree->root = node;
    } else if (*keyPtr < parent->key) {
        parent->left = node;
    } else {
        parent->right = node;
    }
    node->left = nil;
    node->right = nil;
    node->color = 1;

    while (node != tree->root && node->parent->color == 1) {
        Node* p = node->parent;
        Node* g = p->parent;
        if (p == g->left) {
            Node* uncle = g->right;
            if (uncle->color == 1) {
                p->color = 0;
                uncle->color = 0;
                g->color = 1;
                node = g;
            } else {
                if (node == p->right) {
                    node = p;
                    FUN_00247d50(tree, node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                Node* gg = node->parent->parent;
                Node* pv = gg->left;
                gg->left = pv->right;
                if (pv->right != nil)
                    pv->right->parent = gg;
                pv->parent = gg->parent;
                Node* gp = gg->parent;
                if (gp == nil) {
                    tree->root = pv;
                } else if (gg == gp->left) {
                    gp->left = pv;
                } else {
                    gp->right = pv;
                }
                pv->right = gg;
                gg->parent = pv;
            }
        } else {
            Node* uncle = g->left;
            if (uncle->color == 1) {
                p->color = 0;
                uncle->color = 0;
                g->color = 1;
                node = g;
            } else {
                if (node == p->left) {
                    node = p;
                    FUN_00247da0(tree, node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                Node* gg = node->parent->parent;
                Node* pv = gg->right;
                gg->right = pv->left;
                if (pv->left != nil)
                    pv->left->parent = gg;
                pv->parent = gg->parent;
                Node* gp = gg->parent;
                if (gp == nil) {
                    tree->root = pv;
                } else if (gg == gp->left) {
                    gp->left = pv;
                } else {
                    gp->right = pv;
                }
                pv->left = gg;
                gg->parent = pv;
            }
        }
    }
    tree->root->color = 0;
    return 1;
}


// 0x0024f4a0 FUN_0024f4a0 (64 B): matches/0x0024f4a0.cpp
// sym: _FUN_0024f4a0
extern "C" unsigned char __cdecl FUN_0024f4a0(void* source, const unsigned char* data) {
    for (unsigned int block = 0; block < 16; ++block) {
        for (unsigned int byteIndex = 0; byteIndex < 4; ++byteIndex) {
            if (!FUN_0025aad0(source, data + block * 4 + byteIndex))
                return 0;
        }
    }
    return 1;
}

} // namespace fn_f983a9d8

// 0x0024f540 audio::SeqEventChannelSendVolumesType::vfunc_3 (80 B): equivalent/0x0024f540.cpp [wrapped: conflict: FUN_002673a0; audio::SeqEventChannelSendVolumes; audio::SeqEventChannelSendVolumesType]
// sym: ?vfunc_3@SeqEventChannelSendVolumesType@audio@fn_0024f540@@UAEPAUSeqEventChannelSendVolumes@23@XZ @5cee1a3156c9 @w150a18947b9a
namespace fn_0024f540 {
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 2/2)
// audio::SeqEventChannelSendVolumesType::vfunc_3 @ 0x0024f540

/* size_t: tree_prelude.h */

namespace audio {
struct SeqEventChannelSendVolumes {
    virtual int vfunc_0_0024f600(void*);
    virtual bool vfunc_1_0024f590(void*);
    virtual void vfunc_2_0024f230(int);
    virtual void vfunc_3();
    char pad[4];
    unsigned int volumes[16];
    int count;
    void *tag;
    void FUN_0025fd00();
};
struct SeqEventChannelSendVolumesType {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual SeqEventChannelSendVolumes *vfunc_3();
};
}
extern void * __cdecl FUN_00247530(void *);
extern void * __cdecl FUN_002673a0(const char *, int);
audio::SeqEventChannelSendVolumes *audio::SeqEventChannelSendVolumesType::vfunc_3() {
    audio::SeqEventChannelSendVolumes *event = (audio::SeqEventChannelSendVolumes *)FUN_00247530(((char*)((char*)&DAT_004e6750)));
    if (event) {
        event->FUN_0025fd00();
        event = new(event) audio::SeqEventChannelSendVolumes;
        event->tag = FUN_002673a0("stitched", 0);
        event->count = 100;
        for (int i = 0; i < 16; ++i) event->volumes[i] = 0;
    }
    return event;
}
} // namespace fn_0024f540


// 0x0024f590 audio::SeqEventChannelSendVolumes::vfunc_1 (97 B): equivalent/0x0024f590.cpp [wrapped: conflict: audio::SeqEvent; audio::SeqEventChannelSendVolumes]
// sym: ?vfunc_1@SeqEventChannelSendVolumes@audio@fn_0024f590@@UAE_NPAPAX@Z @7f2d8c9ec0d6 @we835559aebab
namespace fn_0024f590 {
// STATUS: equivalent (tools/equiv.py level 3: 2853 inputs, branch coverage 6/6)
// audio::SeqEventChannelSendVolumes::vfunc_1 @ 0x0024f590
namespace audio {
struct SeqEvent {
    virtual void vfunc_0();
    virtual bool vfunc_1(void **);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
struct SeqEventChannelSendVolumes : SeqEvent {
    char padding[0x48 - sizeof(SeqEvent)];
    float mFadeTime;
    virtual void vfunc_0();
    virtual bool vfunc_1(void **);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
}
struct ParseState { char pad[0x24]; int depth; };
extern "C++" __declspec(nothrow) bool __cdecl FUN_00246f50(void *, const char *, ...);
extern "C" bool __cdecl FUN_0024eb60(void **, const char *, float *);
bool audio::SeqEventChannelSendVolumes::vfunc_1(void **state) {
    if (SeqEvent::vfunc_1(state) && FUN_00246f50(*state, "\n[\n")) {
        ++((ParseState *)*state)->depth;
        if (FUN_0024eb60(state, "mFadeTime", &mFadeTime))
            FUN_00246f50(*state, "%s ", "mLayerNameBuf");
    }
    return false;
}
} // namespace fn_0024f590


// 0x0024f600 audio::SeqEventChannelSendVolumes::vfunc_0 (86 B): matches/0x0024f600.cpp
// sym: ?vfunc_0@SeqEventChannelSendVolumes@audio@@UAEHPAX@Z
int audio::SeqEventChannelSendVolumes::vfunc_0(void* __p0) { void * p = (void *)__p0;

    SeqEvent_24f600* base = reinterpret_cast<SeqEvent_24f600*>(this);
    if (base->vfunc_0_0025fd20(p) && FUN_0025abd0(p, &this->f_48) && ReadB_0024f010(p, &this->f_4c) && ReadC_0024f4a0(p, &this->f_08))
        return 1;
    return 0;
}

