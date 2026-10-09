class X {
  public:
    void Run();
};
extern X* __cdecl Make();
void __cdecl target() {
    Make()->Run();
}