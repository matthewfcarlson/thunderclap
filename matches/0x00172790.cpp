struct Obj {
    char pad[0x1b0c];
    float amount;
    float Get();
    void Set(float, int);
};
struct Mid {
    Obj* GetObj();
};
struct Source {
    Mid* GetMid();
};
struct Param {
    char pad[0x10];
    float amount;
};
namespace hulkfight {
namespace motion {
class CriticalMassDrainAction {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual char vfunc_3(int, int);
    char pad[0x18];
    Param* param;
    Source* src;
};
char CriticalMassDrainAction::vfunc_3(int x, int y) {
    if (!src)
        return 0;
    Mid* m = src->GetMid();
    if (!m)
        return 0;
    Obj* o = m->GetObj();
    if (!o)
        return 0;
    float amt = o->amount;
    if (amt >= o->Get())
        o->Set(amt - param->amount, 1);
    return 0;
}
} // namespace motion
} // namespace hulkfight