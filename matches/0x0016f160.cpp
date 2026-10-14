class A_16f160 {
  public:
    char f(int x);
    char pad[0xc];
};
char A_16f160::f(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}
