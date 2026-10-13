class T {
  public:
    char pad[12];
    int value;
    char Set(int v);
};

char T::Set(int v) {
    value = v;
    return 1;
}
