class C_44ab0 {
  public:
    char pad[12];
    int count;
    int* items;
    int get(int i);
};
int C_44ab0::get(int i) {
    if (i >= 0 && i < count)
        return items[i];
    return 0;
}