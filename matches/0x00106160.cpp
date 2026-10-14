class Target_106160 {
    char pad[0x10];
    int value;

  public:
    int Get(int index);
};
int Target_106160::Get(int index) {
    return value + index * 0x24;
}