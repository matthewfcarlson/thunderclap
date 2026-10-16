// STATUS: equivalent (tools/equiv.py level 3: 12141 inputs, branch coverage 120/120)
// FUN_00044cb0 @ 0x00044cb0
extern "C" int strcmp(const char *, const char *);
int FUN_00096600(const char *a, const char *b);

struct Agent {
    char pad0[0x32c];
    float fDesiredMinEngage;
    float fDesiredMaxEngage;
    float fAbsoluteMinEngage;
    float fAbsoluteMaxEngage;
    float fMaxAttack;
    float fHearingRadius;
    float fNoisiness;
    float fSightRadius;
    float fSightFOV;
    char pad350[0xc];
    float fDodgingSkill;
    float fMinAttackPeriod;
    float fMinTauntPeriod;
    float fMinAttackPause;
    float fMaxAttackPause;
    float fTargetPerceptionLag;
    float fChasePersistenceTime;
    float fSuspiciousTime;
    char fNoGolem;
    char fFightingNPCMode;
    char fSuckInProp;
    char fGroupManaged;
    char pad380[0x4];
    char fIgnoreFriendlyFire;
    char pad385[0x3];
    float fSpeedSleepwalking;
    char fRangedAgent;
    char fHand2HandAgent;
    char fChaseAgent;
    char fPathGraphAgent;
    char fOccupationAgent;
    char pad391[0x1f];
    char nameB[0x40];
    char nameA[0x40];
    char pad430[0x8];
    float fAvoidTolerance;
    float fAvoidRadius;
    char pad440[0x20];
    float fPatrolPathBreakOffHealth;
    float fPatrolPathBreakOffDistance;
    float fPatrolPathBreakOffReset;
};

struct AgentList {
    char pad0[0xc];
    int count;
    Agent **items;
};

struct Middle {
    char pad0[4];
    AgentList *agents;
};

struct Root {
    char pad0[0x20];
    Middle *middle;
};

extern Root *DAT_004dd700;

// equiv-dead: +0x57 taken, +0x5b taken: the inlined bounds check of items[i] runs with 0 <= i < count (i starts at 0, count is re-read into eax just before the loop compare, nothing changes it before the check)
// Applies one tuning property (key, value) to every agent whose name matches the category.
void FUN_00044cb0(const char *category, const char *key, float value)
{
    if (!category || !*category)
        return;
    if (!key || !*key)
        return;
    AgentList *list = DAT_004dd700->middle->agents;
    for (int i = 0; i < list->count; i++) {
        Agent *a = (i >= 0 && i < list->count) ? list->items[i] : 0;
        if (strcmp(a->nameA, category) != 0 && strcmp(a->nameB, category) != 0)
            continue;
        if (FUN_00096600(key, "DesiredMinEngage") == 0)
            a->fDesiredMinEngage = value;
        else if (FUN_00096600(key, "DesiredMaxEngage") == 0)
            a->fDesiredMaxEngage = value;
        else if (FUN_00096600(key, "AbsoluteMinEngage") == 0)
            a->fAbsoluteMinEngage = value;
        else if (FUN_00096600(key, "AbsoluteMaxEngage") == 0)
            a->fAbsoluteMaxEngage = value;
        else if (FUN_00096600(key, "MaxAttack") == 0)
            a->fMaxAttack = value;
        else if (FUN_00096600(key, "HearingRadius") == 0)
            a->fHearingRadius = value;
        else if (FUN_00096600(key, "Noisiness") == 0)
            a->fNoisiness = value;
        else if (FUN_00096600(key, "SightRadius") == 0)
            a->fSightRadius = value;
        else if (FUN_00096600(key, "AvoidTolerance") == 0)
            a->fAvoidTolerance = value;
        else if (FUN_00096600(key, "AvoidRadius") == 0)
            a->fAvoidRadius = value;
        else if (FUN_00096600(key, "PatrolPathBreakOffHealth") == 0)
            a->fPatrolPathBreakOffHealth = value;
        else if (FUN_00096600(key, "PatrolPathBreakOffDistance") == 0)
            a->fPatrolPathBreakOffDistance = value;
        else if (FUN_00096600(key, "PatrolPathBreakOffReset") == 0)
            a->fPatrolPathBreakOffReset = value;
        else if (FUN_00096600(key, "SightFOV") == 0)
            a->fSightFOV = value;
        else if (FUN_00096600(key, "DodgingSkill") == 0)
            a->fDodgingSkill = value;
        else if (FUN_00096600(key, "MinAttackPeriod") == 0)
            a->fMinAttackPeriod = value;
        else if (FUN_00096600(key, "MinTauntPeriod") == 0)
            a->fMinTauntPeriod = value;
        else if (FUN_00096600(key, "MinAttackPause") == 0)
            a->fMinAttackPause = value;
        else if (FUN_00096600(key, "MaxAttackPause") == 0)
            a->fMaxAttackPause = value;
        else if (FUN_00096600(key, "TargetPerceptionLag") == 0)
            a->fTargetPerceptionLag = value;
        else if (FUN_00096600(key, "ChasePersistenceTime") == 0)
            a->fChasePersistenceTime = value;
        else if (FUN_00096600(key, "SuspiciousTime") == 0)
            a->fSuspiciousTime = value;
        else if (FUN_00096600(key, "NoGolem") == 0)
            a->fNoGolem = !(value <= 0.0f);
        else if (FUN_00096600(key, "FightingNPCMode") == 0)
            a->fFightingNPCMode = !(value <= 0.0f);
        else if (FUN_00096600(key, "SuckInProp") == 0)
            a->fSuckInProp = !(value <= 0.0f);
        else if (FUN_00096600(key, "GroupManaged") == 0)
            a->fGroupManaged = !(value <= 0.0f);
        else if (FUN_00096600(key, "IgnoreFriendlyFire") == 0)
            a->fIgnoreFriendlyFire = !(value <= 0.0f);
        else if (FUN_00096600(key, "SpeedSleepwalking") == 0)
            a->fSpeedSleepwalking = value;
        else if (FUN_00096600(key, "OccupationAgent") == 0)
            a->fOccupationAgent = !(value <= 0.0f);
        else if (FUN_00096600(key, "Hand2HandAgent") == 0)
            a->fHand2HandAgent = !(value <= 0.0f);
        else if (FUN_00096600(key, "RangedAgent") == 0)
            a->fRangedAgent = !(value <= 0.0f);
        else if (FUN_00096600(key, "PathGraphAgent") == 0)
            a->fPathGraphAgent = !(value <= 0.0f);
        else if (FUN_00096600(key, "ChaseAgent") == 0)
            a->fChaseAgent = !(value <= 0.0f);
    }
}
