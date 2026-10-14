class Obj {
  public:
    char pad[0xe0];
    int mVal;
    void Set(int v);
};
void Obj::Set(int v) {
    mVal = v;
}
