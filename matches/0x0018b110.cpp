class TrackFactoryCasterTemplate_18b110 {
  public:
    virtual void Cast();
};
class Target {
  public:
    void* Do(void*);
};
extern "C" void* Find(void*, TrackFactoryCasterTemplate_18b110*);
void* Func(Target* t, void* name) {
    TrackFactoryCasterTemplate_18b110 c;
    void* p = Find(name, &c);
    return t->Do(p);
}