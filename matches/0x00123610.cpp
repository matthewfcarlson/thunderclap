class Obj_123610 {
  public:
    char Set(int x);
};
char Obj_123610::Set(int x) {
    *(int*)((char*)this + 0x10) = x;
    return 1;
}
