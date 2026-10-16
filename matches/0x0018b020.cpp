class Caster {
  public:
    virtual void Cast();
};
class Receiver {
  public:
    void Fn(void*);
};
void* Find(void*, Caster*);
void Target(Receiver* receiver, void* name) {
    Caster caster;
    receiver->Fn(Find(name, &caster));
}