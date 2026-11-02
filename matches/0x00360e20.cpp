extern "C" int __cdecl atexit(void(__cdecl* f)());
class SeqEventCrossFadeType_360e20 {
  public:
    virtual void Reg();
};
extern SeqEventCrossFadeType_360e20 gReg_360e20;
extern "C" void __cdecl FUN_003645f0();
void __cdecl Init() {
    gReg_360e20.Reg();
    atexit(FUN_003645f0);
}
