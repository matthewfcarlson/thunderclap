// STATUS: equivalent (tools/equiv.py level 3: 195 inputs, branch coverage 10/10)
// FUN_002ab6a0 @ 0x002ab6a0
void* __cdecl FUN_0008d690(unsigned int);
void* __cdecl memmove(void*, const void*, unsigned int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
namespace pure3d {
struct DefaultParticleGeneratorHandler {
 virtual void slot0();
 unsigned int value;
};
struct ParticleGeneratorLoader {
 virtual void slot0();
 virtual void slot1();
 unsigned int value;
 unsigned int count;
 DefaultParticleGeneratorHandler* handlers[8];
};
struct ParticleEmitterLoader {
 virtual void slot0();
 unsigned int baseValue;
 unsigned int value;
 unsigned int values[8];
 ParticleGeneratorLoader* loader;
 void FUN_002a3e80();
 ParticleEmitterLoader* init();
};
ParticleEmitterLoader* ParticleEmitterLoader::init() {
 FUN_002a3e80();
 new (this) ParticleEmitterLoader;
 value=0; loader=0;
 for(int i=0;i<8;++i) values[i]=0;
 ParticleGeneratorLoader* p=(ParticleGeneratorLoader*)FUN_0008d690(44);
 if(p) {
  new (p) ParticleGeneratorLoader;
  p->value=0; p->count=0;
  for(int j=0;j<8;++j) p->handlers[j]=0;
 }
 if(p) p->slot0();
 if(loader) loader->slot1();
 loader=p;
 DefaultParticleGeneratorHandler* h=(DefaultParticleGeneratorHandler*)FUN_0008d690(8);
 if(h) { new(h) DefaultParticleGeneratorHandler; h->value=0; }
 p=loader;
 if(h) {
  memmove(p->handlers+1,p->handlers,p->count*4);
  p->handlers[0]=h;
  h->slot0();
  ++p->count;
 }
 return this;
}
}
