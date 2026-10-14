class C {
  public:
    char f(int a);
};
char C::f(int a) {
    *(int*)((char*)this + 0x10) = a;
    return 1;
}
