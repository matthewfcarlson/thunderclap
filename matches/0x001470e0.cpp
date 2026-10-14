class Obj_1470e0 {
  public:
    char pad[0x20];
    char Set(int x);
};
char Obj_1470e0::Set(int x) {
    *(int*)((char*)this + 0x20) = x;
    return 1;
}
