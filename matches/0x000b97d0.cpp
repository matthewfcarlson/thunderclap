class Actor {
  public:
    void A();
    void B(int);
};
class State {
  public:
    char pad0[0x10];
    int state;
    char pad14[0x20];
    Actor* a;
    Actor* b;
    void Target();
};
struct Manager {
    char pad[0x2218];
    void* item;
    int value;
};
struct Item {
    char pad[0x9a8];
    char busy;
};
extern Manager* GetManager();
extern void __cdecl Finish();
void State::Target() {
    if (state == 0x15) {
        Manager* m = GetManager();
        if (m->item == 0 || !((Item*)m->item)->busy) {
            state = 9;
            m = GetManager();
            if (m->value == 1 && state != 3) {
                a->A();
                if (b)
                    b->B(5);
                Finish();
            }
        }
    }
}