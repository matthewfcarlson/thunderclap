class Target {
  public:
    char pad[0xABD];
    unsigned char value;
    unsigned char Get();
};
unsigned char Target::Get() {
    return value;
}