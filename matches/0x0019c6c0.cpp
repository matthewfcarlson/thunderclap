class TrackFactoryCasterTemplate_19c6c0 {
  public:
    virtual void cast();
};
void* __cdecl Find(void*, TrackFactoryCasterTemplate_19c6c0*);
class Obj {
  public:
    void Do(void*);
};
extern "C" void FUN_0019c6c0(Obj* a, void* b) {
    TrackFactoryCasterTemplate_19c6c0 c;
    void* p = Find(b, &c);
    a->Do(p);
}