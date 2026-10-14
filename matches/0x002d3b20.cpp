// Same code shape as 0x002a7540 (propagated; names are from that function)
class ParticleController {
  public:
    virtual int vfunc_0();
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_3();
    virtual int vfunc_4();
};
class Other_2d3b20 {
  public:
    int helper(ParticleController*);
};
extern "C" void* __cdecl allocate(int);
int ParticleController::vfunc_4() {
    ParticleController* self = this;
    Other_2d3b20* p = (Other_2d3b20*)allocate(0x60);
    if (p)
        return p->helper(self);
    return 0;
}