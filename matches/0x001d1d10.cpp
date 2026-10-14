typedef unsigned int uint;
void __cdecl DoThing(uint, int);
class Target_1d1d10 {
    char pad[8];
    uint value;

  public:
    unsigned char __fastcall Run();
};
unsigned char __fastcall Target_1d1d10::Run() {
    DoThing(value, -3);
    return 1;
}