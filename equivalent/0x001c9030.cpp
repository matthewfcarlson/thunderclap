// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 4/4)
// FUN_001c9030 @ 0x001c9030
typedef unsigned int size_t;
inline void* operator new(size_t, void* p) { return p; }
extern "C" void* __cdecl FUN_00263ea0(unsigned);
extern "C" void* __cdecl FUN_0008d690(unsigned);
struct Small_1c9030 { char data[8]; void FUN_0027af00(); };
struct StoreBase { char data[0x120]; void FUN_001c77e0(int,int); };
namespace Render { struct Room; template<class T> struct Store { virtual void slot0(); char data[0x11c]; }; }
struct Stream { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(unsigned,int); };
struct Resource_1c9030 { virtual void init(); char pad[12]; Stream* stream; Resource_1c9030* FUN_0028edb0(); };
struct ShadowData { char data[12]; void FUN_002a30a0(); };
namespace pure3d { struct ShadowGenerator { virtual void init(); unsigned value; ShadowData data; }; }
namespace Render { struct World {
virtual void slot0(); unsigned pad4,field8,fieldC; Small_1c9030 first; StoreBase rooms; unsigned entries[256]; unsigned field538; unsigned fields53c[4]; unsigned field54c; char pad550[0x200]; Resource_1c9030* resource; unsigned pad754; Small_1c9030 last; pure3d::ShadowGenerator* shadow; World();
}; }
Render::World::World() {
first.FUN_0027af00(); rooms.FUN_001c77e0(250,1); new (&rooms) Store<Room>;
for(int i=0;i<256;++i) entries[i]=0;
for(int j=0;j<4;++j) fields53c[j]=0;
last.FUN_0027af00();
for(int k=0;k<4;++k) fields53c[k]=0;
field538=0; field54c=0; field8=0; fieldC=0;
Resource_1c9030* r=(Resource_1c9030*)FUN_00263ea0(32); if(r) r=r->FUN_0028edb0(); resource=r; r->init(); resource->stream->s6(0x444d4c42,4);
pure3d::ShadowGenerator* s=(pure3d::ShadowGenerator*)FUN_0008d690(20);
if(s) { s->value=0; new(s) pure3d::ShadowGenerator; s->data.FUN_002a30a0(); }
shadow=s; s->init();
}