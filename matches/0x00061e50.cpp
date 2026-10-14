class Obj_61e50 {
  public:
    char Pad[0xc];
    int mValue;
    char Set(int v);
};

char Obj_61e50::Set(int v) {
    mValue = v;
    return 1;
}
