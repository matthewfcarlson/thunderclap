class List {
  public:
    void** first;
    void** last;
    void* Get(unsigned i);
};
void* List::Get(unsigned i) {
    if (i < (unsigned)(last - first))
        return first[i];
    return 0;
}