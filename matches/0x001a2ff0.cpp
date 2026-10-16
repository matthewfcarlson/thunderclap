class Base {
  public:
    Base(int);
    virtual void f();
};
class Part {
  public:
    Part();
};
class Event_PropTypeCondition : public Base {
    char pad[12];
    Part part;

  public:
    Event_PropTypeCondition();
    virtual void f();
};
Event_PropTypeCondition::Event_PropTypeCondition() : Base(0), part() {}