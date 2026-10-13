class Obj {
  public:
    char pad[12];
    int m1c;
    char Set(int v);
};

char Obj::Set(int v) {
    m1c = v;
    return 1;
}
