class Sink {
public:
    virtual void Begin(int a, int b, int size, int c, int d);     // slot 0
    virtual void Add(int item);                                   // slot 1
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual int Finish();                                         // slot 10
};

struct Stream;

unsigned char __cdecl FUN_002d7f30(Stream *s, int x);
int __cdecl FUN_002d7ed0(Stream *s, int x);
int __cdecl FUN_002d7ef0(Stream *s, int x);
int __cdecl FUN_002d7eb0(Stream *s, int x);
void __cdecl FUN_002d7440(Stream *s, int item, int flag);
int __cdecl FUN_00266e00(int a, int b);
void __cdecl FUN_00266f00(int a, int b);

// Reads a block of items from a stream into a sink.
// equiv-conv: FUN_002adb10 eax esi edi
int FUN_002adb10(int x, Stream *s, Sink *sink) {
    int size = FUN_002d7f30(s, x) != 6 ? 0x18 : 0x20;
    int first = FUN_002d7ed0(s, x);
    int count = FUN_002d7ef0(s, x);
    sink->Begin(first, count, size, 0, 0);
    int handle = FUN_00266e00(1, FUN_002d7eb0(s, x));
    for (; count > 0; count--) {
        FUN_002d7440(s, handle, 0);
        sink->Add(handle);
    }
    FUN_00266f00(1, handle);
    return sink->Finish();
}
