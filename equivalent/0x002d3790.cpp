// STATUS: equivalent (tools/equiv.py level 3: 37 inputs, branch coverage 16/16)
// FUN_002d3790 @ 0x002d3790
typedef unsigned size_t;
void* __cdecl operator new(size_t,void*);
struct Ref { virtual void AddRef(); virtual void Release(); };
struct Part { unsigned a,b; void FUN_0027af70(const Part*); };
namespace pure3d {
struct ParticleGenerator {virtual void slot0(); unsigned field4;Part part;unsigned char flag;char pad11[3];unsigned f14,f18,count,f20,f24;Ref* ref;Ref** items;Ref** end;unsigned f34,f38,f3c,f40,f44,f48,f4c;void FUN_0027b070();};
struct ParticlePointGenerator:ParticleGenerator {virtual void slot0(); ParticlePointGenerator* copy(const ParticlePointGenerator&);};
}
extern "C" void* __cdecl FUN_0008d6d0(unsigned);
pure3d::ParticlePointGenerator* pure3d::ParticlePointGenerator::copy(const ParticlePointGenerator& src) {
 FUN_0027b070();
 this->ParticleGenerator::ParticleGenerator();
 flag=src.flag;f14=src.f14;f18=src.f18;count=src.count;f20=src.f20;part.FUN_0027af70(&src.part);
 this->ParticlePointGenerator::ParticlePointGenerator();
 ref=0;unsigned bytes=src.count*4;
 if(src.count){items=(Ref**)FUN_0008d6d0(bytes);if(items)end=(Ref**)((char*)items+bytes);else{items=0;end=0;}}else{items=0;end=0;}
 f38=src.f38;f3c=src.f3c;f40=src.f40;f44=src.f44;f48=src.f48;f4c=src.f4c;
 Ref* r=src.ref;if(r)r->AddRef();if(ref)ref->Release();ref=r;
 for(unsigned i=0;i<count;++i){items[i]=0;Ref** dst=&items[i];Ref* r=src.items[i];if(r)r->AddRef();if(*dst)(*dst)->Release();*dst=r;}return this;
}
