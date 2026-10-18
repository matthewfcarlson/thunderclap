// FUN_00092ef0 @ 0x00092ef0
// 0x00092ef0: fill in a table entry (names, text and flag) for one of the ids 0x266..0x2c9
extern char DAT_0049dab8[];
extern char DAT_0049db1c[];
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
void* __cdecl FUN_00344e74(int id, int a, const char* b, const char* c, int d);

struct Name_92ef0 {
    void FUN_0027b040(const char* s);
    char data[8];
};

struct Entry_92ef0 {
    char pad00[0x10];
    Name_92ef0 name10;
    char pad18[8];
    char flag20;
    char pad21[3];
    int value24;
    char pad28[0x10];
    Name_92ef0 name38;
    Name_92ef0 name40;
    char text48[0x40];
};

class Table_92ef0 {
public:
    int ids[0x300];
    void FUN_00092ef0(int index, const char* a, const char* b, const char* c, const char* text, int value);
};

void Table_92ef0::FUN_00092ef0(int index, const char* a, const char* b, const char* c, const char* text, int value)
{
    if (index < 0x266 || index > 0x2c9)
        return;
    Entry_92ef0* e = (Entry_92ef0*)FUN_00344e74(ids[index], 0, DAT_0049dab8, DAT_0049db1c, 0);
    if (e == 0)
        return;
    e->name10.FUN_0027b040(a);
    e->name38.FUN_0027b040(b);
    e->name40.FUN_0027b040(c);
    strncpy(e->text48, text, 0x40);
    e->value24 = value;
    if (value == 0)
        e->flag20 = 1;
}
