// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00092c40 @ 0x00092c40
struct Entry { int first; int second; char rest[0x48]; };
struct Object { char pad[0xd90]; Entry entries[32]; int FUN_00092c40(int first, int second); };
int Object::FUN_00092c40(int first, int second) {
    for (int i = 0; i < 32; ++i) {
        if (entries[i].first == first && entries[i].second == second)
            return i;
    }
    return -1;
}