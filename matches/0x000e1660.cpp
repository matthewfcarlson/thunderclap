class FEParticleSystem {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(void*);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    char pad[0x2c - 4];
    void* field;
};
void FEParticleSystem::vfunc_1(void* value) {
    field = value;
}