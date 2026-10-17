// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001dd190 @ 0x001dd190
struct Entry { int first; int second; float value; int unused; };
struct Object { char pad[0x1ec60]; Entry entries[16]; float FUN_001dd190(int first, int second); };
float Object::FUN_001dd190(int first, int second) {
    for (int i = 0; i < 16; ++i) {
        if (entries[i].first == first && entries[i].second == second)
            return entries[i].value;
    }
    return -1.0f;
}