class Obj_47d90 {
  public:
    char fn(int x);
    char pad[12];
};

char Obj_47d90::fn(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}
