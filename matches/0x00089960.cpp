class C_89960 {
  public:
    char pad[0x110];
    int values[10];
    int Get(int index);
};
int C_89960::Get(int index) {
    if (index >= 0 && index < 10)
        return values[index];
    return -1;
}