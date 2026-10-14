// STATUS: equivalent (tools/equiv.py level 3: 120 inputs, branch coverage 6/8, incomplete)
// FUN_002d0da0 @ 0x002d0da0
struct Obj {
    char pad0[0xc];
    int handler;        // 0x0c
};

struct Handler {
    void FUN_002e1020(Obj* obj, int a, int b);
};

struct Row {
    Obj** objs;
    int pad[2];
};

struct Table {
    char pad0[0x14];
    Row* rows;          // 0x14
};

struct Source;

struct Cursor {
    int pad0;
    int row;            // 0x04
    int index;          // 0x08
    Table* table;       // 0x0c
    void FUN_002e5850(Source* src, int arg);
    void FUN_002e5310();
};

class Dispatcher {
public:
    char pad0[8];
    Source* source;     // 0x08
    Handler** handlers; // 0x0c
    void FUN_002d0da0(int arg, int a, int b);
};

// Walks a cursor from its index down to 0, sending each object to its handler.
void Dispatcher::FUN_002d0da0(int arg, int a, int b)
{
    Cursor c;
    c.FUN_002e5850(source, arg);
    int i = c.index;
    while (i >= 0) {
        Obj* obj = c.table->rows[c.row].objs[i];
        handlers[obj->handler]->FUN_002e1020(obj, a, b);
        i = c.index;
        if (i < 0)
            break;
        c.index = --i;
    }
    c.FUN_002e5310();
}
