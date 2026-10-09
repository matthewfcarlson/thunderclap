typedef unsigned int u32;
extern "C" void* memcpy(void*, const void*, unsigned int);
class Obj { public: char pad[0x1c]; u32 data[16]; char pad2[0x10]; unsigned char flag; void Copy(u32* src); };
void Obj::Copy(u32* src) { memcpy(data, src, 64); flag = 0; }