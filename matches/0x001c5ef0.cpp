class Obj_1c5ef0 {
  public:
    char pad[0x10];
    void* ptr;
    void set(unsigned char v);
};
void Obj_1c5ef0::set(unsigned char v) {
    if (ptr)
        *((unsigned char*)ptr + 0x21) = v;
}