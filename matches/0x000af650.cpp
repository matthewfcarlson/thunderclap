extern unsigned char gFlag;
class Obj { public: char pad0[8]; unsigned char enabled; char pad9[0x14-9]; int *data; void Set(int, unsigned int, float); };
void Obj::Set(int index, unsigned int element, float value) {
    if (enabled && element < (unsigned int)data[index * 12]) {
        if (gFlag) data[index * 12 + element + 5] = 0;
        *(float *)(data + index * 12 + element + 3) = value;
    }
}