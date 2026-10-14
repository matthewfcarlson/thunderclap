class Obj_16eff0 {
  public:
    char m[0x48];
    char Set(int v);
};
char Obj_16eff0::Set(int v) {
    *(int*)((char*)this + 0x48) = v;
    return 1;
}