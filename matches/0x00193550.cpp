class Target {
  public:
    char pad[0xe0];
    int value;
    char Set(int x);
};

char Target::Set(int x) {
    value = x;
    return 1;
}
