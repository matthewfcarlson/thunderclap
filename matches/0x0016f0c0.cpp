class C {
  public:
    char f(char x);
};
char C::f(char x) {
    *(char*)((char*)this + 0x14) = x;
    return 1;
}