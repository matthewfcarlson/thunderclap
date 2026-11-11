// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00260730..0x00260950 (kind game, layer engine, confidence high), dominant class audio::SeqEventContainer
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f2465100 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f2465100 {} using namespace fn_f2465100;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f2465100 {
struct Pair_260730 {
    int a;
    int b;
};
class Result_260730 {
  public:
    virtual char Check(int);
    virtual void V1();
    virtual void V2();
    virtual Result_260730* Get();
    virtual void Stop(int);
};
extern "C" char Parse(int, Pair_260730*);
extern "C" Result_260730* Find(Pair_260730*);
extern int hulk_at_00429b1c;
extern int hulk_at_0042aa60;
extern "C" void FUN_00260590(void*);
class SeqEventContainer_2607a0 {
  public:
    int* vptr;
    char pad[8];
    void Initialize();
};
struct Node {
    Node* next;
};
extern "C" bool __cdecl FUN_0025abd0(unsigned a, unsigned* out);
extern "C" void * __cdecl FUN_00260730(int);
struct SeqEventContainer_2607c0 {
    virtual bool v0(unsigned a);
    int m4, m8;
    Node* mc;
    Node* m10;
};
struct Writer_260840 { char pad[0x24]; unsigned depth; };
extern bool __cdecl FUN_00246f50(Writer_260840*, const char*, ...);
struct NameService { const char* FUN_0023fb00(); };
extern NameService* __cdecl FUN_0024c710();
namespace audio {
struct EventLink { EventLink* next; };
}
namespace audio {
struct SeqEvent {
 virtual void vfunc_0();
 virtual bool vfunc_1(Writer_260840**);
 virtual void FUN_00344f51();
 virtual void slot3();
 EventLink link;
};
}
namespace audio {
struct SeqEventContainer : SeqEvent {
 char padding[4];
 EventLink* children;
 virtual bool vfunc_1(Writer_260840**);
};
}


// 0x00260730 FUN_00260730 (99 B): matches/0x00260730.cpp
// sym: _FUN_00260730
extern "C" void * FUN_00260730(int param) {
    Pair_260730 p;
    p.a = 0;
    p.b = 0;
    if (!Parse(param, &p))
        return (Result_260730 *)0;
    Result_260730* r = Find(&p);
    if (!r)
        return (Result_260730 *)0;
    r = r->Get();
    if (!r->Check(param)) {
        r->Stop(1);
        return (Result_260730 *)0;
    }
    return (Result_260730 *)r;
}


// 0x002607a0 FUN_002607a0 (29 B): matches/0x002607a0.cpp
// sym: ?Initialize@SeqEventContainer_2607a0@fn_f2465100@@QAEXXZ
void SeqEventContainer_2607a0::Initialize() {
    vptr = &hulk_at_00429b1c;
    FUN_00260590(&pad[8]);
    vptr = &hulk_at_0042aa60;
}


// 0x002607c0 audio::SeqEventContainer::vfunc_0 (119 B): matches/0x002607c0.cpp
// sym: ?v0@SeqEventContainer_2607c0@fn_f2465100@@UAE_NI@Z
bool SeqEventContainer_2607c0::v0(unsigned a) {
    unsigned n;
    if (!FUN_0025abd0(a, &n))
        return false;
    unsigned i = 0;
    if (n > 0) {
        do {
            char* p = ((char *)FUN_00260730((unsigned)a));
            if (!p)
                return false;
            Node* nd = (Node*)(p + 4);
            nd->next = 0;
            if (m10 == 0)
                mc = nd;
            else
                m10->next = nd;
            m10 = nd;
            _ReadWriteBarrier();
            m8++;
            i++;
        } while (i < n);
    }
    return true;
}


// 0x00260840 audio::SeqEventContainer::vfunc_1 (194 B): equivalent/0x00260840.cpp
// sym: ?vfunc_1@SeqEventContainer@audio@fn_f2465100@@UAE_NPAPAUWriter_260840@3@@Z
// STATUS: equivalent (tools/equiv.py level 3: 1252 inputs, branch coverage 16/16)
// audio::SeqEventContainer::vfunc_1 @ 0x00260840
namespace audio {
bool SeqEventContainer::vfunc_1(Writer_260840** output) {
 if (!FUN_00246f50(*output,"mChildren\n[\n")) return false;
 ++(*output)->depth;
 SeqEvent* child = children ? reinterpret_cast<SeqEvent*>(reinterpret_cast<char*>(children)-4) : 0;
 while (child) {
  child->slot3();
  Writer_260840* writer = *output;
  const char* name = FUN_0024c710()->FUN_0023fb00();
  if (!FUN_00246f50(writer,"%s\n",name)) return false;
  if (!child->vfunc_1(output)) return false;
  if (!FUN_00246f50(*output,"\n")) return false;
  EventLink* next = child->link.next;
  child = next ? reinterpret_cast<SeqEvent*>(reinterpret_cast<char*>(next)-4) : 0;
 }
 --(*output)->depth;
 return FUN_00246f50(*output,"]\n") != false;
}
}

} // namespace fn_f2465100

// 0x00260910 audio::SeqEventContainer::vfunc_5 (59 B): equivalent/0x00260910.cpp [wrapped: conflict: audio::SeqEvent; audio::SeqEventContainer]
// sym: ?vfunc_5@SeqEventContainer@audio@fn_00260910@@UAEIXZ
namespace fn_00260910 {
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 10/10)
// audio::SeqEventContainer::vfunc_5 @ 0x00260910
namespace audio {
struct SeqEvent {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void FUN_00344f51_2();
    virtual void FUN_00344f51_3();
    virtual void vfunc_4();
    virtual unsigned int vfunc_5();
    SeqEvent *nextLink;
    char pad[4];
};
struct SeqEventContainer : SeqEvent {
    SeqEvent *firstLink;
    unsigned int vfunc_5();
};
unsigned int SeqEventContainer::vfunc_5() {
    unsigned int maximum = 0;
    SeqEvent *event = firstLink ? (SeqEvent *)((char *)firstLink - 4) : 0;
    while (event) {
        unsigned int value = event->vfunc_5();
        if (value > maximum) maximum = value;
        SeqEvent *link = event->nextLink;
        event = link ? (SeqEvent *)((char *)link - 4) : 0;
    }
    return maximum + 1;
}
}
} // namespace fn_00260910

