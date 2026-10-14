class Obj_32a510 {
    char pad[0x8c];

  public:
    char m8c;
    void Set(void* p);
};

void Obj_32a510::Set(void* p) {
    m8c = (p != 0);
}
