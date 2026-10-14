class Manager_89e80 {
  public:
    int Get();
    void Set(int);
};
class Obj_89e80 {
    char pad[0xabd];

  public:
    char flag;
    char other;
    void Init();
    char Fn(Manager_89e80*, char);
};
char Obj_89e80::Fn(Manager_89e80* m, char param) {
    Init();
    char r = 0;
    int x = m->Get();
    if (x == 2) {
        flag = 0;
        r = 1;
    } else if (x == 5) {
        flag = 1;
        r = 1;
    } else if (x == 3) {
        flag = (other == 0);
        m->Set(4);
    }
    x = m->Get();
    if (x == 4 && param)
        return 1;
    return r;
}