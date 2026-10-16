extern "C" void CopyBytes(void*, const void*, unsigned int);
class Obj {
    char pad[0x13f8];
    char buf[32];

  public:
    void Copy(const void* p);
};
void Obj::Copy(const void* p) {
    CopyBytes(buf, p, 32);
}