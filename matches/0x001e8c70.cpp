typedef unsigned int U_1e8c70;
extern U_1e8c70 __cdecl F40750();
extern U_1e8c70 __cdecl F40750(U_1e8c70);
extern void __cdecl F416c0(U_1e8c70, U_1e8c70, int);
extern void __cdecl F43090(U_1e8c70);
extern void __cdecl F42ca0(U_1e8c70);
class Obj_1e8c70 {
  public:
    char pad[0x34];
    int field;
};
class Target_1e8c70 {
  public:
    char pad[0xc];
    Obj_1e8c70* p;
};
void __fastcall target(Target_1e8c70* self) {
    U_1e8c70 x = F40750();
    Obj_1e8c70** q = &self->p;
    F416c0(x, (U_1e8c70)*q, 0);
    while ((*q)->field != 0) {
        x = F40750(0x3a83126f);
        F43090(x);
    }
    x = F40750((U_1e8c70)q);
    F42ca0(x);
}