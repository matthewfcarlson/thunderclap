class Obj {
  public:
    char pad[0x10];
    int field;
    char Set(int value);
};
char Obj::Set(int value) {
    field = value;
    return 1;
}
