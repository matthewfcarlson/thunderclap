class Target {
  public:
    char pad[0x2c];
    int* values;
    int Get(int index);
};
int Target::Get(int index) {
    return values[index];
}