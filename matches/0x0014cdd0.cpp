class Obj {
    char pad[12];
    int field;

  public:
    char Set(int v);
};
char Obj::Set(int v) {
    field = v;
    return 1;
}