class Obj {
  public:
    char Set(int v);
    char pad[0x60];
    int m;
};
char Obj::Set(int v) {
    m = v;
    return 1;
}