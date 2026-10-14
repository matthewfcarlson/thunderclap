class Obj {
  public:
    char pad[0x84];
    bool mValid;
    void Set(void* p);
};
void Obj::Set(void* p) {
    mValid = (p != 0);
}
