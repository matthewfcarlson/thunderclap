// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 22/26, incomplete)
// FUN_00321dc0 @ 0x00321dc0
struct Entry {
    char padding[0x70];
    int key;
    char padding2[4];
    unsigned char active;
    char padding3[3];
};
struct Entries { int header; Entry entries[8]; };
struct Object {
    char padding[0x50];
    Entries *data;
    unsigned int FUN_00321dc0(int *output, int key);
};
unsigned int Object::FUN_00321dc0(int *output, int key) {
    output[0] = -1;
    output[1] = -1;
    output[2] = -1;
    output[3] = -1;
    unsigned int count = 0;
    for (int i = 0; i < 8 && count < 4; ++i) {
        if (data->entries[i].active && data->entries[i].key == key) {
            output[count++] = i;
        }
    }
    return count;
}