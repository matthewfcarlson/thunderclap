struct Obj { char pad[0x81c]; int result; int Query(); };
struct S { char pad[4]; int value; Obj* obj; void run(); };
void S::run() {
    int r;
    int x;
    do {
        r = obj->Query();
        x = obj->result;
        value = x;
        if (r != 0) return;
    } while (x == 0);
}