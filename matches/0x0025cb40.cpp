extern "C" char __cdecl Check(void*, const char*);
extern "C" char __cdecl FUN_00252470(void*, const char*, void*);
struct Node {
    char pad[0x24];
    int count;
};
class Target_25cb40 {
  public:
    char Run(Node**);
};
char Target_25cb40::Run(Node** p) {
    if (Check(*p, "\n[\n")) {
        ++(*p)->count;
        if (FUN_00252470(p, "mMin", this)) {
            if (FUN_00252470(p, "mMax", (char*)this + 4)) {
                --(*p)->count;
                Node* n = *p;
                if (Check(n, "]"))
                    return 1;
            }
        }
    }
    return 0;
}