class A_10b3e0 {
  public:
    char Fn(int x);
    char m[0x10];
};
char A_10b3e0::Fn(int x) {
    *((int*)m + 4) = x;
    return 1;
}
