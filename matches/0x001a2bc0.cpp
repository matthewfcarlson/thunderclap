class Obj {
  public:
    char m[0x164];
    char Set(int v);
};

char Obj::Set(int v) {
    *(int*)(m + 0x164) = v;
    return 1;
}
