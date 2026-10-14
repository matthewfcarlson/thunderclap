struct Record_7a840;
struct Shape_7a840 {
    char data[56];
    bool FUN_0022d2b0(Record_7a840* other, float tolerance);
};
struct Record_7a840 {
    char prefix[12];
    Shape_7a840 shape;
    unsigned char active;
    char padding[3];
};
struct Owner_7a840 {
    char prefix[0x1904];
    Record_7a840 records[7][14];
    void FUN_0007a840(int group, int index, int* foundGroup, int* foundIndex);
};
void Owner_7a840::FUN_0007a840(int group, int index, int* foundGroup, int* foundIndex) {
    for (int g = 0; g < 7; ++g) {
        if (g == group)
            continue;
        for (int i = 0; i < 14; ++i) {
            Record_7a840* candidate = &records[g][i];
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
