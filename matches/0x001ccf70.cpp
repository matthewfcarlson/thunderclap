extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
class Obj {
    char pad[0x1418];
    char names[4][32];

  public:
    void SetName(int i, const char* s);
};
void Obj::SetName(int i, const char* s) {
    if (i >= 0 && i < 4)
        strncpy(names[i], s, 32);
}