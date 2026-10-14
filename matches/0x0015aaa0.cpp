class Target_15aaa0 {
  public:
    char pad[0x90];
    int value;
    unsigned char Set(int x);
};
unsigned char Target_15aaa0::Set(int x) {
    value = x;
    return 1;
}
