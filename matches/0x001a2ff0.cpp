class Condition_1a2ff0 {
  public:
    Condition_1a2ff0(int);
    virtual void f();
};
class Part {
  public:
    Part();
};
class Event_PropTypeCondition : public Condition_1a2ff0 {
    char pad[12];
    Part part;

  public:
    Event_PropTypeCondition();
    virtual void f();
};
Event_PropTypeCondition::Event_PropTypeCondition() : Condition_1a2ff0(0), part() {}