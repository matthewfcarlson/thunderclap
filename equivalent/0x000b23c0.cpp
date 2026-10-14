// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 28/28)
// FUN_000b23c0 @ 0x000b23c0
extern "C" int __cdecl _sprintf(char *, const char *, ...);
void __cdecl FUN_00267830(char *dst, const char *src, int n);
void *__cdecl FUN_0008d750(int size, int align);

struct Cell_b23c0 {
    int a;
    int b;
    void FUN_000b06e0();
};

void __stdcall FUN_00011520(void *arr, unsigned int size, int count, void (Cell_b23c0::*ctor)());

struct Node {
    int a, b, c, d;
};

struct Str_b23c0 {
    int cap;
    char *text;
    void FUN_000b1020(int n);
};

struct Words6_b23c0 {
    int v[6];
    int rest[6];
};

class CPhysicalController {
public:
    virtual void f0();
    int field4;
    int field8;
    bool enabled;
    bool flagD;
    char padE[2];
    int field10;
    char name[0x40];
    int field54;
    int zeroA[22];
    Cell_b23c0 cellsA[2][6];
    int zeroB[22];
    Cell_b23c0 cellsB[2][6];
    int zeroC[26];
    Cell_b23c0 cellsC[2][6];
    int zeroD[26];
    Cell_b23c0 cellsD[2][6];
    Node *nodesA[11];
    Words6_b23c0 blocksA[2];
    Node *nodesB[13];
    Words6_b23c0 blocksB[2];
    Str_b23c0 str478;
    Str_b23c0 str480;
    int field488;
    int field48c;
    int pad490[6];
    int field4a8;
    int field4ac;

    CPhysicalController(int arg);
};

CPhysicalController::CPhysicalController(int arg)
{
    field8 = arg;
    field4 = 0;
    enabled = true;
    flagD = false;
    field10 = 0;
    field54 = 3;
    int i;
    int j;
    for (i = 0; i < 22; i++)
        zeroA[i] = 0;
    for (j = 0; j < 2; j++)
        FUN_00011520(cellsA[j], 8, 6, &Cell_b23c0::FUN_000b06e0);
    for (i = 0; i < 22; i++)
        zeroB[i] = 0;
    for (j = 0; j < 2; j++)
        FUN_00011520(cellsB[j], 8, 6, &Cell_b23c0::FUN_000b06e0);
    for (i = 0; i < 26; i++)
        zeroC[i] = 0;
    for (j = 0; j < 2; j++)
        FUN_00011520(cellsC[j], 8, 6, &Cell_b23c0::FUN_000b06e0);
    for (i = 0; i < 26; i++)
        zeroD[i] = 0;
    for (j = 0; j < 2; j++)
        FUN_00011520(cellsD[j], 8, 6, &Cell_b23c0::FUN_000b06e0);
    str478.cap = 0;
    str478.text = 0;
    str480.cap = 0;
    str480.text = 0;
    field488 = 0;
    field48c = 0;
    field4a8 = 0;
    field4ac = 1;
    _sprintf(name, "%s", "");
    for (i = 0; i < 11; i++) {
        nodesA[i] = 0;
        nodesA[i] = (Node *)FUN_0008d750(0x10, 4);
        nodesA[i]->a = 0;
        nodesA[i]->b = 0;
        nodesA[i]->c = 0;
        nodesA[i]->d = 0;
    }
    for (i = 0; i < 13; i++) {
        nodesB[i] = 0;
        nodesB[i] = (Node *)FUN_0008d750(0x10, 4);
        nodesB[i]->a = 0;
        nodesB[i]->b = 0;
        nodesB[i]->c = 0;
        nodesB[i]->d = 0;
    }
    for (j = 0; j < 2; j++)
        for (i = 0; i < 6; i++)
            blocksA[j].v[i] = 0;
    for (j = 0; j < 2; j++)
        for (i = 0; i < 6; i++)
            blocksB[j].v[i] = 0;
    field488 = 0;
    field48c = 0;
    if (str478.cap <= 0)
        str478.FUN_000b1020(1);
    FUN_00267830(str478.text, "", 0x20);
    if (str480.cap <= 0)
        str480.FUN_000b1020(1);
    FUN_00267830(str480.text, "", 0x20);
}
