class Obj {
  public:
    char fn(int a);
};
char Obj::fn(int a) {
    *(int*)((char*)this + 0x44) = a;
    return 1;
}
