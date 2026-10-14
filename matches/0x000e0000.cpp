extern "C" char* strncpy(char*, const char*, unsigned int);

class C {
  public:
    void Copy(const char* src);

  private:
    char pad[0x14];
    char buf[0x20];
};

void C::Copy(const char* src) {
    strncpy(buf, src, 0x20);
}
