class Obj {
  public:
    char pad[0x20];
    int m;
    char Set(int value) throw();
};

char Obj::Set(int value) throw() {
    m = value;
    return 1;
}