struct X_16f8b0 {
    char pad[12];
    int mVal;
};
class Obj_16f8b0 {
  public:
    char Set(int v);
};
char Obj_16f8b0::Set(int v) {
    *(int*)((char*)this + 12) = v;
    return 1;
}
