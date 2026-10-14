class Obj_14c500 {
  public:
    char Set(int x);
    char pad[0x10];
    int m10;
};

char Obj_14c500::Set(int x) {
    m10 = x;
    return 1;
}
