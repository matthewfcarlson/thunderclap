class C {
  public:
    int Get(int index);
};
int C::Get(int index) {
    if (index >= 0 && index < 0x20)
        return ((int*)this)[index];
    return 0;
}