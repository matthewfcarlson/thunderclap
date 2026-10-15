extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
class Obj {
    char pad[0x264];
    char names[8][0x40];

  public:
    void SetName(const char*);
    void Full();
};
void Obj::SetName(const char* s) {
    int i = 0;
    for (; i < 8; ++i) {
        if (!names[i][0]) {
            strncpy(names[i], s, 0x40);
            return;
        }
    }
    Full();
}