class C_1b68e0 {
  public:
    int Get(int index);
};
int C_1b68e0::Get(int index) {
    if (index >= 0 && index < 0x20)
        return ((int*)this)[index];
    return 0;
}