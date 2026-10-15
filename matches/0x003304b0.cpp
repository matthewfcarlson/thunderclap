class Obj {
    char pad0[0x80];
    void* ptr;
    char pad1[0xd8 - 0x84];
    int value;

  public:
    void Update();
    void Set(float x);
};
void Obj::Set(float x) {
    int n = (int)(x * 256.0f);
    if (n != value) {
        value = n;
        if (n < 32)
            n = 32;
        value = n;
        if (n > 128)
            n = 128;
        value = n;
        if (ptr)
            Update();
    }
}