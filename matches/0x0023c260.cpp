class Stream { public: virtual void Init(); };
extern char readerVtable[];
class BinReader {
public:
    void* vptr; int field4; Stream* stream; char b0c,b0d,b0e,pad0f; int field10; char pad14[4]; int field18,field1c,field20; char pad24[4]; int field28,field2c; char field30;
    BinReader* Build(Stream*);
    void Finish();
};
BinReader* BinReader::Build(Stream* s) {
    field4=0; vptr=readerVtable;
    b0c=0; b0d=0; b0e=0; field10=-1; field18=0; field1c=0; field20=0; field28=0; field2c=0; field30=1;
    stream=s; s->Init(); Finish(); return this;
}