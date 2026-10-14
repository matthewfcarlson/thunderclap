struct Obj_337980 {
    char pad[0x81c];
    int result;
    int Query();
};
struct S_337980 {
    char pad[4];
    int value;
    Obj_337980* obj;
    void run();
};
void S_337980::run() {
    int r;
    int x;
    do {
        r = obj->Query();
        x = obj->result;
        value = x;
        if (r != 0)
            return;
    } while (x == 0);
}