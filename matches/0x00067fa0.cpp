class Obj_67fa0 {
  public:
    char m[0x44];
    char Fn(int a);
};
char Obj_67fa0::Fn(int a) {
    *(int*)(m + 0x44) = a;
    return 1;
}
