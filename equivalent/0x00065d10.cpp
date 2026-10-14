// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 12/12)
// FUN_00065d10 @ 0x00065d10
struct Key_65d10 {
    int lo;
    int hi;
};

class KeySet_65d10 {
public:
    char pad0[0x170];
    Key_65d10 keys[40];       // 0x170
    int count;          // 0x2b0
    void FUN_00065d10(const Key_65d10* key);
};

// Removes the first entry equal to *key, shifting the rest down.
void KeySet_65d10::FUN_00065d10(const Key_65d10* key)
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
