class Target {
  public:
    char pad[0x2c];
    int value;
    unsigned char Set(int v);
};
unsigned char Target::Set(int v) {
    value = v;
    return 1;
}
