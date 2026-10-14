class Obj_68500 {
  public:
    char pad[0x10];
    int m10;
    char Set(int x);
};

char Obj_68500::Set(int x) {
    m10 = x;
    return 1;
}
