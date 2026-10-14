typedef unsigned char u8;
struct Caller_1c68c0 {
    void method(int);
};
struct Obj_1c68c0 {
    char pad[8];
    u8 enabled;
    char pad9[7];
    int value;
    void target(Caller_1c68c0* arg);
};
void Obj_1c68c0::target(Caller_1c68c0* arg) {
    if (enabled && value)
        arg->method(value);
}