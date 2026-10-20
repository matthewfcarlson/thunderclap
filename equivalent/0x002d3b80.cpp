// STATUS: equivalent (tools/equiv.py level 3: 37 inputs, branch coverage 16/16)
// FUN_002d3b80 @ 0x002d3b80
#include "compat/ptr.h"
typedef unsigned int uint;
struct Ref_2d3b80 { virtual void AddRef(); virtual void Release(); };
struct Small_2d3b80 { void FUN_0027af70(const Small_2d3b80*); char data[8]; };
struct FUN_0027b070 { virtual void placeholder(); uint f4; FUN_0027b070(); };
namespace pure3d {
struct ParticleGenerator : FUN_0027b070 {
 virtual void placeholder();
 Small_2d3b80 small;
 unsigned char flag; char pad11[3];
 uint f14,f18,count,f20,f24;
 Ref_2d3b80* object; Ref_2d3b80** entries; Ref_2d3b80** end;
 uint f34,f38,f3c,f40,f44;
 ParticleGenerator(const ParticleGenerator& source) {
 flag=source.flag; f14=source.f14; f18=source.f18; count=source.count; f20=source.f20;
 small.FUN_0027af70(&source.small);
 }
};
struct ParticleSphereGenerator : ParticleGenerator {
 virtual void placeholder();
 ParticleSphereGenerator(const ParticleSphereGenerator& source);
};
}
void* __cdecl FUN_0008d6d0(hulk_uintptr);
pure3d::ParticleSphereGenerator::ParticleSphereGenerator(const ParticleSphereGenerator& source) : ParticleGenerator(source) {
 object=0;
 uint size=source.count*4;
 if(source.count) {
 entries=(Ref_2d3b80**)FUN_0008d6d0(size);
 if(entries) end=(Ref_2d3b80**)((char*)entries+size);
 else { entries=0; end=0; }
 } else { entries=0; end=0; }
 f38=source.f38; f3c=source.f3c; f40=source.f40; f44=source.f44;
 Ref_2d3b80* obj=source.object;
 if(obj) obj->AddRef();
 if(object) object->Release();
 object=obj;
 for(uint i=0;i<count;++i) {
 entries[i]=0;
 Ref_2d3b80** slot=&entries[i];
 Ref_2d3b80* item=source.entries[i];
 if(item) item->AddRef();
 if(*slot) (*slot)->Release();
 *slot=item;
 }
}