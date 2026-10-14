class C_f7220 {
  public:
    char pad0[0x0c];
    int* items;
    int max;
    int Get(int index);
};
int C_f7220::Get(int index) {
    if (index < 0 || index > max)
        return 0;
    return items[index];
}