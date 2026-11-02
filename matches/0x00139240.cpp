class TrackFactoryCasterTemplate_139240 {
  public:
    virtual void cast();
};
class Manager {
  public:
    void* get(void*);
};
extern void* find(const char*, TrackFactoryCasterTemplate_139240*);
extern "C" void* FUN_00139240(Manager* m, const char* name) {
    TrackFactoryCasterTemplate_139240 caster;
    return m->get(find(name, &caster));
}