struct Obj_1dd800 {
    char pad[0x62a];
    struct Rec {
        short index;
        char rest[0x26];
    } rec[0x800];
    bool target(int index);
};
bool Obj_1dd800::target(int index) {
    if (index < 0 || index >= 0x800)
        return false;
    short v = rec[index].index;
    return *((unsigned char*)this + (v + 0x104e) * 0x14) & 1;
}