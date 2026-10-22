class TrackFactoryCasterTemplate_1463a0 {
  public:
    virtual void Cast();
};
struct Target {
    int Get(void*);
};
extern "C" void* __cdecl Find(void*, TrackFactoryCasterTemplate_1463a0*);
int F(Target* t, void* x) {
    TrackFactoryCasterTemplate_1463a0 c;
    void* p = Find(x, &c);
    return t->Get(p);
}