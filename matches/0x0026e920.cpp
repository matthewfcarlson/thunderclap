struct Event_26e920 {
    int kind;
    int value;
    unsigned char a, b, c;
    char unused[16];
};
struct Obj_26e920 {
    char pad[0xa0];
    int active;
    void FUN_0026e240(Event_26e920*);
    void FUN_0026e920(int value, unsigned char a, unsigned char b, unsigned char c);
};
void Obj_26e920::FUN_0026e920(int value, unsigned char a, unsigned char b, unsigned char c) {
    if (active) {
        Event_26e920 event;
        event.kind = 1;
        event.value = value;
        event.a = a;
        event.b = b;
        event.c = c;
        FUN_0026e240(&event);
    }
}