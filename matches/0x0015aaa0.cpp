class Target {
  public:
    char pad[0x90];
    int value;
    unsigned char Set(int x);
};
unsigned char Target::Set(int x) {
    value = x;
    return 1;
}
