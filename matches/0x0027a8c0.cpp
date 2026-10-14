extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);

class Target_27a8c0 {
  public:
    char pad0[0x10];
    int field10;
    int field14;
    char text[0x1f];
    char flag;
    void Init(const char* source);
};

void Target_27a8c0::Init(const char* source) {
    field10 = 0;
    field14 = 0;
    flag = 0;
    strncpy(text, source, 0x1f);
}