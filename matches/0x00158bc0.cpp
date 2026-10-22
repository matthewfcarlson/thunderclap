class TrackFactoryCasterTemplate_158bc0 {
  public:
    virtual void Cast();
};
extern void* Find(void*, TrackFactoryCasterTemplate_158bc0*);
class Factory {
  public:
    void Add(void*);
};
void Function(Factory* f, void* name) {
    TrackFactoryCasterTemplate_158bc0 caster;
    void* obj = Find(name, &caster);
    f->Add(obj);
}
