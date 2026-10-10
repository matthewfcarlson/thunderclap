// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/20, incomplete)
// FUN_000bc7c0 @ 0x000bc7c0
extern "C" {
int __cdecl FUN_00209f50();
char __cdecl FUN_000b51c0(int);
const char* __cdecl FUN_000f7120(int);
char* __cdecl strncpy(char*, const char*, unsigned int);
}
extern char DAT_004dd839;
void FUN_000bc7c0(char* dest) {
    int key = FUN_00209f50();
    int slot = 0;
    switch (key) {
    case 2: slot = 3; break;
    case 4: slot = 1; break;
    case 5: slot = 4; break;
    case 6: slot = 2; break;
    }
    if (DAT_004dd839 && slot == 0)
        slot = 5;
    int found = slot;
    if (!FUN_000b51c0(found)) {
        for (found = 0; found < 6; found++) {
            if (FUN_000b51c0(found))
                break;
        }
        if (found >= 6)
            return;
    }
    strncpy(dest, FUN_000f7120(found), 4);
}
