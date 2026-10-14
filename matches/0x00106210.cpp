class C_106210 {
  public:
    char pad[8];
    int count;
    int* values;
    int Get(int index);
};
int C_106210::Get(int index) {
    if (index >= 0 && index < count)
        return values[index];
    return 0;
}