typedef unsigned int u32;
struct DefaultParticleEmitterHandler;
struct HandlerBase {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(u32, u32, u32, u32);
};
struct Query {
    void* GetType();
};
struct DefaultParticleEmitterHandler : HandlerBase {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(u32, u32, u32, u32);
    void Dispatch(u32, u32, u32, u32);
};
void DefaultParticleEmitterHandler::e(u32 first, u32 obj, u32 third, u32 fourth) {
    if ((u32)((Query*)obj)->GetType() == 0x15900)
        Dispatch(first, obj, third, fourth);
}