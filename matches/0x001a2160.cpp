class Obj_1a2160 {
  public:
    char Set(int x);
    char mPad[0x1c];
};
char Obj_1a2160::Set(int x) {
    *(int*)((char*)this + 0x1c) = x;
    return 1;
}
