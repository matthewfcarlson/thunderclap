class Thing {
  public:
    char pad0[0x40];
    int count;
    void* base;
    char pad48[8];
    void* value;
    void set(void* p);
};
void Thing::set(void* p) {
    value = p;
    for (int i = 0; i < count * 4; ++i) {
        int off = i * 0x18;
        *(void**)((char*)off + (int)base + 0xc) = value;
    }
}