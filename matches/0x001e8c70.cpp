typedef unsigned int U;
extern U __cdecl F40750();
extern U __cdecl F40750(U);
extern void __cdecl F416c0(U, U, int);
extern void __cdecl F43090(U);
extern void __cdecl F42ca0(U);
class Obj {
  public:
    char pad[0x34];
    int field;
};
class Target {
  public:
    char pad[0xc];
    Obj* p;
};
void __fastcall target(Target* self) {
    U x = F40750();
    Obj** q = &self->p;
    F416c0(x, (U)*q, 0);
    while ((*q)->field != 0) {
        x = F40750(0x3a83126f);
        F43090(x);
    }
    x = F40750((U)q);
    F42ca0(x);
}