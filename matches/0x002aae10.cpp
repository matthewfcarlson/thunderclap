class Ref { public: virtual void a(); virtual void Release(); };
extern int particleVtable;
extern int refVtable;
class ParticleGeneratorLoader { public: int* vptr; int pad; unsigned count; Ref* items[1]; void cleanup(); };
void ParticleGeneratorLoader::cleanup() { vptr=&particleVtable; for (unsigned i=0; i<count; ++i) { if (items[i]) { items[i]->Release(); items[i]=0; } } vptr=&refVtable; }