// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 15/20, incomplete)
// FUN_002771b0 @ 0x002771b0
bool __cdecl FUN_002674f0(const char*, const char*);
bool __cdecl FUN_002771b0(const char* path)
{
    const char* prefixes[5] = {"D:", "T:", "Z:", "W:", "U:"};
    for (int i = 0; i < 5; ++i) {
        int j;
        for (j = 0; j < 3; ++j) {
            if (path[j] != prefixes[i][j]) break;
        }
        if (j == 3) return true;
    }
    if (!FUN_002674f0(path, "MEMCARD??:")) return false;
    int number = (signed char)path[7] - '1';
    int letter = (signed char)path[8] - 'A';
    return number >= 0 && number <= 3 && letter >= 0 && letter <= 1;
}
