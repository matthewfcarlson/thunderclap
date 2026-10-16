class Caster {
  public:
    virtual void cast();
};
class Manager {
  public:
    void* get(void*);
};
extern void* find(const char*, Caster*);
void* target(Manager* m, const char* name) {
    Caster caster;
    return m->get(find(name, &caster));
}