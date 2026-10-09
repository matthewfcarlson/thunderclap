class SeqAction {
  public:
    int mVptr;
};
extern void Register(void*, void*);
class SeqActionVarPitchRand : public SeqAction {
  public:
    SeqActionVarPitchRand* vfunc_0(int);
};
SeqActionVarPitchRand* SeqActionVarPitchRand::vfunc_0(int flag) {
    SeqActionVarPitchRand* self = this;
    self->mVptr = 0x4298fc;
    if (flag & 1)
        Register((void*)0x4e70a0, self);
    return self;
}