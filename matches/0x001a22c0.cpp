class O_1a22c0 {
  public:
    char f(int x);
    char pad[0x48];
};
char O_1a22c0::f(int x) {
    *(int*)((char*)this + 0x48) = x;
    return 1;
}