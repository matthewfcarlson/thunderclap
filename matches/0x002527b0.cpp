class Base {
  public:
    void Init();
};
class SeqEventVarVolume : public Base {
  public:
    int vtable;
    int pad;
    float volume;
    SeqEventVarVolume* Build();
};
SeqEventVarVolume* SeqEventVarVolume::Build() {
    Init();
    vtable = 0x429fac;
    volume = 1.0f;
    return this;
}