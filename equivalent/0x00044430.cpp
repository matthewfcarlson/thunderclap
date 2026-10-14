// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00044430 @ 0x00044430
struct Id64_44430 {
    unsigned int lo, hi;
    void FUN_0027af10(unsigned int lo, unsigned int hi);
    void FUN_0027af50() throw();
};
struct Pair_44430 {
    char pad0[8];
    unsigned int f08;
    unsigned int f0c;
};
struct Sub_44430 {
    int FUN_001c5b00(Id64_44430 *id);
};
struct Singleton_44430 {
    char pad0[0xc];
    Sub_44430 *sub;
    void FUN_001c3740(Id64_44430 *id);
};
Singleton_44430 *FUN_001c3d90();

struct Owner_44430 {
    char pad0[8];
    Pair_44430 *pair;
    void FUN_00044430();
};

void Owner_44430::FUN_00044430()
{
    Id64_44430 id;
    id.FUN_0027af10(pair->f08, pair->f0c);
    int found = FUN_001c3d90()->sub->FUN_001c5b00(&id);
    id.FUN_0027af50();
    if (found) {
        id.FUN_0027af10(pair->f08, pair->f0c);
        FUN_001c3d90()->FUN_001c3740(&id);
        id.FUN_0027af50();
    }
}
