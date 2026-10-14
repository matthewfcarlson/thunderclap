// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 57/58, incomplete)
// FUN_000de1f0 @ 0x000de1f0
extern "C" int strcmp(const char *a, const char *b);
extern "C" char *strcpy(char *dst, const char *src);

extern char DAT_004de768[];
extern char DAT_004de7a8[];

class Item_de1f0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual const char *Name();
    virtual const char *Label();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual float Value(int axis);
};

class Device_de1f0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual bool IsReady();
    virtual void v4(); virtual void v5();
    virtual const char *Name();
    virtual unsigned int ItemCount();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual Item_de1f0 *GetItem(unsigned int index);
};

class DeviceManager_de1f0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual int Count();
    virtual Device_de1f0 *Get(int index);
};

DeviceManager_de1f0 *FUN_002684b0();

void __stdcall FUN_000de1f0(bool analog)
{
    for (int i = 0; i < FUN_002684b0()->Count(); i++) {
        Device_de1f0 *dev = FUN_002684b0()->Get(i);
        if (dev == 0 || !dev->IsReady())
            continue;
        for (unsigned int j = 0; j < dev->ItemCount(); j++) {
            Item_de1f0 *item = dev->GetItem(j);
            if (item == 0)
                continue;
            if (!analog) {
                if (strcmp(item->Label(), "Button") != 0 && strcmp(item->Label(), "AnalogButton") != 0)
                    continue;
                if (strcmp(item->Name(), "Start") != 0 && strcmp(item->Name(), "Menu") != 0
                    && strcmp(item->Name(), "AnalogX") != 0 && strcmp(item->Name(), "A") != 0
                    && strcmp(item->Name(), "AnalogA") != 0)
                    continue;
                if (item->Value(0) > 0.2f) {
                    strcpy(DAT_004de7a8, dev->Name());
                    break;
                }
            } else {
                if (strcmp(item->Label(), "Button") != 0 && strcmp(item->Label(), "XAxis") != 0)
                    continue;
                if (strcmp(item->Name(), "AnalogDPadLeft") != 0 && strcmp(item->Name(), "AnalogDPadRight") != 0
                    && strcmp(item->Name(), "DPadLeft") != 0 && strcmp(item->Name(), "DPadRight") != 0
                    && strcmp(item->Name(), "LeftStickX") != 0 && strcmp(item->Name(), "RightStickX") != 0
                    && strcmp(item->Name(), "AnalogA") != 0)
                    continue;
                if (item->Value(0) > 0.2f || item->Value(0) < -0.2f) {
                    strcpy(DAT_004de768, dev->Name());
                    break;
                }
            }
        }
    }
}
