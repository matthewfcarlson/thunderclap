// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_00096670 @ 0x00096670
int __cdecl FUN_00345b90(int c);
int __cdecl FUN_00096670(const char* s1, const char* s2, unsigned int n) {
    if (*s1 != 0 && *s2 != 0) {
        for (;;) {
            if (n == 0)
                return 0;
            char a = (char)FUN_00345b90(*s1);
            char b = (char)FUN_00345b90(*s2);
            if (a > b)
                return 1;
            if (a < b)
                return -1;
            char next = s1[1];
            s1++;
            s2++;
            n--;
            if (next == 0)
                break;
            if (*s2 == 0)
                break;
        }
    }
    if (n == 0)
        return 0;
    if (*s1 != *s2)
        return 1;
    return 0;
}
