class Caster {
  public:
    virtual void cast();
};
class Token {};
class Factory {
  public:
    void Set(Token*);
};
Token* Find(void*, Caster*);
extern "C" void FUN_00113cf0(Factory* f, void* p) {
    Caster c;
    f->Set(Find(p, &c));
}