extern "C" int strcmp(const char*, const char*);
class Manager {
  public:
    void Do(int);
};
class Obj {
  public:
    char pad[0xabe];
    unsigned char flag;
    char pad2[1];
    Manager* mgr;
    void Target(const char*);
    void Prepare();
};
void Obj::Target(const char* s) {
    Prepare();
    int a = strcmp(s, "story");
    if (a == 0) {
        flag = 1;
        mgr->Do(2);
        return;
    }
    int b = strcmp(s, "oneshot");
    if (b == 0)
        flag = (unsigned char)b;
    mgr->Do(2);
}