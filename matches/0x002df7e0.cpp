// Same code shape as 0x0025d3e0 (propagated; names are from that function)
class Object {
public:
    int GetValue();

    char pad[0x58];
    int mValue;
};

int Object::GetValue() {
    return mValue;
}