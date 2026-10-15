struct Owner {
    char pad[0x18];
    int sem;
    char pad2[5];
    char active;
};
class Agent {
  public:
    Agent* Get();
    Agent* Next();
    void Clear();
    void Clear2(Owner*, int, int);
};
namespace hulkfight {
namespace ai {
class SemaphoreClearAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void vfunc_4();
    virtual void f5();
    char pad[0x18];
    Owner* owner;
    Agent* agent;
};
void SemaphoreClearAction::vfunc_4() {
    if (agent) {
        Agent* a = agent->Get()->Next();
        Owner* o = owner;
        if (o->active) {
            a->Clear();
            return;
        }
        a->Clear2((Owner*)((char*)o + 0x18), 0, 1);
    }
}
} // namespace ai
} // namespace hulkfight