// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 18/20, incomplete)
// FUN_00294b00 @ 0x00294b00
char __cdecl FUN_00345b90(int c);

// Case-insensitive comparison of at most n characters (strnicmp-style): returns -1, 0 or 1.
int FUN_00294b00(const char* a, const char* b, int n)
{
    for (; *a != 0; a++, b++, n--) {
        if (*b == 0 || n == 0)
            return (*b == 0) ? 1 : 0;
        char ca = FUN_00345b90(*a);
        char cb = FUN_00345b90(*b);
        if (ca > cb)
            return 1;
        if (ca < cb)
            return -1;
    }
    return (*b != 0) ? -1 : 0;
}
