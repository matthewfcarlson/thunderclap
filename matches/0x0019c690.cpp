class TrackFactoryCasterTemplate_19c690 {
  public:
    virtual void dummy();
};
class Obj {
  public:
    void Do(void*);
};
void* Cast(void*, TrackFactoryCasterTemplate_19c690*);
extern "C" void FUN_0019c690(Obj* obj, void* p) {
    TrackFactoryCasterTemplate_19c690 c;
    obj->Do(Cast(p, &c));
}