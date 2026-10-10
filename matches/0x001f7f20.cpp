struct CEffectManager {
    bool run(bool);
};
class Closure1 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused, bool* arg, bool* out);
    char pad[0x1c - 4];
    bool (CEffectManager::*fn)(bool);
    CEffectManager* obj;
};
void Closure1::vfunc_2(int unused, bool* arg, bool* out) {
    CEffectManager* o = obj;
    bool b = *arg;
    bool (CEffectManager::*f)(bool) = fn;
    bool value = (o->*f)(b);
    if (out)
        *out = value;
}
