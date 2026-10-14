// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00337c20 @ 0x00337c20
struct Buffer_337c20 {
    unsigned int field0;
    void* data;
    unsigned int field8;
    unsigned int field12;
    void FUN_003352a0();
    void FUN_003352b0();
    void* FUN_00336f00(int size);
    void FUN_00336ee0(int size);
    void FUN_00336d90();
    void FUN_00336dd0();
};
struct Stream {
    virtual void slot0();
    virtual void open(void* arg);
    virtual void close();
    virtual int read(void* dest, int size);
    virtual bool available();
};
struct Converter { void* FUN_003373e0(void* data); };
struct Output_337c20 { virtual void slot0(); virtual void emit(Buffer_337c20* value); };
bool __stdcall FUN_00337c20(Stream* stream, void* arg, Converter* converter, Output_337c20* output) {
    Buffer_337c20 buffer;
    buffer.FUN_003352a0();
    stream->open(arg);
    while (stream->available()) {
        int size;
        if (stream->read(&size,4) < 4) {
            buffer.FUN_003352b0();
            return false;
        }
        if (stream->read(buffer.FUN_00336f00(size),size) < size) {
            buffer.FUN_003352b0();
            return false;
        }
        buffer.FUN_00336ee0(size);
        buffer.FUN_00336d90();
        buffer.data = converter->FUN_003373e0(buffer.data);
        buffer.FUN_00336dd0();
        output->emit(&buffer);
    }
    stream->close();
    buffer.FUN_003352b0();
    return true;
}