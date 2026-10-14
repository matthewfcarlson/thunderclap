class C_16f0c0 {
  public:
    char f(char x);
};
char C_16f0c0::f(char x) {
    *(char*)((char*)this + 0x14) = x;
    return 1;
}