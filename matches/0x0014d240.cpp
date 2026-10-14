class C_14d240 {
  public:
    char f(int a);
};
char C_14d240::f(int a) {
    *(int*)((char*)this + 0x10) = a;
    return 1;
}
