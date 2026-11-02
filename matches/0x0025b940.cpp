extern "C" void __cdecl FUN_0025b7d0(void *);
extern void __cdecl FuncB(void*);
class Target_25b940 {
  public:
    void* p;
    void run();
};
void Target_25b940::run() {
    void* q = p;
    if (q)
        FUN_0025b7d0(q);
    q = *(void* volatile*)&p;
    if (q)
        FuncB(q);
}