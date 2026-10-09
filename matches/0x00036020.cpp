class Thing {
    char pad[0x62c];

  public:
    unsigned int value;
    unsigned int FUN_00036020();
};
unsigned int Thing::FUN_00036020() {
    return value;
}