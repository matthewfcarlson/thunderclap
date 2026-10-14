class Inner_1c3c20 {
  public:
    char pad[0xcc];
    char flag;
};
class Helper_1c3c20 {
  public:
    void Stop();
};
class Obj_1c3c20 {
  public:
    Inner_1c3c20* volatile p;
    Helper_1c3c20* h;
    void Set(char value);
};
void Obj_1c3c20::Set(char value) {
    if (p->flag) {
        if (value == 0)
            h->Stop();
        p->flag = value;
    } else {
        p->flag = value;
    }
}