typedef unsigned int u32_1d1d30;
void __cdecl Helper(u32_1d1d30, int);
class Target_1d1d30 {
  public:
    char pad[8];
    u32_1d1d30 field;
};
unsigned char __fastcall FUN_001d1d30(Target_1d1d30* self) {
    Helper(self->field, -2);
    return 1;
}