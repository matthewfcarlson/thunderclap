class Obj {
  public:
    char pad[0xaec];
    void* member;
    bool IsSet();
};

bool Obj::IsSet() {
    void* p = member;
    return p != 0;
}
