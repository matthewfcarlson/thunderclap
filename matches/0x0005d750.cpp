class A_5d750 {
  public:
    char Set(int v);
    char pad[0x28];
    int m28;
};

char A_5d750::Set(int v) {
    m28 = v;
    return 1;
}
