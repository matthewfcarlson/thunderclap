extern "C" int __cdecl atexit(void(__cdecl* f)());
class RegObj {
  public:
    virtual void Reg();
};
extern RegObj gReg_360e20;
extern "C" void __cdecl Cleanup();
void __cdecl Init() {
    gReg_360e20.Reg();
    atexit(Cleanup);
}
