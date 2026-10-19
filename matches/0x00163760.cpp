class Caster_163760 {
  public:
    virtual void Cast();
};
class Receiver {
  public:
    void Use(void*);
};
void* Find(void*, Caster_163760*);
void Target(Receiver* receiver, void* value) {
    Caster_163760 caster;
    void* result = Find(value, &caster);
    receiver->Use(result);
}