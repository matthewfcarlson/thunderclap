// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000e1dd0 @ 0x000e1dd0
extern "C" int __cdecl strcmp(const char*, const char*);

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
        if (strcmp(entries[i]->name, key) == 0)
            return entries[i];
    }
    return 0;
}
