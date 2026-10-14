// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00044430 @ 0x00044430
struct Id64 {
    unsigned int lo, hi;
    void FUN_0027af10(unsigned int lo, unsigned int hi);
    void FUN_0027af50() throw();
};
struct Pair {
    char pad0[8];
    unsigned int f08;
    unsigned int f0c;
};
struct Sub {
    int FUN_001c5b00(Id64 *id);
};
struct Singleton {
    char pad0[0xc];
    Sub *sub;
    void FUN_001c3740(Id64 *id);
};
Singleton *FUN_001c3d90();

struct Owner {
    char pad0[8];
    Pair *pair;
    void FUN_00044430();
};

void Owner::FUN_00044430()
{
    Id64 id;
    id.FUN_0027af10(pair->f08, pair->f0c);
    int found = FUN_001c3d90()->sub->FUN_001c5b00(&id);
    id.FUN_0027af50();
    if (found) {
        id.FUN_0027af10(pair->f08, pair->f0c);
        FUN_001c3d90()->FUN_001c3740(&id);
        id.FUN_0027af50();
    }
}
