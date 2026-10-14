class ParticleController {
  public:
    virtual int vfunc_0();
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_3();
    virtual int vfunc_4();
};
class Other_2a7540 {
  public:
    int helper(ParticleController*);
};
extern "C" void* __cdecl allocate(int);
int ParticleController::vfunc_4() {
    ParticleController* self = this;
    Other_2a7540* p = (Other_2a7540*)allocate(0x60);
    if (p)
        return p->helper(self);
    return 0;
}