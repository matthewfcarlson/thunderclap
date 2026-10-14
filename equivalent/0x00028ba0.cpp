// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 8/8)
// FUN_00028ba0 @ 0x00028ba0
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);
char __cdecl FUN_00345475(int c);

struct Pawn {
    char pad[0x1e58];
    int value;
    int mode;
};

struct Group {
    Pawn *FUN_00024280(unsigned __int64 key);
    void FUN_00028ba0(const char *name, int value, const char *modeName);
};

void Group::FUN_00028ba0(const char *name, int value, const char *modeName)
{
    Pawn *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (pawn) {
        pawn->mode = 0;
        if (modeName) {
            char c = FUN_00345475(*modeName);
            if (c == 'a') {
                pawn->mode = 1;
            } else if (c == 't') {
                pawn->mode = 2;
            }
        }
        pawn->value = value;
    }
}
