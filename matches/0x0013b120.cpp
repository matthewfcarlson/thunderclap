namespace hulkfight {
namespace motion {
struct Obj {
    virtual void f0();
    virtual void f1();
    char pad[0x220];
    unsigned char flag;
};
struct Result {
    void StopA(Obj*, int);
    void StopB(Obj*, int, float);
};
struct Mid {
    Result* Get();
};
struct Owner {
    Mid* Get();
};
class AnimationVelocityScaledAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4();
    virtual void v5();
    char pad[0x1c];
    Owner* owner;
    Obj* obj;
};
void AnimationVelocityScaledAction::vfunc_4() {
    if (!obj)
        return;
    Result* p = owner->Get()->Get();
    if (!p)
        return;
    if (obj->flag)
        p->StopB(obj, 0, -1.0f);
    else
        p->StopA(obj, 0);
    if (obj) {
        obj->f1();
        obj = 0;
    }
}
} // namespace motion
} // namespace hulkfight