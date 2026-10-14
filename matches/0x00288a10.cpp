class Target_288a10 {
  public:
    char pad[0x2c];
    int* values;
    int Get(int index);
};
int Target_288a10::Get(int index) {
    return values[index];
}