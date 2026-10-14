// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000d4390 @ 0x000d4390
struct Rec {
    char pad0[0x218];
    float score;
    char pad21c[0x18];
    char active;
    char pad235[7];
};
class Pool {
public:
    char pad0[0x14];
    Rec recs[2];
    Rec* FUN_000d4390();
};
Rec* Pool::FUN_000d4390() {
    int best = -1;
    float bestScore = 0.0f;
    for (int i = 0; i < 2; i++) {
        if (!recs[i].active)
            return &recs[i];
        if (best < 0 || bestScore < recs[i].score) {
            bestScore = recs[i].score;
            best = i;
        }
    }
    recs[best].active = 0;
    return &recs[best];
}
