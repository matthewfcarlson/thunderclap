class Target {
  public:
    char pad[0x28];
    unsigned int value;
    unsigned int Get();
};
unsigned int Target::Get() {
    return value;
}