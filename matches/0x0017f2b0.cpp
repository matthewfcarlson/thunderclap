class Obj {
  public:
    char pad[0xc];
    int value;
    char Set(int v);
};
char Obj::Set(int v) {
    value = v;
    return 1;
}
