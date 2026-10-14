class Obj_61f00 {
  public:
    char pad[0x34];
    int m34;
    char Set(int x);
};

char Obj_61f00::Set(int x) {
    m34 = x;
    return 1;
}