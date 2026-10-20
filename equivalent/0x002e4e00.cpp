// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 6/6)
// FUN_002e4e00 @ 0x002e4e00
struct Resource { virtual void unused(); virtual void release(); };
struct Controller {
    char pad[8];
    Resource* resource;
    bool FUN_002e4bd0(int second, int third);
    void FUN_002e3bd0(int first, int second, int third, int fourth);
    void FUN_002e30f0(int first, int second, int third, int fourth);
    void FUN_002e4e00(int first, int second, int third, int fourth, char flag);
};
void Controller::FUN_002e4e00(int first, int second, int third, int fourth, char flag) {
    if (FUN_002e4bd0(second, third)) {
        if (flag) FUN_002e30f0(first, second, third, fourth);
        else FUN_002e3bd0(first, second, third, fourth);
        if (resource) {
            resource->release();
            resource = 0;
        }
    }
}