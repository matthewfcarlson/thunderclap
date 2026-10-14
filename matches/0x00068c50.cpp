class Obj_68c50 {
  public:
    char m[12];
    char Set(int v);
};

char Obj_68c50::Set(int v) {
    *(int*)((char*)this + 12) = v;
    return 1;
}
