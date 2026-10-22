class TrackFactoryCasterTemplate_14b570 {
  public:
    virtual void dummy();
};
class Obj {
  public:
    void apply(void*);
};
void* __cdecl find(void*, TrackFactoryCasterTemplate_14b570*);
void fn(Obj* o, void* p) {
    TrackFactoryCasterTemplate_14b570 c;
    o->apply(find(p, &c));
}