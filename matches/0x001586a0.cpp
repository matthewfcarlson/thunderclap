class Caster {
  public:
    virtual void Cast();
};
class Receiver {
  public:
    void Set(void*);
};
void* Find(void*, Caster*);
void Target(Receiver* receiver, void* value) {
    Caster caster;
    receiver->Set(Find(value, &caster));
}