class Obj_fc890 {
public:
    char pad0[0x10];
    bool flag10;
    bool flag11;
    bool flag12;
    bool flag13;
    float threshold;
    float value;
    float Get();
};

float Obj_fc890::Get()
{
    bool direct = !flag12 && !(threshold < 0.1f) && !flag10;
    if ((!direct && flag13) || flag11)
        return 0.0f;
    return value;
}
