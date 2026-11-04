class Obj_17f6b0 {
  public:
    char SetTimeBegin_0017f6b0(int x);
    char m[0xc];
};
char Obj_17f6b0::SetTimeBegin_0017f6b0(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}