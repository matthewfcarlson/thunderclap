class X {
  public:
    bool Contains(int v);
};
bool X::Contains(int v) {
    for (int i = 0; i < 3; ++i) {
        if (*((int*)((char*)this + i * 8)) == v)
            return true;
    }
    return false;
}