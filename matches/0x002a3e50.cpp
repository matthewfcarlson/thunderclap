class ParticleSystem {
public:
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
    virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void vfunc_9();
    virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14();
    virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18();
    char pad[0xa0];
    class Callback *mCallback;
};
class Callback {
public:
    virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3(); virtual void b4(); virtual void b5();
    virtual void b6(); virtual void b7(); virtual void b8(); virtual void b9(); virtual void b10(); virtual void b11();
    virtual void Invoke(int);
};
extern void FUN_002a3b60();
void ParticleSystem::vfunc_9() {
    FUN_002a3b60();
    if (mCallback) mCallback->Invoke(0);
}
