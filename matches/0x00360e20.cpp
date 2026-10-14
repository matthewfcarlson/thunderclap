extern "C" int __cdecl atexit(void(__cdecl* f)());
class RegObj {
  public:
    virtual void Reg();
};
extern RegObj gReg;
extern "C" void __cdecl Cleanup();
void __cdecl Init() {
    gReg.Reg();
    atexit(Cleanup);
}
