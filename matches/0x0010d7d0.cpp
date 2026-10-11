extern const float gZero;
class Action {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float Get();
    char pad04[0x10];
    int m14;
    int m18;
};
class State {
  public:
    char pad[4];
};
class Manager {
  public:
    void* First();
    char* Second();
};
class ButtonAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4();
    virtual void v5();
    char pad04[0x18];
    Action* action;
    State* state;
};
void ButtonAction::vfunc_4() {
    if (state && (action->m18 == 2 || action->m18 == 1)) {
        float f = action->Get();
        if (f < gZero || f > gZero) {
            Manager* m = (Manager*)state;
            char* v = ((Manager*)m->First())->Second() + 0x1f58;
            *(int*)(v + action->m14 * 12) = 0;
        }
    }
}
