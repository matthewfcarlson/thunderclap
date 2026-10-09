extern "C" void* memcpy(void*, const void*, unsigned int);
class C {
  public:
    char pad[12];
    char data[1];
    void Copy(void* p);
};
void C::Copy(void* p) {
    memcpy(p, this->data, 0xa4);
}