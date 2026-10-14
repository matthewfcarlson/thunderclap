struct Record;
struct Shape {
    char data[56];
    bool FUN_0022d2b0(Record* other, float tolerance);
};
struct Record {
    char prefix[12];
    Shape shape;
    unsigned char active;
    char padding[3];
};
struct Owner {
    char prefix[0x1904];
    Record records[7][14];
    void FUN_0007a840(int group, int index, int* foundGroup, int* foundIndex);
};
void Owner::FUN_0007a840(int group, int index, int* foundGroup, int* foundIndex) {
    for (int g = 0; g < 7; ++g) {
        if (g == group)
            continue;
        for (int i = 0; i < 14; ++i) {
            Record* candidate = &records[g][i];
            if (!candidate->active)
                break;
            if (records[group][index].shape.FUN_0022d2b0(candidate, 0.1f)) {
                *foundGroup = g;
                *foundIndex = i;
                return;
            }
        }
    }
    *foundGroup = -1;
    *foundIndex = -1;
}
