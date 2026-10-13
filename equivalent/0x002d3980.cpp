// STATUS: equivalent (tools/equiv.py level 3: 37 inputs, branch coverage 16/16)
// FUN_002d3980 @ 0x002d3980
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
struct Ref { virtual void AddRef()=0; virtual void Release()=0; };
struct Small { char data[8]; void FUN_0027af70(const Small*); };
namespace pure3d {
struct ParticleGenerator {
 virtual void placeholder();
 unsigned int unknown4; Small data; unsigned char flag; char pad11[3];
 unsigned int a14,a18,count,a20,a24; Ref* object; Ref** items; Ref** end; unsigned int a34; unsigned int fields[10];
 void FUN_0027b070();
};
struct ParticlePlaneGenerator: ParticleGenerator { virtual void placeholder(); ParticlePlaneGenerator* copy(const ParticlePlaneGenerator&); };
}
void* __cdecl FUN_0008d6d0(unsigned int);
pure3d::ParticlePlaneGenerator* pure3d::ParticlePlaneGenerator::copy(const ParticlePlaneGenerator& src) {
 FUN_0027b070(); new(this) ParticleGenerator;
 flag=src.flag; a14=src.a14; a18=src.a18; count=src.count; a20=src.a20;
 data.FUN_0027af70(&src.data);
 new(this) ParticlePlaneGenerator;
 object=0;
 unsigned int bytes=src.count*4;
 if(src.count>0) { items=(Ref**)FUN_0008d6d0(bytes); if(items) end=(Ref**)((char*)items+bytes); else {items=0;end=0;} } else {items=0;end=0;}
 for(unsigned int j=0;j<10;++j) fields[j]=src.fields[j];
 Ref* r=src.object; if(r) r->AddRef(); if(object) object->Release(); object=r;
 for(unsigned int i=0;i<count;++i) { items[i]=0; Ref** slot=items+i; Ref* value=src.items[i]; if(value) value->AddRef(); if(*slot) (*slot)->Release(); *slot=value; }
 return this;
}
