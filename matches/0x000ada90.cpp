struct Data_ada90 {
    unsigned int x[0x11];
};
class Thing_ada90 {
  public:
    char pad[0x5c];
    Data_ada90 data;
    void Copy(Data_ada90* out);
};
void Thing_ada90::Copy(Data_ada90* out) {
    *out = data;
}