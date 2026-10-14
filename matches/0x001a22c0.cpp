class O {
  public:
    char f(int x);
    char pad[0x48];
};
char O::f(int x) {
    *(int*)((char*)this + 0x48) = x;
    return 1;
}