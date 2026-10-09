class Target {
    char pad[0x22fc];

  public:
    unsigned char Get();
};
unsigned char Target::Get() {
    return *(unsigned char*)((char*)this + 0x22fc);
}