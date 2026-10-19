class Caster_18b020 {
  public:
    virtual void Cast();
};
class Receiver {
  public:
    void Fn(void*);
};
void* Find(void*, Caster_18b020*);
void Target(Receiver* receiver, void* name) {
    Caster_18b020 caster;
    receiver->Fn(Find(name, &caster));
}