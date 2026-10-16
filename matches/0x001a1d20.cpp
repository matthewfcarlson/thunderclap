class Caster {
  public:
    virtual void cast();
};
class Track {
  public:
    void* get(void*);
};
extern void* find(const char*, Caster*);
void* func(Track* t, const char* name) {
    Caster c;
    return t->get(find(name, &c));
}