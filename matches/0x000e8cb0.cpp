class Worker { public: void run(int, int, int); };
class FELayout { char pad[0x44]; };
class SingleLayout : public FELayout { public: Worker* worker; void vfunc_10(int); };
void SingleLayout::vfunc_10(int param) {
    Worker* p = worker;
    if (p) p->run(param, -1, -1);
}