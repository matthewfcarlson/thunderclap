// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00271930 @ 0x00271930
void __cdecl FUN_00271930(char* dest, const char* src, unsigned int size) {
    unsigned int i = 0;
    if (*src) {
        unsigned int limit = size - 1;
        while (i != limit && *src) {
            dest[i] = *src;
            ++i;
            ++src;
        }
    }
    dest[i] = 0;
}
