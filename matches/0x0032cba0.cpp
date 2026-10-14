struct Block_32cba0 {
    unsigned int x[16];
};
class Thing_32cba0 {
    char pad[0x88];

  public:
    void Copy(Block_32cba0* src);
};
void Thing_32cba0::Copy(Block_32cba0* src) {
    *(Block_32cba0*)((char*)this + 0x88) = *src;
}