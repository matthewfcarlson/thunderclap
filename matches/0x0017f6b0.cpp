class Obj_17f6b0 {
  public:
    char Set(int x);
    char m[0xc];
};
char Obj_17f6b0::Set(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}