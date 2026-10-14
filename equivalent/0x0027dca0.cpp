// STATUS: equivalent (tools/equiv.py level 3: 574 inputs, branch coverage 4/4)
// FUN_0027dca0 @ 0x0027dca0
struct Id64 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af00();
    void FUN_0027af50();
    void FUN_0027af70(Id64 *src);
    Id64 *FUN_0027b0e0(const char *name);
};

extern char DAT_003f335c;

class Chain;

class Handler {
public:
    virtual void vfunc_0(Id64 *id, Chain *chain);
};

class Chain {
public:
    char pad00[0x90];
    int count;                  // 0x90
    Handler *handlers[1];       // 0x94
    void FUN_0027dca0();
};

void Chain::FUN_0027dca0()
{
    Id64 id;
    Id64 empty;

    id.FUN_0027af00();
    empty.FUN_0027b0e0(&DAT_003f335c);
    id.FUN_0027af70(&empty);
    empty.FUN_0027af50();

    for (int i = 0; i < count; i++)
        handlers[i]->vfunc_0(&id, this);

    id.FUN_0027af50();
}
