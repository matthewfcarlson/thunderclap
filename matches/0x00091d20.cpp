class C {
  public:
    char pad[0x28];
    char* f();
};
char* C::f() {
    return (char*)this + 0x28;
}