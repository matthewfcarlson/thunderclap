class C_208b90 {
    char pad[0x2e];
    short items[1];

  public:
    int get(int index);
};
int C_208b90::get(int index) {
    return items[index];
}