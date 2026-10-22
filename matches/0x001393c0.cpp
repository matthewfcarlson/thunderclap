class TrackFactoryCasterTemplate_1393c0 {
  public:
    virtual void cast();
};
class Manager {
  public:
    int get(void* p);
};
extern "C" void* first(void*, TrackFactoryCasterTemplate_1393c0*);
int __cdecl target(Manager* mgr, void* name) {
    TrackFactoryCasterTemplate_1393c0 caster;
    void* p = first(name, &caster);
    return mgr->get(p);
}