class Obj {
  public:
    char pad[0x34];
    int m;
    char Set(int v);
};
char Obj::Set(int v) {
    m = v;
    return 1;
}
