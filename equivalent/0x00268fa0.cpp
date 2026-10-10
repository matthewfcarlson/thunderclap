// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00268fa0 @ 0x00268fa0
namespace core {
struct ControllerInputPointXBox {
    virtual void dummy();
    int values[3];
    float scale;
    int rest[8];
};
struct ControllerOutputPointXBox {
    virtual void dummy();
    int values[3];
};
struct ControllerXBox {
    virtual void dummy();
    int values[5];
    ControllerInputPointXBox inputs[20];
    ControllerOutputPointXBox outputs[2];
    char reserved[0x56];
    char active;
    ControllerXBox();
};
ControllerXBox::ControllerXBox() {
    for (int i = 0; i < 5; ++i) values[i] = 0;
    for (int j = 0; j < 20; ++j) {
        for (int k = 0; k < 3; ++k) inputs[j].values[k] = 0;
        inputs[j].scale = 1.0f;
        for (int k = 0; k < 8; ++k) inputs[j].rest[k] = 0;
    }
    for (int j = 0; j < 2; ++j)
        for (int k = 0; k < 3; ++k) outputs[j].values[k] = 0;
    active = 0;
}
}