class Worker_e8cb0 {
  public:
    void run(int, int, int);
};
class FELayout {
    char pad[0x44];
};
class SingleLayout : public FELayout {
  public:
    Worker_e8cb0* worker;
    void vfunc_10(int);
};
void SingleLayout::vfunc_10(int param) {
    Worker_e8cb0* p = worker;
    if (p)
        p->run(param, -1, -1);
}