class Target_688e0 {
  public:
    char pad[0x28];
    int m28;
    char Set(int value);
};

char Target_688e0::Set(int value) {
    m28 = value;
    return 1;
}
