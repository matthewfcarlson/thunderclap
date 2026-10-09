class Obj { public: char pad[0x68]; unsigned count; char rest[0x100]; bool FindSet(int key, int value); };
bool Obj::FindSet(int key, int value) {
    unsigned i = 0;
    while (i < count) {
        int* p = (int*)((char*)this + 0x6c + i * 0x28);
        if (*p == key) { p[8] = value; return true; }
        ++i;
    }
    return false;
}