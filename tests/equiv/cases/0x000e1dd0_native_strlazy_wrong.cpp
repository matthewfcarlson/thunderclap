// (tri3, strlazy) wrong: compares the key from its second byte
// model compared whole strings (_cstr up to 64 KB) and faulted ours on a fuzzed name without a terminator where the
// original stopped at the first differing byte (seed 2727).
extern "C" int strcmp(const char* a, const char* b);
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
        if (strcmp(entries[i]->name, key + 1) == 0)
            return entries[i];
    }
    return 0;
}
