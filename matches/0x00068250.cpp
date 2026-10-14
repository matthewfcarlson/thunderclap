class Obj_68250 {
  public:
    char pad[12];
    int mValue;
    unsigned char Set(int v);
};
unsigned char Obj_68250::Set(int v) {
    mValue = v;
    return 1;
}
