typedef unsigned char u8;
typedef unsigned int u32;
class Buffer {
  public:
    char pad0[8];
    u8 count;
    char pad9[3];
    u8* data;
    char pad10[8];
    u8* out;
    char pad1c[8];
    u32* flags;
    void Add(u8 value);
};
void Buffer::Add(u8 value) {
    if (flags[value] != 0 && data[value] == 0xff) {
        data[value] = count;
        out[count] = value;
        ++count;
    }
}