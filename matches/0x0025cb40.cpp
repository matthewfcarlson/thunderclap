extern "C" char __cdecl Check(void*, const char*);
extern "C" char __cdecl Parse(void*, const char*, void*);
struct Node {
    char pad[0x24];
    int count;
};
class Target {
  public:
    char Run(Node**);
};
char Target::Run(Node** p) {
    if (Check(*p, "\n[\n")) {
        ++(*p)->count;
        if (Parse(p, "mMin", this)) {
            if (Parse(p, "mMax", (char*)this + 4)) {
                --(*p)->count;
                Node* n = *p;
                if (Check(n, "]"))
                    return 1;
            }
        }
    }
    return 0;
}