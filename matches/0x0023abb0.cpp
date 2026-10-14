class Obj_23abb0 {
  public:
    char pad[0x12c];
    int count;
    char pad2[8];
    struct Item {
        int type;
        volatile int ivalue;
        char pad[16];
    } items[1];
    bool Get(int idx, bool* out);
};
bool Obj_23abb0::Get(int idx, bool* out) {
    if (idx < 0 || idx >= count)
        return false;
    switch (items[idx].type) {
    case 1:
        *out = items[idx].ivalue != 0;
        return true;
    case 2:
        *out = (int)*(float*)&items[idx].ivalue != 0;
        return true;
    }
    return false;
}