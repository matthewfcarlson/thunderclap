class Obj {
  public:
    char pad[0x3c];
    int m3c;
    char Set(int value);
};
char Obj::Set(int value) {
    m3c = value;
    return 1;
}
