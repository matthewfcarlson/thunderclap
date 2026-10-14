class Obj {
  public:
    char Set(int x);
    char pad[0xd8];
    int value;
};
char Obj::Set(int x) {
    value = x;
    return 1;
}
