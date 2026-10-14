namespace pure3d {
struct Ref_2d4de0 {
    virtual void Release();
    virtual void AddRef();
};
class ParticleEmitter {
  public:
    char pad[0x8c];
    Ref_2d4de0* item;
    void vfunc_29(Ref_2d4de0*);
};
void ParticleEmitter::vfunc_29(Ref_2d4de0* p) {
    if (p != item) {
        if (p)
            p->Release();
        if (item)
            item->AddRef();
        item = p;
    }
}
} // namespace pure3d