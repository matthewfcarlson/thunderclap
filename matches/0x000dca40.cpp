extern const char alphabet[];
class Thing {
public:
    char pad0[0x150]; int count; char pad154[4]; char *out; char pad15c[0x10]; int *values;
    bool Run();
};
bool Thing::Run() {
    int i = 0;
    if (count > 0) {
        do {
            int value = values[i];
            if (value >= 0) out[i] = alphabet[value];
            else out[i] = 0;
            ++i;
        } while (i < count);
    }
    out[count] = 0;
    return true;
}