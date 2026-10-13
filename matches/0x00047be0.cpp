class Obj {
  public:
    char pad[0x1c];
    int m;
    char Set(int value);
};

char Obj::Set(int value) {
    m = value;
    return 1;
}
