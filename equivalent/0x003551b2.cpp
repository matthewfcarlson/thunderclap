// STATUS: equivalent (tools/equiv.py level 3: 115 inputs, branch coverage 38/42, incomplete)
// XAPILIB::GetTimeZoneInformation @ 0x003551b2
typedef unsigned long DWORD;
typedef unsigned char BOOLEAN;

namespace XAPILIB {
extern void __stdcall SetLastError(DWORD code);
}

struct FileTime {
    DWORD low;
    long high;
};

struct SystemTime {
    unsigned short year;
    unsigned short month;
    unsigned short dayOfWeek;
    unsigned short day;
    unsigned short hour;
    unsigned short minute;
    unsigned short second;
    unsigned short milliseconds;
};

struct TimeZoneInformation {
    long bias;
    unsigned short standardName[32];
    SystemTime standardDate;
    long standardBias;
    unsigned short daylightName[32];
    SystemTime daylightDate;
    long daylightBias;
};

extern void (__stdcall *DAT_003f2c58)(FileTime *out);
extern DWORD __stdcall FUN_00354d4f(TimeZoneInformation *tz, int *flag);
extern BOOLEAN __stdcall FUN_00354fa8(SystemTime *date, FileTime *out, FileTime *now, int year);

struct Frame {
    FileTime std;
    FileTime dst;
    DWORD aLow;
    int pad;
    __int64 bias;
    FileTime now;
};

namespace XAPILIB {
DWORD __stdcall GetTimeZoneInformation(TimeZoneInformation *tz);
}

DWORD __stdcall XAPILIB::GetTimeZoneInformation(TimeZoneInformation *tz)
{
    Frame f;
    TimeZoneInformation *p = tz;
    DWORD err = FUN_00354d4f(p, (int *)&tz);
    if (err != 0) {
        XAPILIB::SetLastError(err);
        return 0xffffffff;
    }
    if (*(int *)&tz == 0) {
        p->standardBias = 0;
        p->standardDate.year = 0;
        p->standardDate.month = 0;
        p->standardDate.dayOfWeek = 0;
        p->standardDate.day = 0;
        p->standardDate.hour = 0;
        p->standardDate.minute = 0;
        p->standardDate.second = 0;
        p->standardDate.milliseconds = 0;
        p->daylightBias = 0;
        for (int i = 0; i < 8; i++)
            ((unsigned short *)&p->daylightDate)[i] = 0;
        for (int i = 0; i < 32; i++)
            p->daylightName[i] = 0;
    }
    DAT_003f2c58(&f.now);
    DWORD result = 0;
    if (p->standardDate.month == 0)
        return result;
    if (p->daylightDate.month == 0)
        return result;
    if (!FUN_00354fa8(&p->standardDate, &f.std, &f.now, 1))
        return result;
    if (!FUN_00354fa8(&p->daylightDate, &f.dst, &f.now, 1))
        return result;
    f.bias = (__int64)(p->bias * 60) * 10000000;
    unsigned __int64 now = ((unsigned __int64)(unsigned long)f.now.high << 32) | f.now.low;
    __int64 a = (__int64)(p->standardBias * 60) * 10000000 + f.bias + (((__int64)f.dst.high << 32) | f.dst.low);
    __int64 b = (__int64)(p->daylightBias * 60) * 10000000 + f.bias + (((__int64)f.std.high << 32) | f.std.low);
    __int64 t = (__int64)now;
    if (a < b) {
        if (t < a)
            return 1;
        if (t < b)
            return 2;
        return 1;
    }
    if (t < b)
        return 2;
    if (t < a)
        return 1;
    return 2;
}
