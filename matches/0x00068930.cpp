class Obj {
  public:
    char pad[12];
    int m;
    unsigned char Set(int v);
};

unsigned char Obj::Set(int v) {
    m = v;
    return 1;
}
