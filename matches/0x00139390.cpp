class TrackFactoryCasterTemplate_139390 {
  public:
    virtual void cast();
};
extern "C" int __cdecl first(int, TrackFactoryCasterTemplate_139390*);
class Obj {
  public:
    void second(int);
};
void func(Obj* o, int n) {
    TrackFactoryCasterTemplate_139390 c;
    int r = first(n, &c);
    o->second(r);
}