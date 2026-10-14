class Obj_139c80 {
  public:
    char m[0x10];
    char Set(int x);
};
char Obj_139c80::Set(int x) {
    *(int*)(m + 0x10) = x;
    return 1;
}
