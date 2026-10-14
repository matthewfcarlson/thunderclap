// STATUS: equivalent (tools/equiv.py level 3: 936 inputs, branch coverage 2/2)
// FUN_000b77c0 @ 0x000b77c0
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

class Settings {
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual int GetLanguage();
};

struct Lookup {
    char data[0x24];
    void FUN_000f7930();
    void FUN_000f7960();
    void FUN_000f8500(int key, int language, int flag);
    const unsigned short *FUN_000f83f0(int language, int flag);
};

Settings *__cdecl FUN_000fc3d0();
int __cdecl FUN_00294b80(const unsigned short *s);

// Looks the key up in the string table and copies the localised text into buf if it fits.
bool __stdcall FUN_000b77c0(int key, unsigned short *buf, int maxLength, int unused)
{
    Lookup lookup;
    lookup.FUN_000f7930();
    lookup.FUN_000f8500(key, FUN_000fc3d0()->GetLanguage(), 1);
    const unsigned short *text = lookup.FUN_000f83f0(FUN_000fc3d0()->GetLanguage(), 0);
    int length = FUN_00294b80(text);
    if (length > maxLength) {
        lookup.FUN_000f7960();
        return false;
    }
    memcpy(buf, text, (length + 1) * 2);
    lookup.FUN_000f7960();
    return true;
}
