// STATUS: equivalent (tools/equiv.py level 3: 177 inputs, branch coverage 12/12)
// physics::WorldCollisionObjectLoader::vfunc_5 @ 0x003088d0
#include "gen/physics.h"

struct Ref_3088d0 { virtual void addRef()=0; virtual void release()=0; };
struct Name_3088d0 { unsigned a,b; void FUN_0027b040(const char*); };
struct Obj_3088d0 { char pad[8]; Name_3088d0 name; Ref_3088d0* ref; char tail[4]; Obj_3088d0* FUN_002fe1d0(); };
struct Reader_3088d0 { void FUN_002647e0(void*,unsigned,unsigned,unsigned); };
struct Stream_3088d0 { char pad[0x284]; Reader_3088d0* reader; bool FUN_002669f0(); void FUN_00266a30(); unsigned FUN_00266c30(); void FUN_00266be0(); };
extern "C" void* __cdecl FUN_00263ea0(unsigned);
extern "C" Ref_3088d0* __cdecl FUN_003080a0(Stream_3088d0*);
namespace physics {  }
void physics::WorldCollisionObjectLoader::vfunc_5(void* __p0, void* __p1, void* __p2, int __p3) { Obj_3088d0 ** out = (Obj_3088d0 **)__p0; Name_3088d0 * name = (Name_3088d0 *)__p1; Stream_3088d0 * stream = (Stream_3088d0 *)__p2; unsigned int unused = (unsigned int)__p3;

 void* mem=FUN_00263ea0(0x18);
 Obj_3088d0* obj=mem?((Obj_3088d0*)mem)->FUN_002fe1d0():0;
 unsigned char length;
 char text[256]; unsigned value;
 stream->reader->FUN_002647e0(&length,1,1,1);
 unsigned n=length;
 stream->reader->FUN_002647e0(text,n,1,1);
 text[n]=0;
 obj->name.FUN_0027b040(text);
 stream->reader->FUN_002647e0(&value,1,4,1);
 while(stream->FUN_002669f0()) {
 stream->FUN_00266a30();
 if(stream->FUN_00266c30()==0x7010001) {
 Ref_3088d0* ref=FUN_003080a0(stream);
 if(ref) ref->addRef();
 if(obj->ref) obj->ref->release();
 obj->ref=ref;
 }
 stream->FUN_00266be0();
 }
 *out=obj;
 name->a=obj->name.a;
 name->b=obj->name.b;
}
