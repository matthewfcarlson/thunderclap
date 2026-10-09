class ParticleController { public: virtual int vfunc_0(); virtual int vfunc_1(); virtual int vfunc_2(); virtual int vfunc_3(); virtual int vfunc_4(); };
class Other { public: int helper(ParticleController*); };
extern "C" void* __cdecl allocate(int);
int ParticleController::vfunc_4() {
    ParticleController* self = this;
    Other* p = (Other*)allocate(0x60);
    if (p) return p->helper(self);
    return 0;
}