extern void __cdecl FuncA(void*);
extern void __cdecl FuncB(void*);
class Target {
  public:
    void* p;
    void run();
};
void Target::run() {
    void* q = p;
    if (q)
        FuncA(q);
    q = *(void* volatile*)&p;
    if (q)
        FuncB(q);
}