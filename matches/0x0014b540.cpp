class TrackFactoryCasterTemplate_14b540 {
  public:
    virtual void f();
};
extern "C" void* __cdecl findTrack(const char*, TrackFactoryCasterTemplate_14b540*);
class Owner {
  public:
    void set(void*);
};
void __cdecl FUN_0014b540(Owner* o, const char* name) {
    TrackFactoryCasterTemplate_14b540 c;
    o->set(findTrack(name, &c));
}
