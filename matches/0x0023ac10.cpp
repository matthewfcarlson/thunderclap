class Obj {
    char pad[0x12c];
    int count;
    char gap[0x8];
    struct Entry {
        int type;
        float value;
        char rest[16];
    } entries[1];

  public:
    char get(int index, int* out);
};
char Obj::get(int index, int* out) {
    if (index >= 0 && index < count) {
        switch (entries[index].type) {
        case 1:
            *out = *(int*)&entries[index].value;
            return 1;
        case 2:
            *out = (int)entries[index].value;
            return 1;
        }
    }
    return 0;
}