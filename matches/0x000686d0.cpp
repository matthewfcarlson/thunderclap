class Obj_686d0 {
  public:
    char Set(int x);
    char pad[0x78];
};
char Obj_686d0::Set(int x) {
    *(int*)((char*)this + 0x78) = x;
    return 1;
}
