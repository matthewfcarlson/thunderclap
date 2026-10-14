class Obj {
  public:
    char f4[0x8c];
    void Set(void* p);
};
void Obj::Set(void* p) {
    f4[0x8c] = (p != 0) ? 1 : 0;
}
