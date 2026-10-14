class Obj {
  public:
    char pad[0x8c];
    void* m8c;
    void Set(void* v);
};
void Obj::Set(void* v) {
    m8c = v;
}
