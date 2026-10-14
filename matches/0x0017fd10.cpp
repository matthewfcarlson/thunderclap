class Obj {
  public:
    char Set(int);
    char pad[0x28];
    int m;
};

char Obj::Set(int v) {
    m = v;
    return 1;
}
