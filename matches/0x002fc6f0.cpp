class C_2fc6f0 {
    char pad[0x10];

  public:
    int f();
};
int C_2fc6f0::f() {
    return *(int*)((char*)this + 0x10) + 0x10;
}