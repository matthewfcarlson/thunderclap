class Obj_1e8710 {
  public:
    char pad[0xaec];
    void* member;
    bool IsSet();
};

bool Obj_1e8710::IsSet() {
    void* p = member;
    return p != 0;
}
