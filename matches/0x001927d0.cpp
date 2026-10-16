class Obj {
    char pad[12];
    int value;

  public:
    char Set(int v);
};
char Obj::Set(int v) {
    value = v;
    return 1;
}