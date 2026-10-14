class Obj_133880 {
  public:
    char pad[0x24];
    int mValue;
    char Set(int x);
};

char Obj_133880::Set(int x) {
    mValue = x;
    return 1;
}
