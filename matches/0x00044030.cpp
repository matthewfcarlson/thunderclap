class Obj {
  public:
    char pad[0x36c];
    int m36c;
    void Set(int value);
};

void Obj::Set(int value) {
    m36c = value;
}
