// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00106900 @ 0x00106900
// 0x00106900: register a new named entry (with a flag and a size) unless the name is already known
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
struct Name_106900 {
    void FUN_0027b040(const char* s);
};

class Entry_106900 {
public:
    virtual void v0();
    virtual void v1();
    char pad04[4];
    Name_106900 name;
    char pad09[15];
    char flag;
    char pad19[7];
    Entry_106900* FUN_00106510(int n);
};

unsigned __int64 __cdecl FUN_0027afb0(const char* s);
void* __cdecl thunk_FUN_0008d690(unsigned int size);

class Registry_106900 {
public:
    int FUN_00106290(unsigned __int64 key);
    void FUN_001062d0(Entry_106900* e);
    bool Add(const char* name, char flag, int n);
};

bool Registry_106900::Add(const char* name, char flag, int n)
{
    if (FUN_00106290(FUN_0027afb0(name)) != -1)
        return false;
    if (n <= 0)
        return false;

    void* mem = thunk_FUN_0008d690(0x20);
    Entry_106900* e = 0;
    if (mem != 0)
        e = ((Entry_106900*)mem)->FUN_00106510(n);
    e->v0();
    e->name.FUN_0027b040(name);
    e->flag = flag;
    FUN_001062d0(e);
    e->v1();
    return true;
}
