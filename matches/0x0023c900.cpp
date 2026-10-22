// Same code shape as 0x0010c7d0 (propagated; names are from that function)
struct Member_23c900 {
    void Release();
};
struct Condition_23c900 {
    virtual void g();
    void Shutdown();
};
struct SubConditionGroupCondition_23c900 : Condition_23c900 {
    char pad[8];
    Member_23c900 m;
    ~SubConditionGroupCondition_23c900();
    virtual void f();
};
SubConditionGroupCondition_23c900::~SubConditionGroupCondition_23c900() {
    m.Release();
    Shutdown();
}
