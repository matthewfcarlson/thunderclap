struct Data {
    unsigned int x[0x11];
};
class Thing {
  public:
    char pad[0x5c];
    Data data;
    void Copy(Data* out);
};
void Thing::Copy(Data* out) {
    *out = data;
}