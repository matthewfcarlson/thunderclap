class C_a9130 {
    char pad[0x158];
    int values[3];

  public:
    void Set(int index, int value);
};
void C_a9130::Set(int index, int value) {
    values[index * 3] = value;
}