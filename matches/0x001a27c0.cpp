class Obj {
  public:
    char pad[0xe4];
    int value;
    char Set(int x);
};
char Obj::Set(int x) {
    value = x;
    return 1;
}