class TrackFactoryCasterTemplate_189f60 {
  public:
    virtual void cast();
};
class Obj {
  public:
    int Do(void*);
};
extern void* Find(int, TrackFactoryCasterTemplate_189f60*);
int Func(Obj* obj, int name) {
    TrackFactoryCasterTemplate_189f60 c;
    return obj->Do(Find(name, &c));
}