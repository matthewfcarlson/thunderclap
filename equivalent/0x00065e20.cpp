// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 12/12)
// FUN_00065e20 @ 0x00065e20
struct Key_65e20 {
    int lo;
    int hi;
};

class KeySet_65e20 {
public:
    char pad0[0x10];
    Key_65e20 keys[40];       // 0x10
    int count;          // 0x150
    void FUN_00065e20(const Key_65e20* key);
};

// Removes the first entry equal to *key, shifting the rest down.
void KeySet_65e20::FUN_00065e20(const Key_65e20* key)
{
    if (count <= 0)
        return;
    int lo = key->lo;
    int hi = key->hi;
    int i = 0;
    while (keys[i].lo != lo || keys[i].hi != hi) {
        i++;
        if (i >= count)
            return;
    }
    for (i++; i < count; i++)
        keys[i - 1] = keys[i];
    count--;
}
