// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 15/16, incomplete)
// FUN_001d7890 @ 0x001d7890
struct Item74 { char pad0[0x71]; char b71; char b72; };
struct Item10_1d7890 { char pad0[0x74]; Item74 *p74; };
struct Node { char pad0[0x10]; Item10_1d7890 *p10; };
struct Rec_1d7890 { char pad0[0x44]; int count; };
struct ItemList_1d7890 { char pad0[0x1c]; };

struct Indexer_1d7890 {
    ItemList_1d7890 *FUN_001d4fc0();
    int FUN_001d5c70(int index);
    bool FUN_001d4df0();
    Node *FUN_001d4e00();
    Rec_1d7890 *FUN_001d56f0(int i);
};

struct SubA_1d7890 {
    int a; int pad4; int b; int padc; int c;
    void FUN_001b6d60();
};
struct SubB_1d7890 {
    int a; int b;
    SubB_1d7890 *FUN_0027af00();
};

class __declspec(novtable) CSPHulkPropBase {
public:
    CSPHulkPropBase(ItemList_1d7890 *list, int arg) { FUN_0027def0(list, arg); }
    virtual void v0();
    CSPHulkPropBase *FUN_0027def0(ItemList_1d7890 *list, int arg);
};

class CSPHulkPropInstance : public CSPHulkPropBase {
public:
    CSPHulkPropInstance(Indexer_1d7890 *idx, int arg);
    virtual void v1();
    char pad4[0x9c];
    Node* node;
    char pada4[0x44];
    char fe8;
    char pade9[0x3];
    Indexer_1d7890* indexer;
    int ff0;
    int ff4;
    char ff8;
    char ff9;
    char padfa[0x6];
    char f100;
    char pad101[0x3];
    int f104;
    int f108;
    int f10c;
    char f110;
    char f111;
    char pad112[0x2];
    int f114;
    int f118;
    int f11c;
    int f120;
    int f124;
    int f128;
    char f12c;
    char pad12d[0x3];
    int f130;
    int f134;
    char f138;
    char pad139[0x3];
    int f13c;
    int f140;
    char f144;
    char pad145[0x3];
    int f148;
    char f14c;
    char f14d;
    char f14e;
    char pad14f[0x1];
    int f150;
    int f154;
    int f158;
    int f15c;
    int f160;
    char pad164[0x30];
    char f194;
    char pad195[0x3];
    int f198;
    int f19c;
    char f1a0;
    char f1a1;
    char pad1a2[0x2];
    SubA_1d7890 sub1;
    char pad1b8[0x4];
    int f1bc;
    int f1c0;
    int f1c4;
    char pad1c8[0x1];
    char f1c9;
    char pad1ca[0x2];
    int f1cc;
    char f1d0;
    char pad1d1[0x3];
    int f1d4;
    char f1d8;
    char f1d9;
    char pad1da[0x2];
    int f1dc;
    char f1e0;
    char pad1e1[0x3];
    int f1e4;
    int f1e8;
    char f1ec;
    char f1ed;
    char pad1ee[0x2];
    int f1f0;
    int f1f4;
    int f1f8;
    int f1fc;
    int f200;
    int f204;
    int f208;
    int f20c;
    int f210;
    int f214;
    int f218;
    int f21c;
    int f220;
    int f224;
    int f228;
    int f22c;
    int f230;
    int f234;
    int f238;
    char pad23c[0x4];
    SubB_1d7890 sub2;
    int f248;
    int f24c;
    int f250;
    int f254;
    int f258;
    int f25c;
    int f260;
    int f264;
    int f268;
    char f26c;
    char pad26d[0x3];
    int f270;
};

CSPHulkPropInstance::CSPHulkPropInstance(Indexer_1d7890 *idx, int arg)
    : CSPHulkPropBase(idx->FUN_001d4fc0(), arg)
{
    indexer = idx;
    fe8 = 0;
    ff0 = 0;
    ff4 = 0;
    ff8 = 0;
    ff9 = 0;
    f100 = 0;
    f104 = 0;
    f108 = 0;
    f10c = 0;
    f110 = 0;
    f111 = 0;
    f114 = 0;
    f118 = 0;
    f11c = 0;
    f120 = 0;
    f124 = 0;
    f128 = 0;
    f12c = 1;
    f134 = 0;
    f138 = 0;
    f13c = 0;
    f140 = 0;
    f144 = 0;
    f148 = 0;
    f14c = 0;
    f14d = 0;
    f14e = 0;
    f150 = 0;
    f154 = 0;
    f158 = 0;
    f15c = 0;
    f160 = 0;
    f194 = 0;
    f198 = 0;
    f19c = 0;
    f1a0 = 0;
    f1a1 = 0;
    sub1.FUN_001b6d60();
    f1bc = 1;
    f1c0 = 0;
    f1c4 = 0;
    f1c9 = 0;
    f1cc = 0;
    f1d0 = 0;
    f1d4 = -1;
    f1d8 = 1;
    f1d9 = 1;
    f1dc = 0;
    f1e0 = 0;
    f1e4 = 0;
    f1e8 = 0;
    f1ec = 0;
    f1ed = 0;
    f1f0 = 0;
    f1f4 = 0;
    f1f8 = 0;
    f1fc = 0;
    f200 = 0;
    f204 = 0;
    f208 = 0;
    f20c = 0;
    f210 = 0;
    f214 = 0;
    f218 = 0;
    f21c = 0;
    f220 = 0;
    f224 = 0;
    f228 = 0;
    f22c = 0;
    f230 = 0;
    f234 = 0;
    f238 = 0;
    sub2.FUN_0027af00();
    f248 = 0;
    f24c = 0;
    f250 = 2;
    f254 = -1;
    f258 = 0;
    f25c = 0;
    f260 = 0;
    f264 = 0;
    f268 = 0;
    f26c = 0;
    f270 = 0;
    f108 = idx->FUN_001d5c70(arg);
    f110 = f108 > 0;
    f130 = 0;
    if (indexer->FUN_001d4df0()) {
        f150 = (int)indexer->FUN_001d4e00();
        if (node) {
            Item10_1d7890 *a = node->p10;
            if (a) {
                Item74 *b = a->p74;
                if (b) {
                    b->b72 = 0;
                    Item10_1d7890 *c = node ? node->p10 : 0;
                    c->p74->b71 = 0;
                }
            }
        }
    }
    int i = 0;
    if (indexer->FUN_001d56f0(0)->count > 0) {
        Rec_1d7890 *r;
        do {
            i++;
            r = indexer->FUN_001d56f0(0);
        } while (i < r->count);
    }

}
