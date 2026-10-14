struct Block_80e50 {
    unsigned int x[16];
};
class Target_80e50 {
    char pad[0x34];

  public:
    void Copy(const Block_80e50* src);
};
void Target_80e50::Copy(const Block_80e50* src) {
    *(Block_80e50*)((char*)this + 0x34) = *src;
}