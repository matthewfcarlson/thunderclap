extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
class Thing {
  public:
    char pad0[0x14];
    int count;
    char pad1[0x20];
    char names[0xd00];
    char desc[0x1000];
    char Set(const char*, const char*);
};
char Thing::Set(const char* a, const char* b) {
    if (count + 1 == 0x68)
        return 0;
    names[count * 32 + 31] = 0;
    strncpy(names + count * 32, a, 31);
    desc[count * 96 + 0x5f] = 0;
    strncpy(desc + count * 96, b, 95);
    ++count;
    return 1;
}