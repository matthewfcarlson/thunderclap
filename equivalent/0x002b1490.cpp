// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 10/10)
// FUN_002b1490 @ 0x002b1490
struct IntVec_2b1490 {
    int* begin;
    int* end;
};

struct Source_2b1490 {
    char pad[0x28];
    IntVec_2b1490 vec;
};

struct Rec16 {
    char pad[16];
};

struct Scratch_2b1490 {
    int w[6];
};

struct RecList {
    Rec16* data;
    char pad[12];
    void FUN_002b1330(int count, Scratch_2b1490* s);
};

struct Index_2b1490 {
    char pad[12];
    void FUN_002b1070(int first, Scratch_2b1490* s);
};

class Packer {
public:
    void run();
    void FUN_002b1230(Rec16* dst, int len, int* src, int start);
    char p0[0x10];
    Source_2b1490* source;
    char p1[0x20 - 0x14];
    Index_2b1490 index;
    RecList list;
};

void Packer::run()
{
    IntVec_2b1490* vec = &source->vec;
    unsigned int count = (unsigned int)(vec->end - vec->begin);
    Scratch_2b1490 s;

    if (count < 2 || vec->begin[0] >= 0) {
        for (int i = 0; i < 6; i++)
            s.w[i] = 0;
        index.FUN_002b1070(count, &s);
        return;
    }

    s.w[0] = 0;
    s.w[1] = 0;
    list.FUN_002b1330(-vec->begin[0], &s);
    for (int i = 0; i < 6; i++)
        s.w[i] = 0;
    index.FUN_002b1070(vec->begin[1], &s);

    int prev = -1;
    int start = vec->begin[1];
    int groups = 0;
    for (unsigned int i = start; i < (unsigned int)(vec->end - vec->begin); i++) {
        int v = vec->begin[i];
        if (v > prev) {
            prev = v;
        } else {
            FUN_002b1230(list.data + groups, (int)i - start, &vec->begin[start], start);
            groups++;
            start = i;
            prev = -1;
        }
    }
    FUN_002b1230(list.data + groups, (int)(vec->end - vec->begin) - start, &vec->begin[start], start);
}
