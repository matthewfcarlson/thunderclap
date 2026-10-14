extern "C" void __cdecl F1(int, int);
extern "C" void __cdecl F2(int, float);
extern "C" void __cdecl F3(int, int);
class Obj_1d1dd0 {
  public:
    char pad[8];
    int field;
    bool Run(int a, int b);
};
bool Obj_1d1dd0::Run(int a, int b) {
    F1(field, a);
    F2(field, (float)b);
    F3(field, -3);
    return true;
}