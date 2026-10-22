class TrackFactoryCasterTemplate_139240 {
  public:
    virtual void cast();
};
class Manager {
  public:
    void* get(void*);
};
extern void* find(const char*, TrackFactoryCasterTemplate_139240*);
void* target(Manager* m, const char* name) {
    TrackFactoryCasterTemplate_139240 caster;
    return m->get(find(name, &caster));
}