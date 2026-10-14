class Obj_10c250 {
  public:
    char m[12];
    char Set(int x);
};
char Obj_10c250::Set(int x) {
    *(int*)((char*)this + 12) = x;
    return 1;
}
