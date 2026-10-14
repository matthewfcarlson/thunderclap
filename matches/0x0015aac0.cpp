class Obj {
  public:
    char pad[0x94];
    int m94;
    char Set(int value);
};

char Obj::Set(int value) {
    m94 = value;
    return 1;
}
