struct Resource {
    virtual void unused();
    virtual void release();
};
struct Owner {
    char pad0[4];
    int state;
    int field8;
    char padc[4];
    int field10;
    int field14;
    unsigned char flag18, flag19;
    char pad1a[2];
    int count1;
    Resource* resources1[31];
    int count2;
    Resource* resources2[4];
    Resource* rB0;
    Resource* rB4;
    Resource* rB8;
    Resource* rBC;
    Resource* rC0;
    Resource* rC4;
    int FUN_0009a0e0();
};
int Owner::FUN_0009a0e0() {
    if (rB8) {
        rB8->release();
        rB8 = 0;
    }
    if (rB0) {
        rB0->release();
        rB0 = 0;
    }
    if (rB4) {
        rB4->release();
        rB4 = 0;
    }
    if (rBC) {
        rBC->release();
        rBC = 0;
    }
    if (rC0) {
        rC0->release();
        rC0 = 0;
    }
    if (rC4) {
        rC4->release();
        rC4 = 0;
    }
    for (int i = 0; i < count1; ++i) {
        if (resources1[i]) {
            resources1[i]->release();
            resources1[i] = 0;
        }
    }
    int n = count2;
    count1 = 0;
    for (int j = 0; j < n; ++j) {
        if (resources2[j]) {
            resources2[j]->release();
            resources2[j] = 0;
        }
        n = count2;
    }
    count2 = 0;
    field10 = 0;
    flag18 = 0;
    field14 = 0;
    field8 = 0;
    state = 1;
    flag19 = 1;
    return 1;
}