// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_002b5610 @ 0x002b5610
#include "compat/ptr.h"
struct Ref_2b5610 { virtual void AddRef(); virtual void Release(); char pad[12]; unsigned count; };
struct Matrix { char data[64]; void FUN_0022b980(); };
struct Small_2b5610 : Ref_2b5610 { Small_2b5610* FUN_002b5100(Ref_2b5610*); };
void* __cdecl FUN_0008d6d0(hulk_uintptr);
void* __cdecl FUN_0008d690(hulk_uintptr);
struct FUN_002b52e0 { virtual void dummy(); char pad04[12]; unsigned type; char pad14[52]; Ref_2b5610* object; char pad4c[36]; Ref_2b5610* resource; Matrix* matrices; Ref_2b5610* resource2; unsigned tail; FUN_002b52e0(FUN_002b52e0*); };
namespace pure3d {
struct ShadowSkinImpl : FUN_002b52e0 { virtual void dummy(); ShadowSkinImpl(FUN_002b52e0*); };
}
pure3d::ShadowSkinImpl::ShadowSkinImpl(FUN_002b52e0* src) : FUN_002b52e0(src) {
 resource=0; matrices=0; resource2=0; tail=0; type=2;
 Ref_2b5610* p=src->resource;
 if(p) p->AddRef();
 if(resource) resource->Release();
 resource=p;
 p=src->resource2;
 if(p) p->AddRef();
 if(resource2) resource2->Release();
 resource2=p;
 Matrix* mem=(Matrix*)FUN_0008d6d0((resource->count+1)*64);
 matrices=mem;
 mem[resource->count].FUN_0022b980();
 Small_2b5610* obj=(Small_2b5610*)FUN_0008d690(24);
 Ref_2b5610* result=obj ? obj->FUN_002b5100(src->object) : 0;
 if(result) result->AddRef();
 if(object) object->Release();
 object=result;
}