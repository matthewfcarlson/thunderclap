typedef unsigned int u32_2ad510;
struct DefaultParticleEmitterHandler;
struct HandlerBase {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(u32_2ad510, u32_2ad510, u32_2ad510, u32_2ad510);
};
struct Query_2ad510 {
    void* GetType();
};
struct DefaultParticleEmitterHandler : HandlerBase {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(u32_2ad510, u32_2ad510, u32_2ad510, u32_2ad510);
    void Dispatch(u32_2ad510, u32_2ad510, u32_2ad510, u32_2ad510);
};
void DefaultParticleEmitterHandler::e(u32_2ad510 first, u32_2ad510 obj, u32_2ad510 third, u32_2ad510 fourth) {
    if ((u32_2ad510)((Query_2ad510*)obj)->GetType() == 0x15900)
        Dispatch(first, obj, third, fourth);
}