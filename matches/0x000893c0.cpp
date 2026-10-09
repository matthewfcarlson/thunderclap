class Target {
  public:
    char pad[0xabf];
    unsigned char value;
    unsigned char Get();
};
unsigned char Target::Get() {
    return value;
}