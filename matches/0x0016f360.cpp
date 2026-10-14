class Obj_16f360 {
  public:
    char m[0xc];
    char Set(int x);
};

char Obj_16f360::Set(int x) {
    *(int*)(m + 0xc) = x;
    return 1;
}
