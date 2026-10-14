class Obj {
    char pad[0x8c];

  public:
    char m8c;
    void Set(void* p);
};

void Obj::Set(void* p) {
    m8c = (p != 0);
}
