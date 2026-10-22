struct Member_10c7d0 {
    void Release();
};
struct Condition_10c7d0 {
    virtual void g();
    void Shutdown();
};
struct AIFightNodeCondition_10c7d0 : Condition_10c7d0 {
    char pad[8];
    Member_10c7d0 m;
    ~AIFightNodeCondition_10c7d0();
    virtual void f();
};
AIFightNodeCondition_10c7d0::~AIFightNodeCondition_10c7d0() {
    m.Release();
    Shutdown();
}
