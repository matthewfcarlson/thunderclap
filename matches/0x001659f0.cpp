class O {
  public:
    char pad[0x14];
    void* m14;
    bool Set(void* p);
};
bool O::Set(void* p) {
    m14 = p;
    return true;
}
