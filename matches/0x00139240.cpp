class Caster_139240 {
  public:
    virtual void cast();
};
class Manager {
  public:
    void* get(void*);
};
extern void* find(const char*, Caster_139240*);
void* target(Manager* m, const char* name) {
    Caster_139240 caster;
    return m->get(find(name, &caster));
}