#include "decls/data/engine/unknown.h"

extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
int __cdecl FUN_00345b90(int);
void __cdecl FUN_0026d850(void*);
void __cdecl FUN_0026d840(void*);
int __cdecl FUN_00270c10(const char*);
unsigned char __cdecl FUN_002771b0(const char*);
struct Receiver_270d40 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21(const char*);
};
struct Entry_270d40 {
    char name[17];
    char pad[3];
    Receiver_270d40* receiver;
    char path[256];
    char tail[4];
};
void __cdecl FUN_00270d40(const char* name, const char* path) {
    char lower[20];
    strncpy(lower, name, 16);
    lower[16] = 0;
    for (char* p = lower; *p; ++p)
        *p = (char)FUN_00345b90((signed char)*p);
    FUN_0026d850(((char*)((char*)&DAT_0052842c + 7364)));
    int index = FUN_00270c10(lower);
    if (index == -1) {
        if (FUN_002771b0(lower) && (*(unsigned int*)&DAT_0052a128) < 26) {
            Entry_270d40& entry = ((Entry_270d40*)&DAT_00528418)[(*(unsigned int*)&DAT_0052a128)];
            strncpy(entry.name, lower, 16);
            entry.name[16] = 0;
            strncpy(entry.path, path, 256);
            ++(*(unsigned int*)&DAT_0052a128);
            FUN_0026d840(((char*)((char*)&DAT_0052842c + 7364)));
        }
    } else {
        Entry_270d40& entry = ((Entry_270d40*)&DAT_00528418)[index];
        strncpy(entry.path, path, 256);
        Receiver_270d40* receiver = entry.receiver;
        FUN_0026d840(((char*)((char*)&DAT_0052842c + 7364)));
        receiver->slot21(path);
    }
}