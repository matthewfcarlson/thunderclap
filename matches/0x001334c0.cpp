class Obj_1334c0 {
  public:
    char pad[0x10];
    int value;
    char Set(int a);
};

char Obj_1334c0::Set(int a) {
    value = a;
    return 1;
}
