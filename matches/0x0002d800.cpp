struct CActorManager {
    char unused;
};
struct Method4 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager*, const char*, void*);
    char pad[0x18];
    void (CActorManager::*method)(const char*, float, int, float);
};
void Method4::vfunc_2(CActorManager* actor, const char* args, void*) {
    const char* name = *(const char**)args;
    args += 4;
    float value = *(float*)args;
    args += 4;
    int count = *(int*)args;
    args += 4;
    float other = *(float*)args;
    (actor->*method)(name, value, count, other);
}