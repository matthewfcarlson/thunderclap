// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001e9e70..0x001eab10 (kind game, layer game, confidence high), dominant class CSoundResourceManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/content.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f01d1853 {
#define TREE_TU_END }
namespace fn_f01d1853 {} using namespace fn_f01d1853;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f01d1853 {
class Dummy_1e9e90 {
  public:
    void Call(void*);
};
class Dummy_1e9f10 {
  public:
    void Call(void*);
};
class Dummy_1e9f90 {
  public:
    void Call(void*);
};
} // namespace fn_f01d1853
extern "C" __int64 __cdecl FUN_002672f0(int, int, int);
namespace fn_f01d1853 {
struct Entry {
    char pad0[0x14];
    Entry *next;
    char pad1[0x20];
    int key;
};
struct List {
    char pad[0x3c];
    Entry *first;
};
extern char DAT_004c7150[];
extern char DAT_004c7170[];
extern char DAT_004c712c[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern "C" hulk_uintptr __cdecl FUN_0026fd50(hulk_uintptr value, unsigned align);
extern "C" void *__cdecl FUN_0008d710(unsigned size, int tag);
struct Key_1ea190 {
    int a;
    int b;
};
struct Entry_1ea190 {
    int f00;
    void *f04;
    hulk_uintptr f08;
    int f0c;
    unsigned f10;
};
struct Pool_1ea190 {
    char pad00[0x19c];
    Entry_1ea190 *entries[200];
    int count;
    Entry_1ea190 *FUN_001e9900(Key_1ea190 *key);
};
struct Source_1ea190 {
    char pad00[0x10];
    Key_1ea190 key;
    unsigned char flags;
    char pad19[3];
    unsigned size;
};
struct Request {
    char pad00[0x40];
    unsigned bits;
};
struct Link_1ea190 {
    Link_1ea190 *next;
};
struct Item_1ea190 {
    int pad00;
    Link_1ea190 link;
};
struct List_1ea190 {
    char pad00[0xc];
    Link_1ea190 *head;
};
class Collector_1ea190 {
public:
    char pad00[0x20];
    unsigned total;
    char pad24[0x2c - 0x24];
    Entry_1ea190 *used[64];
    int usedCount;
    int FUN_001ea190(Request *req, List_1ea190 *list);
};
class CActorManager_1ea420 {
  public:
    void invoke(const char*);
};
class CActorManager_1ea4b0 {
  public:
    void invoke(const char*);
};
class CActorManager_1ea540 {
  public:
    void invoke(const char*);
};
struct Node {
    char pad0[0x14];
    Node* nextLink;
    char pad18[4];
    int data;
};
struct Source {
    char pad[0x3c];
    Node* firstLink;
};
struct Target {
    char pad0[0x18];
    Source* source;
    char pad1[8];
    int count;
    void FUN_001ea190(Node*, int*);
    void FUN_001ea6b0(Source*, int);
};

} // namespace fn_f01d1853

// 0x001e9e70 Method1<CSoundResourceManager,void,const_char_*>::vfunc_0 (30 B): matches/0x001e9e70.cpp
// sym: ??_G?$Method1@VCSoundResourceManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSoundResourceManager, void, const char *>::~Method1() {}


// 0x001e9e90 Method1<CSoundResourceManager,void,const_char_*>::vfunc_2 (19 B): matches/0x001e9e90.cpp
// sym: ?vfunc_2@?$Method1@VCSoundResourceManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CSoundResourceManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1e9e90* d = (Dummy_1e9e90*)a;
    (d->*(*(void (Dummy_1e9e90::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CSoundResourceManager, void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e9e70)
#endif


// 0x001e9ef0 Method1<CSoundResourceManager,void,char_*>::vfunc_0 (30 B): matches/0x001e9ef0.cpp
// sym: ??_G?$Method1@VCSoundResourceManager@@XPAD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSoundResourceManager, void, char *>::~Method1() {}


// 0x001e9f10 Method1<CSoundResourceManager,void,char_*>::vfunc_2 (19 B): matches/0x001e9f10.cpp
// sym: ?vfunc_2@?$Method1@VCSoundResourceManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CSoundResourceManager, void, char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1e9f10* d = (Dummy_1e9f10*)a;
    (d->*(*(void (Dummy_1e9f10::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CSoundResourceManager, void, char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e9ef0)
#endif


// 0x001e9f70 Method1<CSoundResourceManager,void,int>::vfunc_0 (30 B): matches/0x001e9f70.cpp
// sym: ??_G?$Method1@VCSoundResourceManager@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CSoundResourceManager, void, int>::~Method1() {}


// 0x001e9f90 Method1<CSoundResourceManager,void,int>::vfunc_2 (19 B): matches/0x001e9f90.cpp
// sym: ?vfunc_2@?$Method1@VCSoundResourceManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CSoundResourceManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_1e9f90* d = (Dummy_1e9f90*)a;
    (d->*(*(void (Dummy_1e9f90::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CSoundResourceManager, void, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1e9f70)
#endif


// 0x001ea010 FUN_001ea010 (50 B): matches/0x001ea010.cpp
// sym: ?FUN_001ea010@X_1ea010@owners@@QAEHH@Z
int owners::X_1ea010::FUN_001ea010(hulk_intptr p) {
    __int64 v = FUN_002672f0(((int)p), 0, 0);
    return consume(&v);
}

namespace fn_f01d1853 {

// 0x001ea050 FUN_001ea050 (3 B): matches/0x001ea050.cpp
// sym: ?FUN_001ea050@fn_f01d1853@@YGXH@Z
void __stdcall FUN_001ea050(int x) {}


// 0x001ea060 FUN_001ea060 (81 B): equivalent/0x001ea060.cpp
// sym: ?FUN_001ea060@fn_f01d1853@@YGHPAUList@1@H@Z @16f67e8c1343 @wa34ee8eb30ec
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001ea060 @ 0x001ea060
int __stdcall FUN_001ea060(List *list, int value) {
    if (!list) return -1;
    int key = FUN_002673a0(value, 0);
    Entry *entry = list->first ? (Entry *)((char *)list->first - 0x14) : 0;
    int index = 0;
    while (entry) {
        if (entry->key == key) return index;
        entry = entry->next ? (Entry *)((char *)entry->next - 0x14) : 0;
        ++index;
    }
    return -1;
}


// 0x001ea190 FUN_001ea190 (416 B): equivalent/0x001ea190.cpp
// sym: ?FUN_001ea190@Collector_1ea190@fn_f01d1853@@QAEHPAURequest@2@PAUList_1ea190@2@@Z @0354779df5b1 @w62a9c43dfee4
// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 22/24, incomplete)
// FUN_001ea190 @ 0x001ea190
int Collector_1ea190::FUN_001ea190(Request *req, List_1ea190 *list)
{
    Item_1ea190 *it = 0;
    if (list->head)
        it = (Item_1ea190 *)((char *)list->head - 4);
    while (it) {
        List_1ea190 *sub = (List_1ea190 *)FUN_00344e74(it, 0, DAT_004c7150, DAT_004c7170, 0);
        if (sub) {
            FUN_001ea190(req, sub);
        } else {
            Source_1ea190 *src = (Source_1ea190 *)FUN_00344e74(it, 0, DAT_004c7150, DAT_004c712c, 0);
            if (src) {
                Key_1ea190 key = src->key;
                Link_1ea190 *keyLink = (Link_1ea190 *)&src->key;
                hulk_uintptr size = 0;
                if (!(src->flags & 1)) {
                    unsigned v = (src->size & 0x7fffffff) - 0x800;
                    unsigned align = DAT_004c6f4c * 2;
                    if (v < align)
                        size = align;
                    else
                        size = FUN_0026fd50(v, align);
                }
                Pool_1ea190 *pool = (*(Pool_1ea190**)&DAT_004e3690);
                Entry_1ea190 *e = pool->FUN_001e9900(&key);
                if (e) {
                    unsigned lvl = (req->bits >> 5) & 0x1f;
                    if (e->f10 > lvl)
                        e->f10 = lvl;
                } else {
                    if (pool->count >= 200) {
                        e = 0;
                    } else {
                        pool->entries[pool->count++] = (Entry_1ea190 *)FUN_0008d710(0x14, 6);
                        e = pool->entries[pool->count - 1];
                        if (e) {
                            e->f04 = keyLink;
                            e->f00 = 0;
                            e->f08 = size;
                            e->f0c = 0;
                            e->f10 = (req->bits >> 5) & 0x1f;
                            total += size;
                        }
                    }
                }
                used[usedCount] = e;
                usedCount++;
            }
        }
        it = it->link.next ? (Item_1ea190 *)((char *)it->link.next - 4) : 0;
    }
    return 0;
}

} // namespace fn_f01d1853

// 0x001ea3b0 FUN_001ea3b0 (76 B): matches/0x001ea3b0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_001ea3b0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001ea3b0 {
// data: keyA = DAT_0048e100, keyB = DAT_0048e0f0

extern "C" unsigned char __cdecl FUN_001d04d0(const char*);
// Function (include/decls/data/script.h): the vftable, then Function's fields.
class Function_1ea3b0 : public ScriptFunctionFields {
  public:
    virtual void Invoke(const char*);
    Function_1ea3b0(const char*, int);
    ScriptMemberFn fn;  // 0x1c
};
class Method1 : public Function_1ea3b0 {
  public:
    virtual void Invoke(const char*);
    Method1(const char* s, ScriptMemberFn p) : Function_1ea3b0(s, 1) {
        fn = p;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke(const char*);
    void* owner;  // 0x20
    Closure1(const char*, void*, ScriptMemberFn);
};
Closure1::Closure1(const char* s, void* x, ScriptMemberFn p) : Method1(s, p) {
    owner = x;
}
} // namespace fn_001ea3b0


// 0x001ea400 Closure1<CSoundResourceManager,void,const_char_*>::vfunc_0 (30 B): matches/0x001ea400.cpp
// sym: ??_G?$Method1@VCSoundResourceManager@@XPAD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CSoundResourceManager, void, const char *>::~Closure1() {}


// 0x001ea420 Closure1<CSoundResourceManager,void,const_char_*>::vfunc_2 (18 B): matches/0x001ea420.cpp
// sym: ?vfunc_2@?$Closure1@VCSoundResourceManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CSoundResourceManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ea420 * *)&this->f_20)->*(*(void (CActorManager_1ea420::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<CSoundResourceManager, void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ea400)
#endif


// 0x001ea440 FUN_001ea440 (76 B): matches/0x001ea440.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_001ea440@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
namespace fn_001ea440 {

typedef unsigned int uint;
extern "C" unsigned char __cdecl FUN_001d04d0(const char*);
// Function (include/decls/data/script.h): the vftable, then Function's fields.
class Base : public ScriptFunctionFields {
  public:
    Base(const char*, int);
    virtual void f();
};
class Closure1_1ea440 : public Base {
  public:
    Closure1_1ea440(const char*, void*, ScriptMemberFn);
    virtual void f();
    ScriptMemberFn fn;  // 0x1c
};
class Closure1 : public Closure1_1ea440 {
  public:
    Closure1(const char*, void*, ScriptMemberFn);
    virtual void f();
    void* owner;  // 0x20
};
Closure1::Closure1(const char* s, void* p, ScriptMemberFn q) : Closure1_1ea440(s, p, q) {
    owner = p;
}
Closure1_1ea440::Closure1_1ea440(const char* s, void* p, ScriptMemberFn q) : Base(s, 1) {
    fn = q;
    retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0049cad8));
}
} // namespace fn_001ea440


// 0x001ea490 Closure1<CSoundResourceManager,void,char_*>::vfunc_0 (30 B): matches/0x001ea490.cpp
// sym: ??_G?$Method1@VCSoundResourceManager@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CSoundResourceManager, void, char *>::~Closure1() {}


// 0x001ea4b0 Closure1<CSoundResourceManager,void,char_*>::vfunc_2 (18 B): matches/0x001ea4b0.cpp
// sym: ?vfunc_2@?$Closure1@VCSoundResourceManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CSoundResourceManager, void, char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ea4b0 * *)&this->f_20)->*(*(void (CActorManager_1ea4b0::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<CSoundResourceManager, void, char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1ea490)
#endif


// 0x001ea4d0 FUN_001ea4d0 (76 B): matches/0x001ea4d0.cpp [wrapped: conflict: Closure1; Closure1::Closure1; Method1]
// sym: ??0Closure1@fn_001ea4d0@@QAE@PBDPAXP8ScriptBoundClass@@AEXXZ@Z
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_001ea4d0 {
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

// Function (include/decls/data/script.h): the vftable, then Function's fields.
class Function_1ea4d0 : public ScriptFunctionFields {
  public:
    Function_1ea4d0(const char*, int);
    virtual void run();
};
class Method1 : public Function_1ea4d0 {
  public:
    ScriptMemberFn value;  // 0x1c
    Method1(const char* x, ScriptMemberFn v) : Function_1ea4d0(x, 1), value(v) {
        retType = FUN_001d04d0(((int*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((int*)&DAT_0048e134));
    }
    virtual void run();
};
class Closure1 : public Method1 {
  public:
    void* other;  // 0x20
    Closure1(const char* x, void* y, ScriptMemberFn z);
    virtual void run();
};
Closure1::Closure1(const char* x, void* y, ScriptMemberFn z) : Method1(x, z), other(y) {}
} // namespace fn_001ea4d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001ea540 Closure1<CSoundResourceManager,void,int>::vfunc_2 (18 B): matches/0x001ea540.cpp
// sym: ?vfunc_2@?$Closure1@VCSoundResourceManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CSoundResourceManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1ea540 * *)&this->f_20)->*(*(void (CActorManager_1ea540::**)(const char *))&this->f_1c))(*b);
}


// 0x001ea560 FUN_001ea560 (59 B): equivalent/0x001ea560.cpp [wrapped: compile error in a shared declaration (C2757)]
// sym: ?FUN_001ea560@Obj@fn_001ea560@@QAEXHH@Z @ea940f1fb0e4 @wdae5b849266a
namespace fn_001ea560 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001ea560 @ 0x001ea560
struct Caster { virtual void f0(); virtual void f1(); virtual void f2(); virtual char* f3(void* type, int a, int b); }; struct Obj { char pad[0x518]; Caster* caster; void FUN_001ea560(int a,int b); }; struct DynamicCaster { virtual void f(); }; namespace content { namespace LoadInventory { struct DynamicCasterListenerEffectXBox { virtual void f(); }; } } extern "C" void __cdecl FUN_00241280(void*,int,int); void Obj::FUN_001ea560(int a,int b) { content::LoadInventory::DynamicCasterListenerEffectXBox marker; char* result=caster->f3(&marker,a,b); if(result) FUN_00241280(result+0x28,0,0); }
} // namespace fn_001ea560


// 0x001ea5a0 FUN_001ea5a0 (132 B): equivalent/0x001ea5a0.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster; content::LoadInventory::DynamicCasterBase]
// sym: ?Acquire@ClipUser@fn_001ea5a0@@QAEXUArg_1ea5a0@2@@Z @4a6de2db0fa6 @wd2fa1e53bebf
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_001ea5a0 {
// STATUS: equivalent (tools/equiv.py level 3: 2981 inputs, branch coverage 8/8)
// FUN_001ea5a0 @ 0x001ea5a0



namespace audio { class Clip; }

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

struct ClipRef_1ea5a0 {
    unsigned int idLo;
    unsigned int idHi;
};

struct Clip {
    char pad0[0x22];
    unsigned short refs;
};

class ClipLookup_1ea5a0 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Clip *lookup(content::LoadInventory::DynamicCasterBase *caster, unsigned int lo, unsigned int hi);
    virtual void store(unsigned int lo, unsigned int hi, Clip *clip);
};

struct Request {
    char pad0[4];
    ClipRef_1ea5a0 *ref;
};

bool __cdecl FUN_00245720(Clip **out, void *source, const char *name, void *option);
extern "C" void FUN_001e8a60();

struct Arg_1ea5a0 {
    union {
        Request *request;
        Clip *clip;
    };
};

class ClipUser {
public:
    char pad0[0x518];
    ClipLookup_1ea5a0 *clips;
    void Acquire(Arg_1ea5a0 arg);
};

void ClipUser::Acquire(Arg_1ea5a0 arg)
{
    Request *req = arg.request;
    ClipRef_1ea5a0 *ref = req->ref;
    content::LoadInventory::DynamicCaster<audio::Clip> caster;
    arg.clip = clips->lookup(&caster, ref->idLo, ref->idHi);
    if (arg.clip == 0) {
        if (FUN_00245720(&arg.clip, ((char*)&DAT_004e36bc), (const char *)req->ref, (void *)&FUN_001e8a60)) {
            if (arg.clip != 0)
                clips->store(req->ref->idLo, req->ref->idHi, arg.clip);
        }
    }
    if (arg.clip != 0)
        arg.clip->refs++;
}
} // namespace fn_001ea5a0

namespace fn_f01d1853 {

// 0x001ea6b0 FUN_001ea6b0 (75 B): matches/0x001ea6b0.cpp
// sym: ?FUN_001ea6b0@Target@fn_f01d1853@@QAEXPAUSource@2@H@Z
void Target::FUN_001ea6b0(Source* src, int unused) {
    source = src;
    count = 0;
    if (src) {
        Node* link = src->firstLink;
        Node* node = link ? (Node*)((char*)link - 0x14) : 0;
        _ReadWriteBarrier();
        while (node) {
            FUN_001ea190(node, &node->data);
            link = node->nextLink;
            node = link ? (Node*)((char*)link - 0x14) : 0;
            _ReadWriteBarrier();
        }
    }
}

} // namespace fn_f01d1853

// 0x001ea700 FUN_001ea700 (179 B): equivalent/0x001ea700.cpp [wrapped: conflict: content::LoadInventory]
// sym: ?FUN_001ea700@Request@fn_001ea700@@QAEXXZ @56d4de2073de @w8ac2c42cf5a6
namespace fn_001ea700 {
// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 13/14, incomplete)
// FUN_001ea700 @ 0x001ea700

namespace audio { class Clip; }
namespace content { class LoadInventory { public: template<class T> class DynamicCaster { public: virtual void cast(); }; }; }
struct Resource_1ea700 { virtual void slot0(); virtual void release(); char pad[0x1e]; unsigned short refs; };
struct Inventory_1ea700 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Resource_1ea700* lookup(content::LoadInventory::DynamicCaster<audio::Clip>*, unsigned, unsigned); virtual void slot4(); virtual void remove(Resource_1ea700*); };
struct System_1ea700 { char pad[0x518]; Inventory_1ea700* inventory; };
struct Key_1ea700 { unsigned first, second; };
struct Request { unsigned state; Key_1ea700* key; unsigned size; unsigned unused; unsigned category; void FUN_001ea700(); };
void Request::FUN_001ea700() {
 if(state != 3) return;
 content::LoadInventory::DynamicCaster<audio::Clip> caster;
 Resource_1ea700* resource = (*(System_1ea700**)&DAT_004e3690)->inventory->lookup(&caster,key->first,key->second);
 if(resource) { --resource->refs; if(resource->refs == 0) { (*(System_1ea700**)&DAT_004e3690)->inventory->remove(resource); resource->release(); } }
 double amount = (int)size;
 if((int)size < 0) amount += 4294967296.0f;
 if(category != 0) { DAT_004e369c = (float)(DAT_004e369c - amount); state=0; }
 else { DAT_004e36a0 = (float)(DAT_004e36a0 - amount); state=0; }
}
} // namespace fn_001ea700


// 0x001ea8b0 FUN_001ea8b0 (603 B): equivalent/0x001ea8b0.cpp [wrapped: conflict: CSoundResourceManager; Closure1; Method1]
// sym: ?FUN_001ea8b0@CSoundResourceManager@fn_001ea8b0@@QAEHH@Z @ad01fa1cb94d @w51f753705d8f
namespace fn_001ea8b0 {
// STATUS: equivalent (tools/equiv.py level 3: 1920 inputs, branch coverage 10/10)
// FUN_001ea8b0 @ 0x001ea8b0
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

extern "C" void *FUN_0008d690(unsigned int size);


template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void *get() { return ((char*)&DAT_0048e100); } };
template <> struct TypeTag<const char *> { static const void *get() { return ((char*)&DAT_0048e0f0); } };
template <> struct TypeTag<char *> { static const void *get() { return ((char*)&DAT_0049cad8); } };
template <> struct TypeTag<int> { static const void *get() { return ((char*)&DAT_0048e134); } };

// Function (include/decls/data/script.h): the vftable, then Function's fields.
class __declspec(novtable) MethodBase_1ea8b0 : public ScriptFunctionFields {
public:
    virtual void m0();
    void FUN_001d0480(const char *, int);
    MethodBase_1ea8b0(const char *n, int k) { FUN_001d0480(n, k); }
};

template <class T, class R, class A>
class Method1 : public MethodBase_1ea8b0 {
public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) : MethodBase_1ea8b0(name, 1) {
        fn = f;
        retType = FUN_001d04d0(TypeTag<R>::get());
        argTypes[0] = FUN_001d04d0(TypeTag<A>::get());
    }
    Fn fn;
};

template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
public:
    Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) : Method1<T, R, A>(name, f), owner(o) {}
    T *owner;
};

struct Registry_1ea8b0 {
    void FUN_001d3b70(const char *name, void *closure);
};
extern "C" Registry_1ea8b0 *FUN_001d4c90();

struct SoundConfig {
    int size;
    int chunk;
    char pad[0x20];
    int FUN_0023fc40(const char *lang, int flags);
    void FUN_00240060();
};

struct LoadInventory_1ea8b0 {
    char pad0[0x14];
    LoadInventory_1ea8b0 *FUN_00266480(int bufSize);
};

class CSoundResourceManager;

struct Fx_1ea8b0 {
    void FUN_00265240(CSoundResourceManager *owner, const char *name);
};

extern "C" void *FUN_00263ed0(unsigned int size, int kind);
extern "C" void FUN_002474f0(void *p);
extern "C" void FUN_002407a0(int v);
extern "C" void FUN_00241390(SoundConfig *cfg, int zero);
void FUN_00240e00(float v);
void FUN_00240760(int v);
extern "C" int FUN_001e91c0();

class CSoundResourceManager {
public:
    char pad000[0x518];
    LoadInventory_1ea8b0 *streams;
    int param;

    void FUN_001ea0c0(const char *);
    void FUN_001ea050(const char *);
    void FUN_001e9b00(char *);
    void FUN_001e9b20(int);
    int FUN_001ea8b0(int arg);
};

int CSoundResourceManager::FUN_001ea8b0(int arg)
{
    (*(CSoundResourceManager**)&DAT_004e3690) = this;
    param = arg;
    FUN_002474f0(((char*)&DAT_004e36c8));
    FUN_002407a0(-1);

    SoundConfig cfg;
    cfg.size = 0x800000;
    cfg.chunk = 0x80000;
    FUN_00241390(&cfg, 0);
    FUN_00240e00(1.0f);
    DAT_004e36a4 = 2075528.0f;
    FUN_00240760(cfg.FUN_0023fc40("english", 0));
    cfg.FUN_00240060();

    void *raw = FUN_00263ed0(0x14, 6);
    LoadInventory_1ea8b0 *s = 0;
    if (raw != 0)
        s = ((LoadInventory_1ea8b0 *)raw)->FUN_00266480(0x400);
    streams = s;

    (*(Fx_1ea8b0**)&DAT_00527c58)->FUN_00265240(this, "clips");
    Registry_1ea8b0 *reg = FUN_001d4c90();
    void *mem;

    { typedef Closure1<CSoundResourceManager, void, const char *> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure1<CSoundResourceManager, void, const char *>));
    Closure1<CSoundResourceManager, void, const char *> *c1 = 0;
    if (mem)
        c1 = new (mem) Closure1<CSoundResourceManager, void, const char *>("snd_PreloadSequenceOfRankN", this, &CSoundResourceManager::FUN_001ea0c0);
    reg->FUN_001d3b70("snd_PreloadSequenceOfRankN", c1);

    { typedef Closure1<CSoundResourceManager, void, const char *> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure1<CSoundResourceManager, void, const char *>));
    Closure1<CSoundResourceManager, void, const char *> *c2 = 0;
    if (mem)
        c2 = new (mem) Closure1<CSoundResourceManager, void, const char *>("snd_PrepareSequence", this, &CSoundResourceManager::FUN_001ea050);
    reg->FUN_001d3b70("snd_PrepareSequence", c2);

    { typedef Closure1<CSoundResourceManager, void, char *> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure1<CSoundResourceManager, void, char *>));
    Closure1<CSoundResourceManager, void, char *> *c3 = 0;
    if (mem)
        c3 = new (mem) Closure1<CSoundResourceManager, void, char *>("snd_SetDefaultMix", this, &CSoundResourceManager::FUN_001e9b00);
    reg->FUN_001d3b70("snd_SetDefaultMix", c3);

    { typedef Closure1<CSoundResourceManager, void, int> Sized; HULK_SIZE32(Sized, 0x24); }
    mem = FUN_0008d690((int)sizeof(Closure1<CSoundResourceManager, void, int>));
    Closure1<CSoundResourceManager, void, int> *c4 = 0;
    if (mem)
        c4 = new (mem) Closure1<CSoundResourceManager, void, int>("snd_ReturnToDefaultMix", this, &CSoundResourceManager::FUN_001e9b20);
    reg->FUN_001d3b70("snd_ReturnToDefaultMix", c4);

    return FUN_001e91c0();
}
} // namespace fn_001ea8b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

