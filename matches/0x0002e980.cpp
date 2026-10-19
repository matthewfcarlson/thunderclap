extern "C" void _ReadWriteBarrier();
class CActorManager {};
struct Arguments {
    const char* name;
    float value;
    const char* other;
};
class Closure3 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int, Arguments*, int);

  private:
    char padding[0x18];

  public:
    void (CActorManager::*method)(const char*, float, const char*);
    CActorManager* actor;
};
void Closure3::vfunc_2(int unused, Arguments* args, int unused2) {
    const char* name = args->name;
    _ReadWriteBarrier();
    const char* other = args->other;
    float value = args->value;
    (actor->*method)(name, value, other);
    _ReadWriteBarrier();
}