// STATUS: equivalent (tools/equiv.py level 3: 39 inputs, branch coverage 28/32, incomplete)
// FUN_0029ccb0 @ 0x0029ccb0
extern unsigned int DAT_004cf734;

struct Item {
    char pad0[0x14];
    unsigned int packed;
    void FUN_002a07a0(unsigned int color);
};

struct ItemList {
    char pad0[0x10];
    int capacity;
    int count;
    Item **items;
};

class Shader {
public:
    char pad0[0x14];
    float scale;
    void FUN_0029ccb0(ItemList *list, float amount);
};

void Shader::FUN_0029ccb0(ItemList *list, float amount)
{
    int sum = 0;
    int n = list->count;
    int i;
    if (n > 0) {
        for (i = 0; i < n; i++) {
            if (i < list->capacity) {
                Item *it = list->items[i];
                if (it) {
                    int m = it->packed & 0xff;
                    int g = (it->packed >> 8) & 0xff;
                    int b = (it->packed >> 16) & 0xff;
                    if (!(g < m))
                        m = g;
                    if (!(b < m))
                        m = b;
                    sum += m;
                }
            }
        }
        i = 0;
        do {
            if (i < list->capacity) {
                Item *it = list->items[i];
                if (it) {
                    unsigned int color;
                    if (sum != 0) {
                        int m = it->packed & 0xff;
                        int g = (it->packed >> 8) & 0xff;
                        int b = (it->packed >> 16) & 0xff;
                        if (!(g < m))
                            m = g;
                        if (!(b < m))
                            m = b;
                        int c = (int)((float)m * scale / sum * amount * m);
                        if (c < 0)
                            c = 0;
                        else if (c > 255)
                            c = 255;
                        int inv = 255 - c;
                        color = 0xff000000u | (inv << 16) | (inv << 8) | inv;
                    } else {
                        color = DAT_004cf734;
                    }
                    it->FUN_002a07a0(color);
                }
            }
            i++;
        } while (i < list->count);
    }
}
