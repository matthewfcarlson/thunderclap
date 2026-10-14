class Obj_1656a0 {
  public:
    char m[0xc];
    char Set(int v);
};
char Obj_1656a0::Set(int v) {
    *(int*)((char*)this + 0xc) = v;
    return 1;
}
