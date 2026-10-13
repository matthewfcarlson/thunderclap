extern int gData;
class Obj {
  public:
    void Run();
};
void __stdcall Wrapper() {
    Obj* p = (Obj*)&gData;
    p->Run();
}
