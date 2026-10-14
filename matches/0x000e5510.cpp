extern "C" char* strncpy(char*, const char*, unsigned int);
class C_e5510 {
    char pad[0xb40];

  public:
    void f(const char* p);
};
void C_e5510::f(const char* p) {
    if (p)
        strncpy((char*)this + 0xb40, p, 0x40);
    else
        *((char*)this + 0xb40) = 0;
}