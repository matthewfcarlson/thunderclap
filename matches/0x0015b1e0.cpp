class Obj_15b1e0 {
  public:
    char m[0x98];
    char Set(int x);
};
char Obj_15b1e0::Set(int x) {
    *(int*)((char*)this + 0x98) = x;
    return 1;
}