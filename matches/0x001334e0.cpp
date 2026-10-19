extern const float k_1334e0 = 0.017453292f;
class Obj_1334e0 {
  public:
    char Set(float x);
};
char Obj_1334e0::Set(float x) {
    *(float*)((char*)this + 0x14) = x * k_1334e0;
    return 1;
}