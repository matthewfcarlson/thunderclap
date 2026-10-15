namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
class CTriggerVolumeManager {
  public:
    bool Execute(math::Vector, const char*, bool);
};
typedef bool (CTriggerVolumeManager::*Fn)(math::Vector, const char*, bool);
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Params {
    math::Vector v;
    const char* name;
    bool flag;
};
class Method3 : public Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CTriggerVolumeManager*, Params*, bool*);
    char pad[0x18];
    Fn method;
};
void Method3::vfunc_2(CTriggerVolumeManager* obj, Params* p, bool* result) {
    Fn fn = method;
    const char* name = p->name;
    bool flag = p->flag;
    bool r = (obj->*fn)(p->v, name, flag);
    if (result)
        *result = r;
}