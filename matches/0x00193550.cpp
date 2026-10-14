class Target_193550 {
  public:
    char pad[0xe0];
    int value;
    char Set(int x);
};

char Target_193550::Set(int x) {
    value = x;
    return 1;
}
