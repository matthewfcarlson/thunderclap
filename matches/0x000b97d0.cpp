class Actor_b97d0 {
  public:
    void A();
    void B(int);
};
class State_b97d0 {
  public:
    char pad0[0x10];
    int state;
    char pad14[0x20];
    Actor_b97d0* a;
    Actor_b97d0* b;
    void Target();
};
struct Manager_b97d0 {
    char pad[0x2218];
    void* item;
    int value;
};
struct Item_b97d0 {
    char pad[0x9a8];
    char busy;
};
extern Manager_b97d0* FUN_000fc3d0();
extern void __cdecl FUN_000fc300();
void State_b97d0::Target() {
    if (state == 0x15) {
        Manager_b97d0* m = FUN_000fc3d0();
        if (m->item == 0 || !((Item_b97d0*)m->item)->busy) {
            state = 9;
            m = FUN_000fc3d0();
            if (m->value == 1 && state != 3) {
                a->A();
                if (b)
                    b->B(5);
                FUN_000fc300();
            }
        }
    }
}