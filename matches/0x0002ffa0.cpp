class CActorManager {
  public:
    virtual float f(const char*, const char*);
};
class Closure2 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(unsigned*, unsigned*, float*);
    char pad[0x1c - 4];
    float (CActorManager::*mfn)(const char*, const char*);
    CActorManager* obj;
};
void Closure2::v2(unsigned* x, unsigned* args, float* out) {
    CActorManager* o = this->obj;
    float (CActorManager::*fn)(const char*, const char*) = mfn;
    const char* a = (const char*)args[0];
    const char* b = (const char*)args[1];
    float r = (o->*fn)(a, b);
    if (out)
        *out = r;
}
