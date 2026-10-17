// STATUS: equivalent (tools/equiv.py level 3: 2544 inputs, branch coverage 12/12)
// FUN_00264140 @ 0x00264140
struct Converter { char pad[15]; unsigned char reverse; void FUN_00264140(unsigned char* data, unsigned int count, unsigned int size); };
void Converter::FUN_00264140(unsigned char* data, unsigned int count, unsigned int size)
{
    if (!reverse || size == 1) return;
    for (unsigned int i = 0; i < count; ++i) {
        unsigned char* left = data;
        unsigned char* right = data + size - 1;
        while (left < right) {
            unsigned char value = *right;
            *right = *left;
            *left = value;
            ++left;
            --right;
        }
        data += size;
    }
}