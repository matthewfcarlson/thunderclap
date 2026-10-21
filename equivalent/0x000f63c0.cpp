// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_000f63c0 @ 0x000f63c0
struct Device {
    void FUN_00284820(int value);
    int FUN_002843a0(int first, int second);
    void FUN_00284860(int result, int zero, void *out);
};
struct Object {
    Device *device;
    int unknown4;
    int first;
    int second;
    void FUN_000f63c0(unsigned int *out);
};
void Object::FUN_000f63c0(unsigned int *out) {
    unsigned int values[16];
    device->FUN_00284820(0);
    int result = device->FUN_002843a0(first, second);
    device->FUN_00284860(result, 0, values);
    for (int i = 0; i < 16; ++i) out[i] = values[i];
}