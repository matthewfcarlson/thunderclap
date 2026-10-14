struct Data_30edc0 {
    unsigned int words[0x15];
};
class Thing_30edc0 {
  public:
    char pad0[0x14];
    Data_30edc0 block;
    char pad1[0xbc - 0x14 - sizeof(Data_30edc0)];
    int state;
    void Run(Data_30edc0* data);
    void Finish();
};
void Thing_30edc0::Run(Data_30edc0* data) {
    block = *data;
    state = 2;
    Finish();
}