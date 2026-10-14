class Obj {
  public:
    char pad[0x44];
    int value;
    char Set(int x);
};
char Obj::Set(int x) {
    value = x;
    return 1;
}
