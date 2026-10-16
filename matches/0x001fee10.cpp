class CTriggerVolumeManager {
  public:
    void Action(const char*, bool);
};
struct Args {
    const char* s;
    bool b;
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
class Method2 : public Function {
  public:
    char pad[24];
    void (CTriggerVolumeManager::*method)(const char*, bool);
    virtual void v2(CTriggerVolumeManager*, Args*, void*);
};
void Method2::v2(CTriggerVolumeManager* obj, Args* a, void*) {
    (obj->*method)(a->s, a->b);
}