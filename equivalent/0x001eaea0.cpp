// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 31/34, incomplete)
// FUN_001eaea0 @ 0x001eaea0
struct Ref_1eaea0 {
    char pad0[0xc];
    int refs;
};

struct Slot_1eaea0 {
    virtual void v0();
    virtual void v1();
    virtual void Destroy(int flag);
    char pad04[0x24 - 4];
    int users;
    char pad28[0x2c - 0x28];
    Ref_1eaea0 *refs[64];
    int refCount;
    void FUN_001eadf0();
};

struct Handle_1eaea0 {
    int state;
    void FUN_001ea700();
};

struct Timer {
    char pad0[0x34];
    int pending;
};

struct Job_1eaea0 {
    virtual void v0();
    virtual void v1();
    virtual void Destroy(int flag);
    char pad04[0xc - 4];
    Timer *timer;
};

struct Sync {
    char FUN_00266750();
    void FUN_00263e90();
};

struct Pool_1eaea0 {
    void FUN_002665a0();
};

extern Sync *DAT_004e3694;
extern int DAT_004e3698;
extern int DAT_004e36ac;

void FUN_00241280(int a, int b, int c);
void *FUN_00240750();
void FUN_002416c0(void *a, Timer *t, int c);
void FUN_00243090(void *a, float step);
void FUN_00242ca0(void *a, Timer **t);
void FUN_0008d330(void *p);

class Manager_1eaea0 {
public:
    char pad0[8];
    Slot_1eaea0 *slots[100];
    int slotCount;
    Handle_1eaea0 *handles[200];
    int handleCount;
    Job_1eaea0 *jobs[20];
    int jobCount;
    int f514;
    Pool_1eaea0 *pool;
    char pad51c[4];
    char f520;

    void FUN_001eaea0();
};

void Manager_1eaea0::FUN_001eaea0()
{
    FUN_00241280(0, 0, 0);

    for (int i = 0; i < slotCount; i++) {
        Slot_1eaea0 *s = slots[i];
        if (s->users > 0) {
            if (s->refCount > 0) {
                int j = 0;
                do {
                    if (s->refs[j])
                        s->refs[j]->refs--;
                    j++;
                } while (j < s->refCount);
            }
            s->users--;
        }
        slots[i]->FUN_001eadf0();
        if (slots[i])
            slots[i]->Destroy(1);
        slots[i] = 0;
    }

    int n = handleCount;
    slotCount = 0;
    for (int i = 0; i < n; i++) {
        if (handles[i]) {
            handles[i]->FUN_001ea700();
            Handle_1eaea0 *h = handles[i];
            if (h->state == 1) {
                if (DAT_004e3694->FUN_00266750()) {
                    h->state = 3;
                    DAT_004e3694->FUN_00263e90();
                    DAT_004e3694 = 0;
                }
            }
            FUN_0008d330(handles[i]);
            handles[i] = 0;
        }
        n = handleCount;
    }

    n = jobCount;
    handleCount = 0;
    for (int i = 0; i < n; i++) {
        Job_1eaea0 *job = jobs[i];
        void *mgr = FUN_00240750();
        FUN_002416c0(mgr, job->timer, 0);
        while (job->timer->pending != 0)
            FUN_00243090(FUN_00240750(), 0.001f);
        FUN_00242ca0(FUN_00240750(), &job->timer);
        if (jobs[i])
            jobs[i]->Destroy(1);
        jobs[i] = 0;
        n = jobCount;
    }

    jobCount = 0;
    DAT_004e3698 = 0;
    f514 = 0;
    pool->FUN_002665a0();
    f520 = 0;
    DAT_004e36ac = 0;
}
