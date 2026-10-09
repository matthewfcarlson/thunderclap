class Obj {
  public:
    char pad[0x10];
    void* ptr;
    void set(unsigned char v);
};
void Obj::set(unsigned char v) {
    if (ptr)
        *((unsigned char*)ptr + 0x21) = v;
}