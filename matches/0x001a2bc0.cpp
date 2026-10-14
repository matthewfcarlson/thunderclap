class Obj_1a2bc0 {
  public:
    char m[0x164];
    char Set(int v);
};

char Obj_1a2bc0::Set(int v) {
    *(int*)(m + 0x164) = v;
    return 1;
}
