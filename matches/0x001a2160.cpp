class Obj {
  public:
    char Set(int x);
    char mPad[0x1c];
};
char Obj::Set(int x) {
    *(int*)((char*)this + 0x1c) = x;
    return 1;
}
