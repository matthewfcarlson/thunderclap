class TrackFactoryCasterTemplate_162280 {
  public:
    virtual void f();
};
class Obj {
  public:
    void run(void*);
};
extern "C" void* find(void*, TrackFactoryCasterTemplate_162280*);
void FUN_00162280(Obj* obj, void* p) {
    TrackFactoryCasterTemplate_162280 c;
    void* v = find(p, &c);
    obj->run(v);
}