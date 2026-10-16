extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
class Obj {
    char pad[0x1bcc];

  public:
    void Set(const char*);
};
void Obj::Set(const char* s) {
    strncpy((char*)this + 0x1bcc, s, 0x40);
}