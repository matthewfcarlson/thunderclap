// STATUS: equivalent (tools/equiv.py level 3: 19124 inputs, branch coverage 67/68, incomplete)
// FUN_0002ab40 @ 0x0002ab40
// FUN_0002ab40 @ 0x0002ab40
extern "C" double sqrt(double);

struct Vec3_2ab40 {
    float x, y, z;
    float FUN_0022d110();
};

class Selector_2ab40 {
public:
    int FUN_000fdc80();
    int FUN_000fdc40();
    char pad0[0xe8];
    char armed;
};

class Agent_2ab40 {
public:
    void FUN_000363f0(int a0, float v);
    void FUN_00036430(int a0, float v);
    void FUN_0003b7d0(int a0, float v);
    void FUN_00040970(int a0, float v);
    void FUN_0003e2a0(int a0, Vec3_2ab40 dir, int a1, float v, unsigned int flags);
    void FUN_00042930(int a0, float v);
    int FUN_00035660(Vec3_2ab40 *out);

    char pad0[0x1ca0];
    Selector_2ab40 *selector;
    char pad1[0x1cf0 - 0x1ca4];
    float gain;
    char pad2[0x2064 - 0x1cf4];
    float dirX;
    float dirY;
    float dirZ;
    float dirScale;
    char pad3[0x2140 - 0x2074];
    char forced;
};

class Lookup_2ab40 {
public:
    Agent_2ab40 *FUN_00059c10(int id);
};

struct Registry_2ab40 {
    char pad0[0x44];
    Lookup_2ab40 *lookup;
};

class AgentSet {
public:
    void FUN_0002ab40(int a0, int a1);
    void FUN_0002a960(int a0);
    void FUN_00025ff0(int a0, int a1);

    Registry_2ab40 *registry;
    char pad0[8];
    int count;
    int ids[16];
    char pad2[4];
    unsigned int flags[16];
    float args[16];
    char pad1[0xe0 - 0xd4];
    int modes[16];
};

void AgentSet::FUN_0002ab40(int a0, int a1)
{
    FUN_0002a960(a0);
    FUN_00025ff0(a0, a1);
    for (int i = 0; i < count; i++) {
        if ((flags[i] & 1) || modes[i] != 0) {
            Agent_2ab40 *agent = registry->lookup->FUN_00059c10(ids[i]);
            if (agent)
                agent->FUN_000363f0(a0, args[i]);
        }
    }
    for (int i = 0; i < count; i++) {
        if ((flags[i] & 1) || modes[i] != 0) {
            Agent_2ab40 *agent = registry->lookup->FUN_00059c10(ids[i]);
            if (agent)
                agent->FUN_00036430(a0, args[i]);
        }
    }
    for (int i = 0; i < count; i++) {
        if ((flags[i] & 1) || modes[i] != 0) {
            Agent_2ab40 *agent = registry->lookup->FUN_00059c10(ids[i]);
            if (agent)
                agent->FUN_0003b7d0(a0, args[i]);
        }
    }
    for (int i = 0; i < count; i++) {
        Agent_2ab40 *agent = registry->lookup->FUN_00059c10(ids[i]);
        if ((flags[i] & 1) && modes[i] == 0) {
            if (agent)
                agent->FUN_00040970(a0, args[i]);
        } else if (agent) {
            Vec3_2ab40 dir;
            dir.x = 0;
            dir.y = 0;
            dir.z = 0;
            if (modes[i] == 0) {
                agent->FUN_00035660(&dir);
                if (sqrt(dir.z * dir.z + dir.y * dir.y + dir.x * dir.x) > 50.0f) {
                    dir.FUN_0022d110();
                    dir.x = dir.x * 50.0f;
                    dir.y = dir.y * 50.0f;
                    dir.z = dir.z * 50.0f;
                }
            } else if (modes[i] == 1) {
                Selector_2ab40 *sel = agent->selector;
                if (sel) {
                    char armed = sel->armed;
                    int current = sel->FUN_000fdc80();
                    int found = sel->FUN_000fdc40();
                    if (agent->forced || (current != 0 && current == found && armed)) {
                        // x uses the unrounded product, y and z the value rounded to float.
                        volatile float s;
                        dir.x = agent->dirX * (agent->gain * agent->dirScale);
                        s = agent->gain * agent->dirScale;
                        dir.y = agent->dirY * s;
                        dir.z = agent->dirZ * s;
                    }
                }
            }
            agent->FUN_0003e2a0(a0, dir, a1, args[i], (flags[i] >> 1) & 0xffffff01u);
        }
    }
    for (int i = 0; i < count; i++) {
        if ((flags[i] & 1) && modes[i] == 0) {
            Agent_2ab40 *agent = registry->lookup->FUN_00059c10(ids[i]);
            if (agent)
                agent->FUN_00042930(a0, args[i]);
        }
    }
}
