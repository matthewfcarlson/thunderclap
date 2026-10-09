class Item {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual char Match(int, int, int);
    Item* next;
    int type;
};
class Owner {
  public:
    Item* head;
    char Run(int, int, int);
};
char Owner::Run(int a, int b, int c) {
    Item* n = head;
    bool active = true;
    bool invert = false;
    char result = 1;
    if (n) {
        do {
            int t = n->type;
            switch (t) {
            case 0:
                if (!result) {
                    if (active)
                        return 0;
                } else if (!active)
                    return 1;
                result = n->Match(a, b, c);
                if (invert)
                    result = (result == 0);
                active = true;
                invert = false;
                break;
            case 1:
                active = false;
                break;
            case 2:
                invert = !invert;
                break;
            }
            n = n->next;
        } while (n);
    }
    return result;
}