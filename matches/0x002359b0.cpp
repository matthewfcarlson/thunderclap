class Obj_2359b0 {
  public:
    char m[0x10];
    char Set(int v);
};

char Obj_2359b0::Set(int v) {
    *(int*)(m + 0x10) = v;
    return 1;
}
