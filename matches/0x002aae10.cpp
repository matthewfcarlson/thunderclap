class Ref_2aae10 {
  public:
    virtual void a();
    virtual void Release();
};
extern int particleVtable;
extern int refVtable_2aae10;
class ParticleGeneratorLoader {
  public:
    int* vptr;
    int pad;
    unsigned count;
    Ref_2aae10* items[1];
    void cleanup();
};
void ParticleGeneratorLoader::cleanup() {
    vptr = &particleVtable;
    for (unsigned i = 0; i < count; ++i) {
        if (items[i]) {
            items[i]->Release();
            items[i] = 0;
        }
    }
    vptr = &refVtable_2aae10;
}