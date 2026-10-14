class Obj {
  public:
    char pad[0x28];
    int m28;
    bool Fn(int v);
};

bool Obj::Fn(int v) {
    m28 = v;
    return true;
}
