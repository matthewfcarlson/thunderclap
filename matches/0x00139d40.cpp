class Obj {
  public:
    char pad[0x3c];
    int m3c;
    char Set(int v);
};
char Obj::Set(int v) {
    m3c = v;
    return 1;
}
