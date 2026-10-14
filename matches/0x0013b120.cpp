namespace hulkfight {
namespace motion {
struct Obj_13b120 {
    virtual void f0();
    virtual void f1();
    char pad[0x220];
    unsigned char flag;
};
struct Result_13b120 {
    void StopA(Obj_13b120*, int);
    void StopB(Obj_13b120*, int, float);
};
struct Mid_13b120 {
    Result_13b120* Get();
};
struct Owner_13b120 {
    Mid_13b120* Get();
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
    Owner_13b120* owner;
    Obj_13b120* obj;
};
void AnimationVelocityScaledAction::vfunc_4() {
    if (!obj)
        return;
    Result_13b120* p = owner->Get()->Get();
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