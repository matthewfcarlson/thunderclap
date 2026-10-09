// Same code shape as 0x001bc710 (propagated; names are from that function)
class X {
  public:
    void Run();
};
extern X* __cdecl Make();
void __cdecl target() {
    Make()->Run();
}