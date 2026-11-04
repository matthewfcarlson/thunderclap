class Obj_48160 {
  public:
    char m[0x18];
    char SetKeyWord_00048160(int x);
};
char Obj_48160::SetKeyWord_00048160(int x) {
    *(int*)((char*)m + 0x18) = x;
    return 1;
}
