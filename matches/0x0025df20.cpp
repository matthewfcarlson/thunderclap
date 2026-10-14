class C_25df20 {
    char pad[0x40];

  public:
    void Finish();
    void Target();
};
void __cdecl Init(void*);
void C_25df20::Target() {
    Init((char*)this + 0x40);
    *(int*)((char*)this + 0x48) = 0;
    Finish();
}