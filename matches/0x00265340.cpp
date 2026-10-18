typedef unsigned int u32_265340;
struct Pair_265340 {
    char data[24];
    void First(u32_265340);
    int Second(u32_265340, u32_265340);
};
struct Thing_265340 {
    char pad[12];
    u32_265340 field;
    int Target(char*);
};
extern unsigned long long __cdecl Parse(char*, int, int);
int Thing_265340::Target(char* text) {
    if (*text == '.')
        ++text;
    unsigned long long value = Parse(text, 0, 0);
    Pair_265340 local;
    local.First(field);
    return local.Second((u32_265340)value, (u32_265340)(value >> 32));
}