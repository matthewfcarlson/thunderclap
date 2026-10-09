struct Item {
    short value;
    char pad[0x26];
};
class Obj {
  public:
    char pad[0x62a];
    Item indices[0x800];
    bool target(int index, int mode);
};
bool Obj::target(int index, int mode) {
    bool result = false;
    if (index >= 0 && index < 0x800) {
        short n = indices[index].value;
        unsigned short* p = (unsigned short*)((char*)this + (n + 0x104e) * 0x14);
        unsigned short v = *p & 0xf3ff;
        if (mode == 1 || mode == 3)
            v |= 0x400;
        if (mode == 2 || mode == 3)
            v |= 0x800;
        *p = v;
        result = true;
    }
    return result;
}