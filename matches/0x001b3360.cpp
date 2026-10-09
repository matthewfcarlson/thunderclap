extern "C" char* strncpy(char*, const char*, unsigned int);
extern "C" char gData[];
void FUN_001b3360(int index, char* name, char* description, int value) {
    if (index < 0 || index >= 13)
        return;
    if (name != 0)
        strncpy(gData + index * 0xb4, name, 0x3f);
    int offset = index * 0xb4;
    gData[offset + 0x3f] = 0;
    if (description != 0)
        strncpy(gData + offset + 0x40, description, 0x3f);
    gData[offset + 0x7f] = 0;
    *(int*)(gData + offset + 0xb0) = value;
}