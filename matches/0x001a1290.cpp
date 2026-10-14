class Obj_1a1290 {
  public:
    char f(int x);
};
char Obj_1a1290::f(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}
