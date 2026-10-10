// STATUS: equivalent (tools/equiv.py level 3: 63 inputs, branch coverage 22/22)
// FUN_001af770 @ 0x001af770
struct Vec3 {
    float x, y, z;
};
struct Vec6 {
    Vec3 a, b;
};
struct Job {
    unsigned char kind;
    unsigned char started;
    char pad02[2];
    Vec3 f04;
    Vec3 f10;
    Vec3 f1c;
    int f28;
    int f2c;
    Vec6 f30;
    Vec3 f48;
    int f54;
    int result;
    int f5c;
};
class JobQueue {
  public:
    char pad00[0x18];
    Job** head;
    Job** tail;
    Job** begin;
    Job** end;
    int FUN_001af650(Vec3* a, Vec3* b, Vec3* c, int d, int e, Vec6* f, Vec3* g, int* h, int i);
    void FUN_001af770();
};
void JobQueue::FUN_001af770() {
    int count;
    if (head > tail)
        count = (tail - begin) + (end - head);
    else
        count = tail - head;
    bool started = false;
    for (int i = 0; i < count; i++) {
        if (started)
            break;
        Job* job = *head;
        if (!(tail < end))
            tail = head;
        head = head + 1;
        if (head == end)
            head = begin;
        if (job->kind == 1) {
            job->started = 1;
            job->result = FUN_001af650(&job->f04, &job->f10, &job->f1c, job->f28, job->f2c, &job->f30, &job->f48, &job->f54, job->f5c);
            started = true;
        }
        if (tail < end) {
            if (tail)
                *tail = job;
            tail = tail + 1;
            if (tail == end)
                tail = begin;
            if (head == tail)
                tail = tail + (end - begin);
        }
    }
}
