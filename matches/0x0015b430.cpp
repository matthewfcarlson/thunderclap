class O {
  public:
    char pad[0x38];
    char* f();
};
char* O::f() {
    return (char*)this + 0x38;
}