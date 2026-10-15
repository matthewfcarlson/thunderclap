namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
class CTriggerVolumeManager {
  public:
    bool method(math::Vector, const char*, bool);
};
struct Args {
    math::Vector v;
    const char* str;
    bool flag;
};
class Closure3 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void vfunc_2(void*, Args*, bool*);
    char pad[0x18];
    bool (CTriggerVolumeManager::*fn)(math::Vector, const char*, bool);
    CTriggerVolumeManager* obj;
};
void Closure3::vfunc_2(void*, Args* args, bool* out) {
    CTriggerVolumeManager* p = obj;
    bool (CTriggerVolumeManager::*f)(math::Vector, const char*, bool) = fn;
    Args* a = args;
    bool b = a->flag;
    const char* s = a->str;
    *(volatile bool*)&args = b;
    bool r = (p->*f)(a->v, s, *(bool*)&args);
    if (out)
        *out = r;
}