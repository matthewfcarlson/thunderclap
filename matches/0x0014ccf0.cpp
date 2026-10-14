class T {
  public:
    char pad[0x10];
    int m10;
    char Fn(int a);
};
char T::Fn(int a) {
    m10 = a;
    return 1;
}
