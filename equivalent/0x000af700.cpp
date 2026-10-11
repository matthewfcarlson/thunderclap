// STATUS: equivalent (tools/equiv.py level 3: 109 inputs, branch coverage 19/22, incomplete)
// FUN_000af700 @ 0x000af700
extern "C" int strcmp(const char *a, const char *b);

class Info {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const char *v4();
};
class Device {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual unsigned int v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual Info *v16(unsigned int i);
};

struct Record {
    unsigned int count;
    int kind[2];
    int state[2];
    char pad14[0x18];
    Device *device;
};

class Controller {
public:
    char pad0[0x14];
    Record *records;
    void FUN_000af530(int index, unsigned int port, int flag);
    void FUN_000af700(int index, Device *dev);
};

void Controller::FUN_000af700(int index, Device *dev)
{
    if (dev == records[index].device)
        return;
    if (dev)
        dev->v0();
    if (records[index].device)
        records[index].device->v1();
    records[index].device = dev;
    if (records[index].device) {
        records[index].count = records[index].device->v12();
        if (records[index].count > 2)
            records[index].count = 2;
        for (unsigned int i = 0; i < records[index].count; i++) {
            Info *info = records[index].device->v16(i);
            info->v3();
            const char *name = info->v4();
            if (strcmp(name, "Analog") == 0)
                records[index].kind[i] = 1;
            else if (strcmp(name, "Digital") == 0)
                records[index].kind[i] = 2;
            else
                records[index].kind[i] = 0;
            records[index].state[i] = 0;
            FUN_000af530(index, i, 0);
        }
    } else {
        records[index].count = 0;
        for (unsigned int i = 0; i < records[index].count; i++) {
            records[index].kind[i] = 0;
            records[index].state[i] = 0;
        }
    }
}
