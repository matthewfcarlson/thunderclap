extern "C" int __cdecl GetLen(void*);
extern "C" int __cdecl Check(void*, int);
extern "C" int __cdecl Modify(void*, int, int, int);
class Obj {
  public:
    char pad[8];
    void* data;
    int Run(int, int);
};
int Obj::Run(int start, int end) {
    int len = GetLen(data);
    if (len == 0)
        return -1;
    if (start != 0) {
        int absStart = start;
        if (start < 0)
            absStart = -start;
        if (absStart <= len) {
            if (Check(data, start) == 6) {
                if (end == -1) {
                    if (start > 0)
                        end = len - start;
                    else
                        end = len + start;
                }
                void* d = data;
                if (Modify(d, end, -1, 0) == 0)
                    return GetLen(data);
            }
        }
    }
    return -1;
}