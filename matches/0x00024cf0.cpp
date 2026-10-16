struct Result {
    char pad[0x1ac];
    int value;
};
struct Manager {
    Result* Get(unsigned int, unsigned int);
};
struct Host {
    char pad[4];
    Manager* mgr;
    void Fn(int, int);
};
extern "C" unsigned __int64 __cdecl Lookup(int);
void Host::Fn(int a, int b) {
    Manager* m = mgr;
    unsigned __int64 v = Lookup(a);
    Result* r = m->Get((unsigned int)v, (unsigned int)(v >> 32));
    r->value = b;
}