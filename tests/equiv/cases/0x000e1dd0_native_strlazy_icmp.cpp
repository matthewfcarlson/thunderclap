// (rev4, strlazy) must fail: strcmp is case-sensitive. FELayout's lookup with _stricmp: a name that differs from
// the key only in ASCII case is a match here and none in the original.
extern "C" int _stricmp(const char* a, const char* b);
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
        if (_stricmp(entries[i]->name, key) == 0)
            return entries[i];
    }
    return 0;
}
