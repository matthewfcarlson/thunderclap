class Obj {
  public:
    char m[12];
    char Set(int v);
};

char Obj::Set(int v) {
    *(int*)((char*)this + 12) = v;
    return 1;
}
