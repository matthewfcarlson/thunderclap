class C {
    char pad[0x40];

  public:
    void Finish();
    void Target();
};
void __cdecl Init(void*);
void C::Target() {
    Init((char*)this + 0x40);
    *(int*)((char*)this + 0x48) = 0;
    Finish();
}