// Same code shape as 0x0025c000 (propagated; names are from that function)
extern "C" bool __cdecl Check(void*, void*);
class Target {
  public:
    int value;
    int Run(void* p);
};
int Target::Run(void* p) {
    if (Check(p, this) && Check(p, (char*)this + 4))
        return 1;
    return 0;
}