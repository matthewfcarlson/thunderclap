class Caster {
  public:
    virtual void Cast();
};
class Arg {
  public:
    void Do(void*);
};
extern void* Search(void*, Caster*);
void FUN_001ac2b0(Arg* obj, void* key) {
    Caster caster;
    void* result = Search(key, &caster);
    obj->Do(result);
}