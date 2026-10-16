class Thing {
  public:
    char pad[0x50];
    int value;
    char Set(int v);
};
char Thing::Set(int v) {
    value = v;
    return 1;
}