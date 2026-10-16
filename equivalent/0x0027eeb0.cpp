// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// pure3d::prop::StatePropLoader::vfunc_5 @ 0x0027eeb0
#include "decls/address.h"
typedef unsigned __int64 U64_27eeb0;
struct Stream { void FUN_002647e0(void*, unsigned, unsigned, unsigned); };
struct Reader { char pad[0x284]; Stream* stream; };
namespace pure3d { namespace prop { struct StatePropData; struct StateProp { char pad[8]; unsigned a,b; StateProp* FUN_0027def0(StatePropData*, int); }; } }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void vfunc_0(); }; } }
struct Inventory_27eeb0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual pure3d::prop::StatePropData* v3(content::LoadInventory::DynamicCaster<pure3d::prop::StatePropData>*, U64_27eeb0); };
extern void* __cdecl FUN_00263ea0(unsigned);
namespace pure3d { namespace prop { struct StatePropLoader { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(StateProp**, unsigned*, Reader*, Inventory_27eeb0*); }; } }
void pure3d::prop::StatePropLoader::vfunc_5(StateProp** out, unsigned* id, Reader* reader, Inventory_27eeb0* inventory) {
 struct { unsigned char padding[3]; unsigned char length; unsigned ignored; char name[256]; } local;
 reader->stream->FUN_002647e0(&local.ignored,1,4,1);
 reader->stream->FUN_002647e0(&local.length,1,1,1);
 unsigned n=local.length;
 reader->stream->FUN_002647e0(local.name,n,1,1);
 local.name[n]=0;
 U64_27eeb0 key=FUN_0027b020(local.name);
 content::LoadInventory::DynamicCaster<StatePropData> caster;
 StatePropData* data=inventory->v3(&caster,key);
 StateProp* obj=(StateProp*)FUN_00263ea0(0xe8);
 if(obj) obj=obj->FUN_0027def0(data,0);
 *out=obj;
 id[0]=obj->a;
 id[1]=obj->b;
}
