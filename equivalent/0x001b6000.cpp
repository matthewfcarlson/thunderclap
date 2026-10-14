// STATUS: equivalent (tools/equiv.py level 3: 109 inputs, branch coverage 16/18, incomplete)
// FUN_001b6000 @ 0x001b6000
struct Rec_1b6000 {
    char pad0[0x18];
    float x;
    float y;
    float z;
    float w;
    char pad1[0x44 - 0x28];
    void FUN_002f8e10(void **item, int *id);
};

class Registry_1b6000 {
public:
    char pad0[0x1b0];
    Rec_1b6000 *begin;
    Rec_1b6000 *end;
    char FUN_002edb90(int id, int mode);
};

extern Registry_1b6000 *DAT_00554c14;
extern float DAT_003f3388;

class Tracker_1b6000 {
public:
    char pad0[0x594];
    void **itemsBegin;
    void **itemsEnd;
    char FUN_001b6000(int id, void ***outList, int *outId);
};

char Tracker_1b6000::FUN_001b6000(int id, void ***outList, int *outId)
{
    Registry_1b6000 *reg = DAT_00554c14;
    if (!reg->FUN_002edb90(id, 10))
        return 0;
    Rec_1b6000 *begin = reg->begin;
    int n = reg->end - begin;
    unsigned int i;
    for (i = 0; i < (unsigned int)n; i++) {
        Rec_1b6000 *r = &reg->begin[i];
        if (!(r->w < 0.0f)) {
            void *item;
            r->FUN_002f8e10(&item, &id);
            Rec_1b6000 *r2 = &reg->begin[i];
            if (!((r2->z * 0.0f + r2->y * DAT_003f3388) + r2->x * 0.0f > 0.0f)) {
                void ***list = (void ***)&itemsBegin;
                unsigned int idx = 0;
                if ((int)(((char *)itemsEnd - (char *)itemsBegin) & 0xfffffffc) > 0) {
                    for (;;) {
                        unsigned int cnt = itemsEnd - itemsBegin;
                        void *e = idx < cnt ? itemsBegin[idx] : 0;
                        if (e == item) {
                            id |= idx << 16;
                            break;
                        }
                        idx++;
                        if ((int)idx >= (int)(itemsEnd - itemsBegin))
                            break;
                    }
                }
                *outList = (void **)&itemsBegin;
                *outId = id;
                return 1;
            }
        }
    }
    return 0;
}
