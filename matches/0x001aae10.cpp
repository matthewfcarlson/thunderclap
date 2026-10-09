class Sub {
  public:
    void Init();
};
class Base {
  public:
    void Tail();
};
class Event_TriggerVolumeNameCondition : public Base {
  public:
    void* vptr;
    char pad[0x0c];
    Sub sub;
    void Fn();
};
void Event_TriggerVolumeNameCondition::Fn() {
    vptr = (void*)0x41d3cc;
    sub.Init();
    Tail();
}