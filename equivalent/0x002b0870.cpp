// STATUS: equivalent (tools/equiv.py level 3: 12 inputs, branch coverage 18/20, incomplete)
// FUN_002b0870 @ 0x002b0870
extern "C" double fabs(double);

struct KeyTable_2b0870 {
    char pad0[0x10];
    int count;           // 0x10
    char pad14[4];
    float *keys;         // 0x18
};

struct TableSet {
    char pad0[0x10];
    KeyTable_2b0870 **tables;   // 0x10
};

struct Segment_2b0870 {
    char kind;           // 0x00: 1 = interpolate between two keys
    char pad1[3];
    int index;           // 0x04
    int index2;          // 0x08
    float weightLow;     // 0x0c
    float weightHigh;    // 0x10
    float scale;         // 0x14
};

class Curves_2b0870 {
public:
    char pad0[0x10];
    TableSet *set;       // 0x10
    float *values;       // 0x14
    char pad18[8];
    Segment_2b0870 *segments;   // 0x20
    Segment_2b0870 *segmentsEnd; // 0x24
    void FUN_002b0870();
};

void Curves_2b0870::FUN_002b0870()
{
    if ((segmentsEnd - segments) == 0)
        return;

    unsigned int i = 0;
    int byteOffset = 0;
    do {
        KeyTable_2b0870 *tbl = set->tables[i];
        Segment_2b0870 *seg = (Segment_2b0870 *)((char *)segments + byteOffset);
        float x = values[i];
        int last = tbl->count - 1;

        if (last == 0) {
            seg->kind = 0;
            seg->index = 0;
            seg->scale = (float)fabs(x / tbl->keys[0]);
        } else {
            float *keys = tbl->keys;
            int k = -1;
            if (x > keys[0]) {
                for (;;) {
                    k++;
                    if (k == last)
                        break;
                    if (!(x > keys[k + 1]))
                        break;
                }
            }
            if (k == -1) {
                seg->kind = 0;
                seg->index = 0;
                seg->scale = (float)fabs(x / tbl->keys[0]);
            } else if (k == last) {
                seg->kind = 0;
                seg->index = last;
                seg->scale = (float)fabs(x / tbl->keys[last]);
            } else {
                float a = keys[k];
                float b = keys[k + 1];
                if (a * b < 0.0f) {
                    int neg = (x < 0.0f) ? 1 : 0;
                    int pick = (k + neg == 0) ? 1 : 0;
                    seg->index = pick;
                    seg->kind = 0;
                    seg->scale = (float)fabs(x / tbl->keys[pick]);
                } else {
                    seg->index = k;
                    seg->kind = 1;
                    seg->index2 = k + 1;
                    seg->scale = 1.0f;
                    seg->weightLow = 1.0f - (x - a) / (b - a);
                    seg->weightHigh = (x - a) / (b - a);
                }
            }
        }
        byteOffset += 0x18;
        i++;
    } while (i < (unsigned int)(segmentsEnd - segments));
}
