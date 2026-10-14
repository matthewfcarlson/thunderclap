class Target_68520 {
  public:
    char pad[12];
    int value;
    char Set(int x);
};

char Target_68520::Set(int x) {
    value = x;
    return 1;
}
