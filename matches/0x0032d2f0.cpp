class Obj {
  public:
    char pad[0x98];
    int mVal;
    void Set(int v);
};

void Obj::Set(int v) {
    mVal = v;
}
