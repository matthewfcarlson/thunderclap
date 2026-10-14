struct Item_1dc230 {
    short value;
    char pad[0x26];
};
class Obj_1dc230 {
  public:
    char pad[0x62a];
    Item_1dc230 indices[0x800];
    bool target(int index, int mode);
};
bool Obj_1dc230::target(int index, int mode) {
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