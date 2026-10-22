// STATUS: equivalent (tools/equiv.py level 3: 54 inputs, branch coverage 22/22)
// FUN_0027a6e0 @ 0x0027a6e0
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
extern "C" void* __cdecl FUN_00263ea0(unsigned int size);
extern "C" void __cdecl FUN_0008d330(void* p);

struct Cursor_27a6e0 {
    int a, b;
    void FUN_0027b0e0(int pos);
    void FUN_0027af50();
};
class Reader {
  public:
    Reader* FUN_0027ab90(int arg);
    bool FUN_0027ac30(int* pos);
    bool FUN_0027acf0(int* first, int* second);
    void FUN_0027aec0();
};
class RDLObject_27a6e0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    RDLObject_27a6e0* FUN_0027a890();
    void FUN_0027a8c0(int pos);
    void FUN_0027a8f0(int first, int second);
};
class Listener_27a6e0 {
  public:
    virtual void vfunc_0(int a, RDLObject_27a6e0* w);
};
struct Slot_27a6e0 {
    int pad[2];
    bool FUN_0027af90(Cursor_27a6e0* c);
};
class Dispatcher_27a6e0 {
  public:
    Slot_27a6e0 slots[20];
    Listener_27a6e0* listeners[20];
    int count;
    void FUN_0027a6e0(int arg1, int arg2);
};
void Dispatcher_27a6e0::FUN_0027a6e0(int arg1, int arg2) {
    Reader* reader;
    void* mem = FUN_0008d690(0xb4);
    if (mem)
        reader = ((Reader*)mem)->FUN_0027ab90(arg1);
    else
        reader = 0;
    RDLObject_27a6e0* writer;
    void* mem2 = FUN_00263ea0(0x3438);
    if (mem2)
        writer = ((RDLObject_27a6e0*)mem2)->FUN_0027a890();
    else
        writer = 0;
    writer->vfunc_0();
    if (reader) {
        int pos;
        while (reader->FUN_0027ac30(&pos)) {
            writer->FUN_0027a8c0(pos);
            int first, second;
            if (reader->FUN_0027acf0(&first, &second)) {
                do {
                    writer->FUN_0027a8f0(first, second);
                } while (reader->FUN_0027acf0(&first, &second));
            }
            Cursor_27a6e0 cursor;
            cursor.FUN_0027b0e0(pos);
            for (int i = 0; i < count; i++) {
                if (slots[i].FUN_0027af90(&cursor)) {
                    if (listeners[i])
                        listeners[i]->vfunc_0(arg2, writer);
                }
            }
            cursor.FUN_0027af50();
        }
        writer->vfunc_1();
        reader->FUN_0027aec0();
        FUN_0008d330(reader);
    }
}
