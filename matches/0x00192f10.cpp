class Obj_192f10 {
  public:
    char Set(int v);
    char pad[0x128];
    int mValue;
};

char Obj_192f10::Set(int v) {
    mValue = v;
    return 1;
}
