class Obj {
  public:
    char pad[0x11b4];
    int count;
    float values[16];
    char data[0x20];
    void Add(float value, const void* src);
};
extern void Copy(void*, const void*, int);
void Obj::Add(float value, const void* src) {
    if (count < 16) {
        values[count] = value;
        Copy(data + count * 0x20, src, 0x20);
        ++count;
    }
}