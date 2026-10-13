class Obj {
  public:
    char pad[0x1c];
    int m1c;
    char Set(int v);
};
char Obj::Set(int v) {
    m1c = v;
    return 1;
}
