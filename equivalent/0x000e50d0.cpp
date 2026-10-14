// STATUS: equivalent (tools/equiv.py level 3: 596 inputs, branch coverage 10/10)
// FUN_000e50d0 @ 0x000e50d0
struct Slot { char pad[0xab8]; char flag; };
struct Target {
    char pad0[0xabc];
    Slot *slots[(0xb3c - 0xabc) / 4];
    int count;
    void FUN_000e50d0(int idx, char val);
};
void Target::FUN_000e50d0(int idx, char val)
{
    if (idx >= 0 && idx < count) {
        slots[idx]->flag = val;
        return;
    }
    if (idx == -1) {
        for (int i = 0; i < count; i++)
            slots[i]->flag = val;
    }
}
