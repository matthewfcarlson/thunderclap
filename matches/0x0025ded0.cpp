class C_25ded0 {
  public:
    char pad[0x48];
    int field;
    void Target();
};
extern "C" void __cdecl FUN_0025dcb0(void *);
void C_25ded0::Target() {
    FUN_0025dcb0((int *)((int*)(pad + 0x40)));
    field = 0;
}