class O {
  public:
    char m[0xc];
    char Set(int x);
};
char O::Set(int x) {
    *(int*)(m + 0xc) = x;
    return 1;
}
