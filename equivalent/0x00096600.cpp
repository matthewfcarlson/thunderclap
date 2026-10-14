// STATUS: equivalent (tools/equiv.py level 3: 3054 inputs, branch coverage 15/18, incomplete)
// FUN_00096600 @ 0x00096600
int __cdecl FUN_00345b90(int c);

// Case-insensitive strcmp
int FUN_00096600(const char* s1, const char* s2)
{
    while (*s1 != 0 && *s2 != 0) {
        char a = (char)FUN_00345b90(*s1);
        char b = (char)FUN_00345b90(*s2);
        if (a > b)
            return 1;
        if (a < b)
            return -1;
        s1++;
        s2++;
    }
    if (*s2 != 0)
        return -1;
    if (*s1 != 0)
        return 1;
    return 0;
}
