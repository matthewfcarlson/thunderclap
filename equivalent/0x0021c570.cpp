// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 4/4)
// FUN_0021c570 @ 0x0021c570
struct Entry { int unused; int value; int unused2; };
struct Table { char pad[0x18]; Entry* entries; };
struct Data {
    Table* table;
    char pad0[0x14];
    int value;
    char pad1[0x18];
    unsigned char count;
    char pad2[0x41];
    unsigned short indices[256];
};
struct Owner { char pad[0x1c]; Data* data; };
// equiv-conv: FUN_0021c570 eax edx
void FUN_0021c570(Owner* owner, int n) {
    Data* data = owner->data;
    data->count = (unsigned char)(data->count + n);
    while (n != 0) {
        unsigned int index = (unsigned int)data->count - n;
        data->table->entries[data->indices[index]].value = data->value;
        --n;
    }
}