typedef unsigned char u8_2989c0;
typedef unsigned int u32_2989c0;
class Buffer_2989c0 {
  public:
    char pad0[8];
    u8_2989c0 count;
    char pad9[3];
    u8_2989c0* data;
    char pad10[8];
    u8_2989c0* out;
    char pad1c[8];
    u32_2989c0* flags;
    void Add(u8_2989c0 value);
};
void Buffer_2989c0::Add(u8_2989c0 value) {
    if (flags[value] != 0 && data[value] == 0xff) {
        data[value] = count;
        out[count] = value;
        ++count;
    }
}