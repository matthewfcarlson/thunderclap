typedef unsigned char u8;
struct Obj {
    char pad[0x10];
    u8 flag10;
    char pad11;
    u8 flag12;
    char pad13;
    float value;
    bool Target();
};
extern const float threshold;
bool Obj::Target() {
    if (flag12)
        return true;
    if (!(value < threshold) && !flag10)
        return false;
    return true;
}