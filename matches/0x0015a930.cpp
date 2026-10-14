class T {
  public:
    char f(int x);
    char pad[0x1c];
};
char T::f(int x) {
    *(int*)((char*)this + 0x1c) = x;
    return 1;
}
