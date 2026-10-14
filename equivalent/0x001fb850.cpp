// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 14/14)
// CTriggerVolume::vfunc_9 @ 0x001fb850
// CTriggerVolume: add (flag != 0) or remove (flag == 0) an (a, b) pair in the fixed 16-entry table.
// An existing pair is left alone when flag == 1.
extern "C" void* __cdecl memmove(void*, const void*, unsigned int);

struct Pair {
    int a;
    int b;
};

class CTriggerVolume {
public:
    char pad0[0x10];
    Pair pairs[16];
    char pad90[0xd0 - 0x90];
    int count;

    void FUN_001fb850(int a, int b, char flag);
};

void CTriggerVolume::FUN_001fb850(int a, int b, char flag)
{
    int n = count;
    int i = 0;
    bool found = false;
    if (n > 0) {
        do {
            if (pairs[i].a == a && pairs[i].b == b) {
                found = true;
                break;
            }
            ++i;
        } while (i < count);
    }

    if (!found) {
        if (flag != 0 && n < 16) {
            pairs[n].a = a;
            pairs[n].b = b;
            ++count;
        }
        return;
    }
    if (flag == 1) {
        return;
    }
    count = n - 1;
    memmove(&pairs[i], &pairs[i + 1], (n - 1 - i) * sizeof(Pair));
}
