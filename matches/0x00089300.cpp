extern "C" int strcmp(const char*, const char*);
class Manager_89300 {
  public:
    void Do(int);
};
class Obj_89300 {
  public:
    char pad[0xabe];
    unsigned char flag;
    char pad2[1];
    Manager_89300* mgr;
    void Target(const char*);
    void Prepare();
};
void Obj_89300::Target(const char* s) {
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