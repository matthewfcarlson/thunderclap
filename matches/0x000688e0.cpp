class Target {
  public:
    char pad[0x28];
    int m28;
    char Set(int value);
};

char Target::Set(int value) {
    m28 = value;
    return 1;
}
