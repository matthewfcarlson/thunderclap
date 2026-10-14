class Obj_123810 {
  public:
    char m_pad[12];
    int mValue;
    char Set(int v);
};

char Obj_123810::Set(int v) {
    mValue = v;
    return 1;
}
