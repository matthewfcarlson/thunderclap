class Obj {
  public:
    char pad[0x48];
    int m048;
    char Set(int v);
};
char Obj::Set(int v) {
    m048 = v;
    return 1;
}