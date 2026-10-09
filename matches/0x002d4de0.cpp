namespace pure3d {
struct Ref {
    virtual void Release();
    virtual void AddRef();
};
class ParticleEmitter {
  public:
    char pad[0x8c];
    Ref* item;
    void vfunc_29(Ref*);
};
void ParticleEmitter::vfunc_29(Ref* p) {
    if (p != item) {
        if (p)
            p->Release();
        if (item)
            item->AddRef();
        item = p;
    }
}
} // namespace pure3d