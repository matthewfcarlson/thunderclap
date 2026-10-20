// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 28/28)
// FUN_00337700 @ 0x00337700
#include "compat/ptr.h"
extern "C" long atol(const char* s);
void* __cdecl FUN_0008d690(hulk_uintptr size);

class AttrDef_337700 {
  public:
    bool FUN_00337210(void* loader);
};

class XmlReader {
  public:
    virtual ~XmlReader();
    XmlReader* FUN_003388d0(void* src, int bufSize);
    bool FUN_003385f0(void* arg);
    void FUN_00338630();
};

class XmlLoader {
  public:
    char pad0[0x5108];
    int status;
    XmlReader* reader;
    const char* FUN_00337460();
    void FUN_003374a0();
    AttrDef_337700* FUN_00337680(const char* name);
    bool Load(void* src, void* arg);
};

static bool Match(const char* text, const char* pattern, int count) {
    for (int i = 0; i < count; ++i) {
        if (text[i] != pattern[i])
            return false;
    }
    return true;
}

bool XmlLoader::Load(void* src, void* arg) {
    if (reader != 0)
        delete reader;
    void* memory = FUN_0008d690(0x874);
    XmlReader* newReader = 0;
    if (memory != 0)
        newReader = ((XmlReader*)memory)->FUN_003388d0(src, 0x2000);
    reader = newReader;
    status = 0;
    if (!newReader->FUN_003385f0(arg)) {
        status = 9;
    } else {
        AttrDef_337700* definition = 0;
        const char* token = FUN_00337460();
        while (token != 0) {
            if (Match(token, "version", 8)) {
                FUN_003374a0();
                const char* value = FUN_00337460();
                if (value == 0)
                    break;
                atol(value);
                FUN_003374a0();
            } else if (token[0] == '[' && token[1] == 0) {
                FUN_003374a0();
                const char* name = FUN_00337460();
                if (name == 0)
                    break;
                definition = FUN_00337680(name);
                if (definition == 0)
                    break;
                FUN_003374a0();
                FUN_003374a0();
            } else if (Match(token, "attrDef", 8)) {
                if (!definition->FUN_00337210(this))
                    break;
            } else {
                status = 4;
                break;
            }
            token = FUN_00337460();
        }
        reader->FUN_00338630();
    }
    return status == 0 || status == 1;
}