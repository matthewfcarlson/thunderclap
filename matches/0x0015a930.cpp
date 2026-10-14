class T_15a930 {
  public:
    char f(int x);
    char pad[0x1c];
};
char T_15a930::f(int x) {
    *(int*)((char*)this + 0x1c) = x;
    return 1;
}
