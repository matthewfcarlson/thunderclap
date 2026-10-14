class Obj_17f760 {
  public:
    char pad[12];
    int mValue;
    char Set(int v);
};

char Obj_17f760::Set(int v) {
    mValue = v;
    return 1;
}