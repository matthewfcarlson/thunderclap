// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002d0f10..0x002d1090 (kind game, layer engine, confidence medium), dominant class pure3d::VertexAnimObject
#include "tree_prelude.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f740762b {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f740762b {} using namespace fn_f740762b;
void __cdecl operator delete[](void* p);   // (x64t21, D115) the game's 0x0008d340
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f740762b {
class Item_2d0f10 {
  public:
    virtual void F() throw();
    virtual void Release() throw();
};
template <class T> struct Vec_2d0f10 {
    T* begin;
    T* end;
    unsigned size() const { return end - begin; }
    ~Vec_2d0f10() throw() {
        if (begin)
            ::operator delete[](begin);   // (x64t21, D115) the game's operator delete[] 0x0008d340
    }
};
class IRefCount {
  public:
    virtual ~IRefCount() throw() {}
};
class VertexAnimObject : public IRefCount {
  public:
    int pad4;
    Item_2d0f10* owner;
    Vec_2d0f10<Item_2d0f10*> items;
    virtual ~VertexAnimObject() throw();
};


// 0x002d0f10 FUN_002d0f10 (107 B): matches/0x002d0f10.cpp
// sym: ??1VertexAnimObject@fn_f740762b@@UAE@XZ
VertexAnimObject::~VertexAnimObject() throw() {
    unsigned n = items.size();
    unsigned i = 0;
    while (i < n) {
        Item_2d0f10** slot = items.begin + i;
        Item_2d0f10* p = *slot;
        if (p) {
            p->Release();
            *slot = 0;
        }
        ++i;
    }
    if (owner) {
        owner->Release();
        owner = 0;
    }
}

} // namespace fn_f740762b

// 0x002d0fa0 FUN_002d0fa0 (196 B): equivalent/0x002d0fa0.cpp [wrapped: conflict: pure3d::VertexAnimObject]
// sym: ??0VertexAnimObject@pure3d@fn_002d0fa0@@QAE@PAUSource_2d0fa0@2@@Z @cc2ec40f8dd3 @w9d1be1a6642a @veb1fe1b9d7d7
namespace fn_002d0fa0 {
// STATUS: equivalent (tools/equiv.py level 3: 51 inputs, branch coverage 12/12)
// FUN_002d0fa0 @ 0x002d0fa0
struct RefObject_2d0fa0 {
 virtual void AddRef();
 virtual void Release();
 virtual void Slot2();
 virtual void Slot3();
 virtual void Slot4();
 virtual unsigned Type();
};
struct Entry_2d0fa0 { RefObject_2d0fa0* object; char padding[12]; };
struct Source_2d0fa0 { char padding[0x48]; Entry_2d0fa0* begin; Entry_2d0fa0* end; char gap[0x14]; RefObject_2d0fa0* extra; };
struct Array_2d0fa0 { RefObject_2d0fa0** data; unsigned size; void FUN_002d0eb0(unsigned count, unsigned* zero); };
namespace pure3d {
struct VertexAnimObject {
 virtual void Slot0_00018b30();
 unsigned field4;
 RefObject_2d0fa0* extra;
 Array_2d0fa0 entries;
 VertexAnimObject(Source_2d0fa0* source);
};
}
pure3d::VertexAnimObject::VertexAnimObject(Source_2d0fa0* source) {
 field4=0;
 extra=0;
 entries.data=0;
 entries.size=0;
 unsigned count=(unsigned)(source->end-source->begin);   // (allocsize1) element-typed: an entry holds a pointer
 unsigned zero=0;
 entries.FUN_002d0eb0(count,&zero);
 for(unsigned i=0;i<count;++i) {
 RefObject_2d0fa0* object=source->begin[i].object;
 if(object->Type()==0x40) {
 RefObject_2d0fa0** slot=entries.data+i;
 object->AddRef();
 if(*slot) (*slot)->Release();
 *slot=object;
 }
 }
 RefObject_2d0fa0* value=source->extra;
 if(value) value->AddRef();
 if(extra) extra->Release();
 extra=value;
}
} // namespace fn_002d0fa0


// 0x002d1070 pure3d::VertexAnimObject::vfunc_2 (30 B): matches/0x002d1070.cpp
// sym: ?vfunc_2@VertexAnimObject_2d1070@fn_002d1070@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `pure3d::VertexAnimObject::~VertexAnimObject() {}` stood for it, which natively
// defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's
// body 0x002d0f10, then (flags & 1) operator delete.
namespace fn_002d1070 {
struct VertexAnimObject_2d1070 {
    void FUN_002d0f10();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* VertexAnimObject_2d1070::vfunc_2(unsigned int flags) {
    FUN_002d0f10();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_002d1070
// (x64t21) the destructor itself, which other objects' code references:
pure3d::VertexAnimObject::~VertexAnimObject() {}

