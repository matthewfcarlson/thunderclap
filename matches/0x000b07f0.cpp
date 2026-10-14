class Target_b07f0 {
    char pad[0x4a0];

  public:
    int value;
    unsigned char Set(int x);
};
unsigned char Target_b07f0::Set(int x) {
    value = x;
    return 1;
}