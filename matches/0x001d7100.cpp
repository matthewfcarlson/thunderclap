struct Table {
    char pad[0x1c];
    int* entries;
};
struct Obj {
    char pad0[0x40];
    int index;
    char pad1[0x54];
    Table* table;
    int Find(int);
};
int Obj::Find(int index) {
    if (index == -1)
        index = this->index;
    int* p = (int*)this->table->entries[index];
    int a = p[2];
    int b = p[3];
    int result = -1;
    for (int i = 0; i < 8; ++i) {
        if (a == ((int*)0x4e2560)[i * 2] && b == ((int*)0x4e2564)[i * 2]) {
            result = i;
            break;
        }
    }
    return result;
}
