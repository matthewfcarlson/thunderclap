// STATUS: equivalent (tools/equiv.py level 3: 111 inputs, branch coverage 12/12)
// FUN_002971f0 @ 0x002971f0
#include "compat/ptr.h"
typedef unsigned int uint;
inline void* operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d6d0(hulk_uintptr);
struct Item_2971f0 {
 virtual void AddRef(); virtual void Release(); virtual void v2(); virtual void v3(); virtual Item_2971f0* Clone(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void Configure(int,int,int,int); virtual void v11(); virtual void v12(); virtual void v13(); virtual void SetParent(void*);
};
struct Small_2971f0 { uint a,b; void FUN_0027af70(const Small_2971f0*); };
namespace pure3d { namespace scenegraph {
struct Node {
 virtual void v0();
 uint field4; Small_2971f0 small; uint field10,field14;
 void FUN_0027b070();
};
struct BranchNode: Node {
 virtual void v0();
 uint count; Item_2971f0** items; Item_2971f0** end;
 BranchNode* FUN_002971f0(const BranchNode* source);
};
}}
pure3d::scenegraph::BranchNode* pure3d::scenegraph::BranchNode::FUN_002971f0(const BranchNode* source) {
 FUN_0027b070();
 new(this) Node;
 field10=source->field10; field14=source->field14;
 small.FUN_0027af70(&source->small);
 new(this) BranchNode;
 count=0;
 uint size=source->count*4;
 if(source->count>0) { items=(Item_2971f0**)FUN_0008d6d0(size); if(items) end=(Item_2971f0**)((char*)items+size); else {items=0;end=0;} }
 else {items=0;end=0;}
 for(uint i=0;i<source->count;++i) {
 items[i]=0;
 Item_2971f0* item=source->items[i]->Clone();
 if(item) {
 Item_2971f0** slot=items+count;
 item->AddRef();
 if(*slot) (*slot)->Release();
 *slot=item; ++count;
 item->SetParent(this);
 item->Configure(1,2,1,1);
 item->Configure(1,6,2,1);
 }
 }
 return this;
}
