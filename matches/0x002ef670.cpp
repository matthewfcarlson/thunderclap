extern "C" void* memcpy(void*, const void*, unsigned int);
class SimState {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void vfunc_12(float*, float, bool);
    virtual void a13();
    virtual void a14();
    char pad[0x3c];
    float x, y, z;
    char p[0x6c - 0x4c];
    int mode;
    void* ptr;
    void update(void*, void*);
};
void SimState::vfunc_12(float* delta, float dt, bool apply) {
    if (!ptr || mode != 1)
        return;
    float temp[16];
    memcpy(temp, (char*)this + 0x10, 64);
    x += delta[0];
    y += delta[1];
    z += delta[2];
    update(temp, (char*)this + 0x10);
    if (apply) {
        float s = 1.0f / dt;
        *(float*)((char*)this + 0x50) += s * delta[0];
        *(float*)((char*)this + 0x54) += s * delta[1];
        *(float*)((char*)this + 0x58) += s * delta[2];
    }
}