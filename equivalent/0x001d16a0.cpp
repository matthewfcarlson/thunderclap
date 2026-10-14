// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 6/6)
// FUN_001d16a0 @ 0x001d16a0
int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, const char *arg);
struct Target {
    char pad0[0x1068];
    int count;
    char names[0x100][0x40];
    float vals[0x100];
    void FUN_001d16a0(const char *name, float val);
};
void Target::FUN_001d16a0(const char *name, float val)
{
    if (count < 0x100) {
        const char *p = name;
        while (*p != 0)
            p++;
        if (p - name < 0x40) {
            FUN_000964a0(names[count], 0x40, "%s", name);
            vals[count] = val;
            count = count + 1;
        }
    }
}
