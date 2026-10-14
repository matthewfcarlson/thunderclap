// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_0019b460 @ 0x0019b460
// hulkfight::motion::ProjectileMissile::~ProjectileMissile body @ 0x0019b460
// equiv-map: ??1CProjectile@@UAE@XZ = 0x001b6820
struct Id64 {
    int lo;
    int hi;
};

struct MissileCfg {
    char pad0[0x20];
    Id64 id;                // 0x20
};

class RefObj {
public:
    virtual void v0();
    virtual void Release();
};

struct Factory {
    bool FUN_001dd800(int handle);
    int FUN_001e3020(int handle, int lo, int hi);
    int FUN_001dc290(int handle);
    void FUN_001e5bc0(int handle);
};

struct World {
    char pad0[0xc];
    Factory *factory;       // 0xc
};

struct Pool {
    void FUN_002834e0(int v);
};

extern World *DAT_004dd700;
Pool *FUN_0027f250();

class CProjectile {
public:
    virtual ~CProjectile() throw();
    char pad04[0x3c - 4];
};

namespace hulkfight {
namespace motion {

class ProjectileMissile : public CProjectile {
public:
    virtual ~ProjectileMissile() throw();
    MissileCfg *cfg;        // 0x3c
    int handle;             // 0x40
    char pad44[0xc];
    RefObj *owner;          // 0x50
    char pad54[0xa0 - 0x54];
    int fa0;
};

ProjectileMissile::~ProjectileMissile() throw()
{
    if (owner)
        owner->Release();
    owner = 0;

    Pool *pool = FUN_0027f250();
    pool->FUN_002834e0(fa0);

    Factory *factory = DAT_004dd700->factory;
    bool keep = false;
    if (factory->FUN_001dd800(handle)) {
        int lo = cfg->id.lo;
        int hi = cfg->id.hi;
        if ((lo | hi) != 0) {
            int found = factory->FUN_001e3020(handle, lo, hi);
            int current = factory->FUN_001dc290(handle);
            keep = (found >= 0 && current == found);
        }
    }
    if (!keep)
        factory->FUN_001e5bc0(handle);

    cfg = 0;
}

}
}
