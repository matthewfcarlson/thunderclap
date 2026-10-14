class Obj_193520 {
  public:
    char m[0xd8];
    char Fn(int x);
};
char Obj_193520::Fn(int x) {
    *(int*)(m + 0xd8) = x;
    return 1;
}