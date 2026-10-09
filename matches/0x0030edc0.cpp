struct Data {
    unsigned int words[0x15];
};
class Thing {
  public:
    char pad0[0x14];
    Data block;
    char pad1[0xbc - 0x14 - sizeof(Data)];
    int state;
    void Run(Data* data);
    void Finish();
};
void Thing::Run(Data* data) {
    block = *data;
    state = 2;
    Finish();
}