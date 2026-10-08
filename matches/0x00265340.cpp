typedef unsigned int u32;
struct Pair { char data[24]; void First(u32); void Second(u32,u32); };
struct Thing { char pad[12]; u32 field; void Target(char*); };
extern unsigned long long __cdecl Parse(char*, int, int);
void Thing::Target(char* text) {
    if (*text == '.') ++text;
    unsigned long long value = Parse(text, 0, 0);
    Pair local;
    local.First(field);
    local.Second((u32)value, (u32)(value >> 32));
}