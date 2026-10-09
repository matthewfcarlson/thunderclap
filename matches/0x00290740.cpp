class StatePropDataLoader {
  public:
    StatePropDataLoader();
    int vptr;
    int a;
    int b;
    int c;
    int d;
};
StatePropDataLoader::StatePropDataLoader() {
    a = 0;
    b = 0x802000a;
    c = 0;
    d = 0;
    vptr = 0x42cca0;
}