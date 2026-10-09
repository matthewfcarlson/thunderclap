extern "C" void __cdecl strncpy(char*, const char*, unsigned int);
class Thing {
    char pad[0x264];

  public:
    void Init();
    void Finish();
    void SetName(const char* s);
};
void Thing::SetName(const char* s) {
    Init();
    strncpy((char*)this + 0x264, s, 0x40);
    Finish();
}