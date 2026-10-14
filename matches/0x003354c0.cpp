typedef unsigned int u32_3354c0;
struct Item_3354c0 {
    char pad[8];
    volatile int kind;
};
struct Info_3354c0 {
    char pad[0x44];
    int count;
    Item_3354c0* Find(int);
};
class C_3354c0 {
  public:
    char pad0[4];
    Info_3354c0* info;
    u32_3354c0* values;
    bool Get(int index, u32_3354c0* out);
};
bool C_3354c0::Get(int index, u32_3354c0* out) {
    if (index < 0)
        return false;
    if (index >= info->count)
        return false;
    if (info->Find(index)->kind != 1)
        return false;
    *out = values[index];
    return true;
}
