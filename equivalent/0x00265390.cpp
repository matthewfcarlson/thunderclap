// STATUS: equivalent (tools/equiv.py level 3: 124 inputs, branch coverage 30/30)
// FUN_00265390 @ 0x00265390
extern "C" char *strrchr(const char *s, int c);

struct Sink_265390 {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3(const char *name, struct Job_265390 *job);
};
struct Local_265390 {
    char data[0x18];
    void FUN_00231160(int v);
    Sink_265390 *FUN_00231180(long long v);
};
struct Job_265390 {
    virtual void vfn0();
    virtual void vfn1();
    int FUN_00266710();
    void FUN_00266950(int v);
    const char *FUN_002666d0();
};
struct Entry_265390 {
    Job_265390 *job;
    int arg;
};
long long FUN_00267340(const char *s, int a, int b);
void FUN_00266da0(int v);

class Queue_265390 {
public:
    char pad0;
    char stop;                // 0x1
    char pad1[6];
    Job_265390 *current;             // 0x8
    int fc;
    char pad2[4];
    Entry_265390 *head;              // 0x14
    Entry_265390 *tail;              // 0x18
    Entry_265390 *begin;             // 0x1c
    Entry_265390 *end;               // 0x20
    char pad3[4];
    int *ringHead;            // 0x28
    int *ringTail;            // 0x2c
    int *ringBegin;           // 0x30
    int *ringEnd;             // 0x34
    void FUN_00264d20();
    void FUN_00265390();
};

void Queue_265390::FUN_00265390()
{
    while (!stop) {
        int count;
        if (head > tail)
            count = (int)(tail - begin) + (int)(end - head);
        else
            count = (int)(tail - head);
        if (count == 0) {
            FUN_00264d20();
        } else {
            Job_265390 *job = head->job;
            int arg = head->arg;
            if (tail >= end)
                tail = head;
            head = head + 1;
            if (head == end)
                head = begin;
            if (arg != 0) {
                if (ringTail < ringEnd) {
                    if (ringTail)
                        *ringTail = arg;
                    ringTail = ringTail + 1;
                    if (ringTail == ringEnd)
                        ringTail = ringBegin;
                    if (ringHead == ringTail)
                        ringTail = ringTail + (ringEnd - ringBegin);
                }
            }
            if (job != 0) {
                current = job;
                if (job->FUN_00266710() != 4) {
                    current->FUN_00266950(2);
                    const char *ext = strrchr(job->FUN_002666d0(), '.');
                    long long key = FUN_00267340(ext + 1, 0, 0);
                    Local_265390 local;
                    local.FUN_00231160(fc);
                    Sink_265390 *sink = local.FUN_00231180(key);
                    FUN_00266da0(*(int *)((const char *)job->FUN_002666d0() + 0x108));
                    sink->vfn3(job->FUN_002666d0(), job);
                    if (current->FUN_00266710() == 2)
                        current->FUN_00266950(3);
                }
                if (current->FUN_00266710() == 4)
                    current->FUN_00266950(3);
                current->vfn1();
                current = 0;
            }
        }
    }
}
