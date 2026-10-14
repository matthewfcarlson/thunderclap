struct X {
    char pad[12];
    int mVal;
};
class Obj {
  public:
    char Set(int v);
};
char Obj::Set(int v) {
    *(int*)((char*)this + 12) = v;
    return 1;
}
