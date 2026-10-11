// STATUS: equivalent (tools/equiv.py level 3: 38 inputs, branch coverage 25/32, incomplete)
// FUN_00219a60 @ 0x00219a60
struct TObject {
    int tt;
    float n;
};
struct Node {
    TObject key;
    TObject val;
    Node* next;
};
struct Table {
    char pad0[7];
    unsigned char lsizenode;
    char pad8[4];
    TObject* array;
    Node* node;
    char pad14[8];
    int sizearray;
};

int FUN_00215f70(unsigned int x);
// equiv-conv: FUN_002199d0 edx stack stack stack
int FUN_002199d0(int* nums, int total, int* pna, int* out);

int FUN_00219a60(Table* t, int* pna, int* out)
{
    int nums[25];
    int total = 0;
    int i = 0;
    int sizearray = t->sizearray;
    int lg = 0;
    for (; lg <= 24; lg++) {
        int lim = 1 << lg;
        if (lim > sizearray) {
            lim = sizearray;
            if (i >= lim)
                break;
        }
        nums[lg] = 0;
        if (i < lim) {
            TObject* p = t->array + i;
            int cnt = lim - i;
            i += cnt;
            do {
                if (p->tt != 0) {
                    nums[lg]++;
                    total++;
                }
                p++;
            } while (--cnt != 0);
        }
    }
    for (; lg <= 24; lg++)
        nums[lg] = 0;

    *pna = total;
    int sizenode = 1 << t->lsizenode;
    float limit = (float)(2 * (sizenode + total));
    if (!(limit < 16777216.0f))
        limit = 16777216.0f;
    for (int n = sizenode; n != 0; n--) {
        Node* nd = &t->node[n - 1];
        if (nd->val.tt == 0)
            continue;
        if (nd->key.tt == 3) {
            float k = nd->key.n;
            if (!(k <= 0.0f) && !(k > limit)) {
                int ki = (int)k;
                if ((float)ki == k && ki >= 0) {
                    int b = FUN_00215f70((unsigned int)(ki - 1));
                    nums[b + 1] = nums[b + 1] + 1;
                    (*pna)++;
                }
            }
        }
        total++;
    }
    return FUN_002199d0(nums, total, pna, out);
}
