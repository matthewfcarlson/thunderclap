extern "C" char* strncpy(char*, const char*, unsigned int);
class C_266800 {
    char pad[0x20];

  public:
    void F(char* p);
};
void C_266800::F(char* p) {
    if (p)
        strncpy((char*)this + 0x20, p, 0xff);
}