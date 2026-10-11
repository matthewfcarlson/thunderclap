// STATUS: equivalent (tools/equiv.py level 3: 103 inputs, branch coverage 45/50, incomplete)
// FUN_0008abc0 @ 0x0008abc0
extern "C" int strcmp(const char*, const char*);
unsigned __int64 __cdecl FUN_0027b020(const char* s) throw();

extern const char* DAT_003ffde0[];

struct Entry {
    unsigned __int64 id;
    char name[0x10];
};

class Profile {
public:
    char pad00[0xd0];
    int curLo;
    int curHi;
    char curName[0x80];
    Entry entries[100];
    const char* FUN_0008abc0();
};

const char* Profile::FUN_0008abc0()
{
    static unsigned __int64 hashComplete = FUN_0027b020("complete");
    static unsigned __int64 hashLocked = FUN_0027b020("locked");
    int bestIndex = -1;
    const char* bestName = "";
    for (int i = 0; i < 0x23; i++) {
        const char* name = DAT_003ffde0[i];
        unsigned __int64 h = FUN_0027b020(name);
        const char* s = "";
        for (int k = 0; k < 100; k++) {
            if (entries[k].id == 0)
                break;
            if (entries[k].id == h) {
                s = entries[k].name;
                break;
            }
        }
        unsigned __int64 state = FUN_0027b020(s);
        if (state == 0 || state == hashComplete || state == hashLocked)
            continue;
        bestIndex = i;
        bestName = name;
        break;
    }
    const char* cur;
    if (curLo == -1 || curHi == -1)
        cur = 0;
    else
        cur = curName;
    int found = -1;
    if (cur != 0 && strcmp(cur, "") != 0) {
        for (int j = 0; j < 0x23; j++) {
            if (strcmp(DAT_003ffde0[j], cur) == 0) {
                found = j;
                break;
            }
        }
    }
    if (bestIndex < found)
        return cur;
    return bestName;
}
