class Target_37410 {
    char pad[0x22fc];

  public:
    unsigned char Get();
};
unsigned char Target_37410::Get() {
    return *(unsigned char*)((char*)this + 0x22fc);
}