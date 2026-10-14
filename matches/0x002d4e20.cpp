namespace pure3d {
class Ref_2d4e20 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class ParticleEmitter {
  public:
    char pad[0x90];
    Ref_2d4e20* mRef;
    void vfunc_31(Ref_2d4e20*);
};
void ParticleEmitter::vfunc_31(Ref_2d4e20* p) {
    if (p != mRef) {
        if (p)
            p->AddRef();
        if (mRef)
            mRef->Release();
        mRef = p;
    }
}
} // namespace pure3d