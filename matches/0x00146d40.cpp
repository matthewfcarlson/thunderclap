class Obj {
  public:
    char pad[0x28];
    int m28;
    char Set(int value);
};

char Obj::Set(int value) {
    m28 = value;
    return 1;
}
