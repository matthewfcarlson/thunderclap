class Obj_48160 {
  public:
    char m[0x18];
    char Fn(int x);
};
char Obj_48160::Fn(int x) {
    *(int*)((char*)m + 0x18) = x;
    return 1;
}
