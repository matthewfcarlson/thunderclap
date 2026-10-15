class CTriggerVolumeManager {
  public:
    bool Fire(const char*, int, int, bool);
};
struct Args {
    const char* a;
    int b, c;
    bool d;
};
class Closure4 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(int, Args*, bool*);
    char pad[0x18];
    bool (CTriggerVolumeManager::*method)(const char*, int, int, bool);
    CTriggerVolumeManager* obj;
};
void Closure4::vfunc_2(int n, Args* args, bool* out) {
    CTriggerVolumeManager* o = obj;
    bool (CTriggerVolumeManager::*fn)(const char*, int, int, bool) = method;
    char* p = (char*)args;
    const char* a = *(const char**)p;
    int b = *(int*)(p += 4);
    int c = *(int*)(p += 4);
    bool d = *(bool*)(p += 4);
    bool r = (o->*fn)(a, b, c, d);
    if (out)
        *out = r;
}