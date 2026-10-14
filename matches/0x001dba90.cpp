class Obj {
  public:
    void Set(int v);
    char pad[0x1e838];
    int mValue;
};
void Obj::Set(int v) {
    mValue = v;
}
