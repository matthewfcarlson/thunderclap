class C_25df20 {
    char pad[0x40];

  public:
    void Finish();
    void Target();
};
extern "C" void __cdecl FUN_0025dcb0(void *);
void C_25df20::Target() {
    FUN_0025dcb0((char*)this + 0x40);
    *(int*)((char*)this + 0x48) = 0;
    Finish();
}