extern "C" char DAT_0041d3cc[];
class Sub_1aae10 {
  public:
    void Init();
};
class Base_1aae10 {
  public:
    void Tail();
};
class Event_TriggerVolumeNameCondition : public Base_1aae10 {
  public:
    void* vptr;
    char pad[0x0c];
    Sub_1aae10 sub;
    void Fn();
};
void Event_TriggerVolumeNameCondition::Fn() {
    vptr = (void*)((int)DAT_0041d3cc);
    sub.Init();
    Tail();
}