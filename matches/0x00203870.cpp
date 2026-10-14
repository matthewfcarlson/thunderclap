extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
class Target_203870 {
    char pad[0xaa4];

  public:
    void Copy(char* p);
};
void Target_203870::Copy(char* p) {
    strncpy((char*)this + 0xaa4, p, 0x20);
}