class ParticleObject {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void Update(float);
};
typedef float (__stdcall *TimeFn)(int);
extern TimeFn g_timeFn;
class FEParticleSystem {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    char pad[0x24];
    ParticleObject* mObject;
    int mEnabled;
};
void FEParticleSystem::vfunc_2() {
    if (mEnabled) {
        mObject->Update(g_timeFn(0) * 1000.0f);
    }
}
