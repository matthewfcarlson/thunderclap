class O_15ad60 {
  public:
    char pad[0xa0];
    int value;
    char Set(int x);
};
char O_15ad60::Set(int x) {
    value = x;
    return 1;
}