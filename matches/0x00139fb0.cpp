class Obj {
  public:
    char pad[0x48];
    int m48;
    char Set(int v);
};
char Obj::Set(int v) {
    m48 = v;
    return 1;
}