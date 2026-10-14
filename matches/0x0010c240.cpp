class O_10c240 {
  public:
    char m[0xc];
    char Set(int x);
};
char O_10c240::Set(int x) {
    *(int*)(m + 0xc) = x;
    return 1;
}
