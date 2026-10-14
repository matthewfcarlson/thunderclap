class C_932a0 {
  public:
    char pad[0xbf8];
    int values[100];
    int Get(int index);
};
int C_932a0::Get(int index) {
    if (index >= 100)
        return -1;
    return values[index];
}