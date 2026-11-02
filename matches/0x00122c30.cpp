class TrackFactoryCasterTemplate_122c30 {
  public:
    virtual void cast();
};
class Track;
class Obj {
  public:
    void apply(Track*);
};
Track* find(void*, TrackFactoryCasterTemplate_122c30*);
extern "C" void FUN_00122c30(Obj* o, void* name) {
    TrackFactoryCasterTemplate_122c30 c;
    Track* p = find(name, &c);
    o->apply(p);
}