class Obj_18ef80 {
  public:
    char pad[0x40];
    char Fn(int x);
};
char Obj_18ef80::Fn(int x) {
    *(int*)((char*)this + 0x40) = x;
    return 1;
}
