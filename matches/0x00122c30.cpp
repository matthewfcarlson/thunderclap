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
void target(Obj* o, void* name) {
    TrackFactoryCasterTemplate_122c30 c;
    Track* p = find(name, &c);
    o->apply(p);
}