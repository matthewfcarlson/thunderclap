// Same code shape as 0x001bc710 (propagated; names are from that function)
class X_1bc720 {
  public:
    void Run();
};
extern X_1bc720* __cdecl Make();
void __cdecl target() {
    Make()->Run();
}