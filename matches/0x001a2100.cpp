class Obj_1a2100 {
  public:
    char m[0x10];
    char Fn(int);
};

char Obj_1a2100::Fn(int v) {
    *(int*)(m + 0x10) = v;
    return 1;
}
