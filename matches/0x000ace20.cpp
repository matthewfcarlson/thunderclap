class C {
  public:
    char pad[0x14];
    int* items;
    int Get(int i);
};
int C::Get(int i) {
    return items[i];
}