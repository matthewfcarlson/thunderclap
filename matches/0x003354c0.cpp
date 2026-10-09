typedef unsigned int u32;
struct Item {
    char pad[8];
    volatile int kind;
};
struct Info {
    char pad[0x44];
    int count;
    Item* Find(int);
};
class C {
  public:
    char pad0[4];
    Info* info;
    u32* values;
    bool Get(int index, u32* out);
};
bool C::Get(int index, u32* out) {
    if (index < 0)
        return false;
    if (index >= info->count)
        return false;
    if (info->Find(index)->kind != 1)
        return false;
    *out = values[index];
    return true;
}
