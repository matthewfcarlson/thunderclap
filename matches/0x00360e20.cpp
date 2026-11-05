extern "C" int __cdecl atexit(void(__cdecl* f)());
class SeqEventCrossFadeType_360e20 {
  public:
    virtual void FUN_002555c0();
};
extern SeqEventCrossFadeType_360e20 gReg_360e20;
extern "C" void __cdecl FUN_003645f0();
void __cdecl Init() {
    gReg_360e20.FUN_002555c0();
    atexit(FUN_003645f0);
}
