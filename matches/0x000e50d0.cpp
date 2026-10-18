// FUN_000e50d0 @ 0x000e50d0
struct Slot_e50d0 { char pad[0xab8]; char flag; };
struct Target_e50d0 {
    char pad0[0xabc];
    Slot_e50d0 *slots[(0xb3c - 0xabc) / 4];
    int count;
    void FUN_000e50d0(int idx, char val);
};
void Target_e50d0::FUN_000e50d0(int idx, char val)
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
