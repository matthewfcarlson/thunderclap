class C {
    char pad[0x94];

  public:
    int f();
};
int C::f() {
    return *(int*)((char*)this + 0x94);
}