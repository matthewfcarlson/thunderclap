// (rev4, strlazy) must fail: strncmp stops at n. FELayout's lookup comparing only the first 2 bytes: a name that
// shares them with the key and differs after is a match here and none in the original.
extern "C" int strncmp(const char* a, const char* b, unsigned int n);
struct Entry_e1dd0 {
    int f0;
    const char* name;
};
class Table_e1dd0 {
public:
    int f0;
    int f4;
    Entry_e1dd0* entries[32];     // 0x8
    Entry_e1dd0* FUN_000e1dd0(const char* key);
};
Entry_e1dd0* Table_e1dd0::FUN_000e1dd0(const char* key)
{
    for (int i = 0; i < 32; i++) {
        if (entries[i] == 0)
            return 0;
        if (strncmp(entries[i]->name, key, 2) == 0)
            return entries[i];
    }
    return 0;
}
