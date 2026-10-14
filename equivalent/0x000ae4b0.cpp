// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000ae4b0 @ 0x000ae4b0
struct Item_ae4b0 { void FUN_000b2810(); };
struct CController {
    virtual void slot0();
    int field4;
    int owner;
    unsigned char enabled;
    char padD[3];
    int count;
    Item_ae4b0 **items;
    int block18[17];
    int block5c[17];
    int fieldA0, fieldA4, fieldA8;
    int blockAc[17];
    int blockF0[17];
    unsigned char field134;
    void FUN_000ae090(int);
    CController(int);
};
CController::CController(int arg) {
    owner = arg;
    field4 = 0;
    enabled = 1;
    count = 0;
    items = 0;
    fieldA0 = fieldA4 = fieldA8 = 0;
    for (int i=0;i<17;++i) block18[i]=0;
    for (int j=0;j<17;++j) block5c[j]=0;
    fieldA0 = fieldA4 = fieldA8 = 0;
    for (int k=0;k<17;++k) blockAc[k]=0;
    for (int l=0;l<17;++l) blockF0[l]=0;
    field134=0;
    FUN_000ae090(4);
    for (int n=0;n<count;++n) items[n]->FUN_000b2810();
}