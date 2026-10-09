extern "C" void __cdecl F1(int, int);
extern "C" void __cdecl F2(int, float);
extern "C" void __cdecl F3(int, int);
class Obj {
  public:
    char pad[8];
    int field;
    bool Run(int a, int b);
};
bool Obj::Run(int a, int b) {
    F1(field, a);
    F2(field, (float)b);
    F3(field, -3);
    return true;
}