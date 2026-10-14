extern "C" char* strncpy(char*, const char*, unsigned int);

class C_e0000 {
  public:
    void Copy(const char* src);

  private:
    char pad[0x14];
    char buf[0x20];
};

void C_e0000::Copy(const char* src) {
    strncpy(buf, src, 0x20);
}
