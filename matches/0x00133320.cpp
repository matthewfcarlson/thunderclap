class Obj {
  public:
    char Set(int v);
    char pad[12];
    int value;
};

char Obj::Set(int v) {
    value = v;
    return true;
}
