extern "C" char DAT_00429fac[];
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
    vtable = ((int)DAT_00429fac);
    volume = 1.0f;
    return this;
}