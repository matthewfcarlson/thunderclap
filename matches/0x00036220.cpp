class Thing_36220 {
  public:
    char pad[0x1b24];
    int value;
    void Change(char up);
};
void Thing_36220::Change(char up) {
    if (up)
        ++value;
    else
        --value;
}