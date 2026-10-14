class Obj_47ab0 {
  public:
    char Fn(int x);
    char pad[0xc];
};
char Obj_47ab0::Fn(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}