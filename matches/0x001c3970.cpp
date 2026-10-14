typedef unsigned int u32_1c3970;
extern "C" void* memcpy(void*, const void*, unsigned int);
class Obj_1c3970 {
  public:
    char pad[0x1c];
    u32_1c3970 data[16];
    char pad2[0x10];
    unsigned char flag;
    void Copy(u32_1c3970* src);
};
void Obj_1c3970::Copy(u32_1c3970* src) {
    memcpy(data, src, 64);
    flag = 0;
}