class Caster {
  public:
    virtual void Cast();
};
class Receiver {
  public:
    void Use(void*);
};
void* Find(void*, Caster*);
void Target(Receiver* receiver, void* value) {
    Caster caster;
    void* result = Find(value, &caster);
    receiver->Use(result);
}