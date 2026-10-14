// STATUS: equivalent (tools/equiv.py level 3: 1510 inputs, branch coverage 10/10)
// FUN_001c7870 @ 0x001c7870
class SlotPool {
public:
    char pad0[8];
    int capacity;       // 0x8
    int freeCount;      // 0xc
    int top;            // 0x10
    int* slots;         // 0x14
    void FUN_001c7770(int newCapacity);
    void FUN_001c7870(int unused, int value);
};

// Stores value in the first empty slot, or appends it (growing the pool when full).
void SlotPool::FUN_001c7870(int unused, int value)
{
    if (freeCount != 0 && top >= 0) {
        int* p = slots;
        for (int i = 0; i <= top; i++) {
            if (p[i] == 0) {
                p[i] = value;
                freeCount--;
                return;
            }
        }
    }
    if (top == capacity - 1)
        FUN_001c7770(capacity * 2);
    top++;
    slots[top] = value;
}
