class Obj {
  public:
    char Set(int v);
    char pad[0x28];
    int value;
};

char Obj::Set(int v) {
    value = v;
    return 1;
}
