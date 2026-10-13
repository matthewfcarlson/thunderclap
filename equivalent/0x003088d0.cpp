// STATUS: equivalent (tools/equiv.py level 3: 177 inputs, branch coverage 12/12)
// physics::WorldCollisionObjectLoader::vfunc_5 @ 0x003088d0
struct Ref { virtual void addRef()=0; virtual void release()=0; };
struct Name { unsigned a,b; void FUN_0027b040(const char*); };
struct Obj { char pad[8]; Name name; Ref* ref; char tail[4]; Obj* FUN_002fe1d0(); };
struct Reader { void FUN_002647e0(void*,unsigned,unsigned,unsigned); };
struct Stream { char pad[0x284]; Reader* reader; bool FUN_002669f0(); void FUN_00266a30(); unsigned FUN_00266c30(); void FUN_00266be0(); };
extern "C" void* __cdecl FUN_00263ea0(unsigned);
extern "C" Ref* __cdecl FUN_003080a0(Stream*);
namespace physics { struct WorldCollisionObjectLoader { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void vfunc_5(Obj**,Name*,Stream*,unsigned); }; }
void physics::WorldCollisionObjectLoader::vfunc_5(Obj** out,Name* name,Stream* stream,unsigned unused) {
 void* mem=FUN_00263ea0(0x18);
 Obj* obj=mem?((Obj*)mem)->FUN_002fe1d0():0;
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
 Ref* ref=FUN_003080a0(stream);
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
