// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_00265a20 @ 0x00265a20
struct Table_265a20;

class Object {
public:
    virtual void v0();
    virtual void v1();
};

struct Probe_265a20 {
    Table_265a20 *table;           // 0x00
    char pad04[0x14];
    void FUN_00231160(Table_265a20 *t);
    Object *FUN_00231180(unsigned int first, unsigned int second);
};

struct Table_265a20 {
    int FUN_00231770(Object *obj);
};

unsigned __int64 __cdecl FUN_00267340(const char *name, int a, int b);

class Registry_265a20 {
public:
    char pad0[0xc];
    Table_265a20 *table;           // 0x0c
    void FUN_00265a20(const char *name);
};

void Registry_265a20::FUN_00265a20(const char *name)
{
    Probe_265a20 first;
    Probe_265a20 again;
    const char *key = name;
    if (*name == '.')
        key = name + 1;
    unsigned __int64 id = FUN_00267340(key, 0, 0);
    first.FUN_00231160(table);
    Object *obj = first.FUN_00231180((unsigned int)id, (unsigned int)(id >> 32));
    while (obj != 0) {
        int n = table->FUN_00231770(obj);
        if (n > 0) {
            do {
                obj->v1();
            } while (--n != 0);
        }
        key = name;
        if (*name == '.')
            key = name + 1;
        id = FUN_00267340(key, 0, 0);
        again.FUN_00231160(table);
        obj = again.FUN_00231180((unsigned int)id, (unsigned int)(id >> 32));
    }
}
