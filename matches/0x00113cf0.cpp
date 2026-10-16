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
void func(Factory* f, void* p) {
    Caster c;
    f->Set(Find(p, &c));
}