struct Inner_1d56f0 {
    char pad[0x1c];
    int* data;
};
class C_1d56f0 {
  public:
    char pad[0x90];
    Inner_1d56f0* m;
    int f(int index);
};
int C_1d56f0::f(int index) {
    return m->data[index];
}