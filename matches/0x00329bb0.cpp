extern int gFlags;
extern int gValues[128];
extern int gMore[128];
class State {
  public:
    char pad[0x64];
    int first[4];
    int second[4];
    void update(unsigned int);
};
void State::update(unsigned int index) {
    if (index < 4) {
        if (first[index] != 1) {
            first[index] = 1;
            gFlags = gFlags | 0x800;
            gValues[index * 32] = 1;
        }
        if (second[index] != 1) {
            second[index] = 1;
            int value = gFlags;
            int current = first[index];
            gFlags = value | 0x800;
            gMore[index * 32] = current;
        }
    }
}