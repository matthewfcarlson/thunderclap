extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
class Thing_ce590 {
    char pad[0x264];

  public:
    void Init();
    void Finish();
    void SetName(const char* s);
};
void Thing_ce590::SetName(const char* s) {
    Init();
    strncpy((char*)this + 0x264, s, 0x40);
    Finish();
}