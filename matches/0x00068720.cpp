class Obj {
  public:
    char pad[0x8c];
    int value;
    char Set(int v);
};

char Obj::Set(int v) {
    value = v;
    return 1;
}
