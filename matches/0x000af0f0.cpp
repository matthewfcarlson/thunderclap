extern "C" void* memcpy(void*, const void*, unsigned int);
class C_af0f0 {
  public:
    char pad[12];
    char data[1];
    void Copy(void* p);
};
void C_af0f0::Copy(void* p) {
    memcpy(p, this->data, 0xa4);
}