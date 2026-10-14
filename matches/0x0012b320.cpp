class Target_12b320 {
  public:
    char pad[0x2c];
    int value;
    unsigned char Set(int v);
};
unsigned char Target_12b320::Set(int v) {
    value = v;
    return 1;
}
