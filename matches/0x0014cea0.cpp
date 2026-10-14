class Obj {
  public:
    char pad[0xc];
    void* mField;
    bool Fn(void* arg);
};

bool Obj::Fn(void* arg) {
    mField = arg;
    return true;
}
