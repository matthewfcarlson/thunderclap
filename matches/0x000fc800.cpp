typedef unsigned char u8;
struct Obj_fc800 {
    char pad[0x10];
    u8 flag10;
    char pad11;
    u8 flag12;
    char pad13;
    float value;
    bool Target();
};
extern const float threshold_fc800;
bool Obj_fc800::Target() {
    if (flag12)
        return true;
    if (!(value < threshold_fc800) && !flag10)
        return false;
    return true;
}