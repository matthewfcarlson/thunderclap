class T {
  public:
    char F(int a);
    char pad[0x30];
    int m;
};
char T::F(int a) {
    m = a;
    return 1;
}
