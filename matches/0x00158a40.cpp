class TrackFactoryCasterTemplate_158a40 {
  public:
    virtual void f();
};
class Obj {
  public:
    void use(void*);
};
void* __cdecl find(const char*, TrackFactoryCasterTemplate_158a40*);
extern "C" void __cdecl FUN_00158a40(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_158a40 c;
    obj->use(find(name, &c));
}