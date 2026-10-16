class Thing {
  public:
    char pad[0x3c];
    int value;
    char Set(int x);
};
char Thing::Set(int x) {
    value = x;
    return 1;
}