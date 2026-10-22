class TrackFactoryCasterTemplate_158b30 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void set(void*);
};
extern "C" void* __cdecl find(const char*, TrackFactoryCasterTemplate_158b30*);
void f(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_158b30 c;
    obj->set(find(name, &c));
}