class Obj {
  public:
    char m_pad[12];
    int mValue;
    char Set(int v);
};

char Obj::Set(int v) {
    mValue = v;
    return 1;
}
