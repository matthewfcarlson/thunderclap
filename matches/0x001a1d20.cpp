class Caster_1a1d20 {
  public:
    virtual void cast();
};
class Track {
  public:
    void* get(void*);
};
extern void* find(const char*, Caster_1a1d20*);
void* func(Track* t, const char* name) {
    Caster_1a1d20 c;
    return t->get(find(name, &c));
}