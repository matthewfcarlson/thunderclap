class Caster_17d640 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void use(void*);
};
void* find(const char*, Caster_17d640*);
void FUN_0017d640(Obj* obj, const char* name) {
    Caster_17d640 c;
    obj->use(find(name, &c));
}