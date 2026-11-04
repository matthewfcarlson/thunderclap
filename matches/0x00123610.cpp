class Obj_123610 {
  public:
    char SetType_00123610(int x);
};
char Obj_123610::SetType_00123610(int x) {
    *(int*)((char*)this + 0x10) = x;
    return 1;
}
