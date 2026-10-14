extern "C" bool __cdecl Check(void*, void*);
class Target_25c000 {
  public:
    int value;
    int Run(void* p);
};
int Target_25c000::Run(void* p) {
    if (Check(p, this) && Check(p, (char*)this + 4))
        return 1;
    return 0;
}