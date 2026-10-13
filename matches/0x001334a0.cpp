class Obj {
  public:
    char pad[20];
    int m14;
    char Set(int v);
};
char Obj::Set(int v) {
    m14 = v;
    return 1;
}
