class C_ace20 {
  public:
    char pad[0x14];
    int* items;
    int Get(int i);
};
int C_ace20::Get(int i) {
    return items[i];
}