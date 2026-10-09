class Obj {
  public:
    char pad0[0x608];
    struct Entry {
        char pad[0x28];
    } entries[1];
    int get(int index);
};
int Obj::get(int index) {
    int result = -1;
    if (index >= 0) {
        Entry* e = (Entry*)((char*)this + 0x608 + index * 0x28);
        short state = *(short*)((char*)e + 0x22);
        if ((*(unsigned char*)((char*)this + (state + 0x104e) * 0x14) & 1) != 0) {
            int* p = (int*)((char*)e + 0x18);
            if (*p != 0)
                return *(int*)((char*)*p + 0x40);
        }
        result = *(signed char*)((char*)e + 0x26);
    }
    return result;
}