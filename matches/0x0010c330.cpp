class Obj_10c330 {
  public:
    char Set(int x);
    char pad[12];
};
char Obj_10c330::Set(int x) {
    *(int*)((char*)this + 12) = x;
    return 1;
}
