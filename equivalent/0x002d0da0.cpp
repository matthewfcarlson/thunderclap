// STATUS: equivalent (tools/equiv.py level 3: 120 inputs, branch coverage 6/8, incomplete)
// FUN_002d0da0 @ 0x002d0da0
struct Obj_2d0da0 {
    char pad0[0xc];
    int handler;        // 0x0c
};

struct Handler_2d0da0 {
    void FUN_002e1020(Obj_2d0da0* obj, int a, int b);
};

struct Row_2d0da0 {
    Obj_2d0da0** objs;
    int pad[2];
};

struct Table_2d0da0 {
    char pad0[0x14];
    Row_2d0da0* rows;          // 0x14
};

struct Source;

struct Cursor_2d0da0 {
    int pad0;
    int row;            // 0x04
    int index;          // 0x08
    Table_2d0da0* table;       // 0x0c
    void FUN_002e5850(Source* src, int arg);
    void FUN_002e5310();
};

class Dispatcher_2d0da0 {
public:
    char pad0[8];
    Source* source;     // 0x08
    Handler_2d0da0** handlers; // 0x0c
    void FUN_002d0da0(int arg, int a, int b);
};

// Walks a cursor from its index down to 0, sending each object to its handler.
void Dispatcher_2d0da0::FUN_002d0da0(int arg, int a, int b)
{
    Cursor_2d0da0 c;
    c.FUN_002e5850(source, arg);
    int i = c.index;
    while (i >= 0) {
        Obj_2d0da0* obj = c.table->rows[c.row].objs[i];
        handlers[obj->handler]->FUN_002e1020(obj, a, b);
        i = c.index;
        if (i < 0)
            break;
        c.index = --i;
    }
    c.FUN_002e5310();
}
