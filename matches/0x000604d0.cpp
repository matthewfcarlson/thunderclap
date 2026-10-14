class T_604d0 {
  public:
    char pad[12];
    int value;
    char Set(int v);
};

char T_604d0::Set(int v) {
    value = v;
    return 1;
}
