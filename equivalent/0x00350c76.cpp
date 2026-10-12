// STATUS: equivalent (tools/equiv.py level 3: 126 inputs, branch coverage 22/22)
// ?getPrimaryDataType@UnDecorator@@CA?AVDName@@ABV2@@Z @ 0x00350c76
enum DNameStatus { DN_valid = 0, DN_invalid = 1, DN_truncated = 2, DN_error = 3 };

class DNameNode;

class DName {
public:
    DNameNode *node;
    unsigned int stat : 4;
    unsigned int isIndir : 1;
    unsigned int isAUDC : 1;
    unsigned int isAUDTThunk : 1;
    unsigned int isArrayType : 1;
    unsigned int NoTE : 1;
    unsigned int rest : 23;

    DName() : node(0)
    {
        stat = 0;
        isIndir = 0;
        isAUDC = 0;
        isAUDTThunk = 0;
        isArrayType = 0;
        NoTE = 0;
    }
    DName(DNameStatus st);
    DName(const DName &other);
    int isEmpty() const;
    DName &operator=(const char *str);
    DName &operator+=(char c);
};

DName operator+(DNameStatus st, const DName &d);

DName FUN_00350046(const DName &superType, char prefix, const DName &cvType, int thisFlag);

extern const char *DAT_005684bc;

// UnDecorator static members, bound by address (their mangled names are not resolvable by the checker)
DName FUN_00350903(const DName &superType);                              // getBasicDataType
DName FUN_003506a5(const DName &cvType, const DName &superType, char c); // getPtrRefType
DName FUN_0034e287(const DName &superType, int isPtr);                   // getPtrRefDataType
DName FUN_0034fd05(const DName &superType);                              // getFunctionIndirectType

class UnDecorator {
private:
    static DName getPrimaryDataType(const DName &superType);
};

DName UnDecorator::getPrimaryDataType(const DName &superType)
{
    DName cvType;

    switch (*DAT_005684bc) {
    case 0:
        return DN_truncated + superType;

    case '$':
        if (DAT_005684bc[1] == '$') {
            DAT_005684bc += 2;
            switch (*DAT_005684bc) {
            case 0:
                return DN_truncated + superType;
            case 'A':
                DAT_005684bc++;
                return FUN_0034fd05(superType);
            case 'B':
                DAT_005684bc++;
                return FUN_0034e287(superType, 1);
            case 'C': {
                DName cv;
                DAT_005684bc++;
                return FUN_00350903(FUN_00350046(superType, 0, cv, 0));
            }
            default:
                return DName(DN_invalid);
            }
        }
        if (DAT_005684bc[1] == 0)
            return DN_truncated + superType;
        return DName(DN_invalid);

    case 'B':
        cvType = "volatile";
        if (!superType.isEmpty())
            cvType += ' ';
        // fall through
    case 'A': {
        DName inner(superType);
        DAT_005684bc++;
        inner.isIndir = 1;
        return FUN_003506a5(cvType, inner, '&');
    }

    default:
        return FUN_00350903(superType);
    }
}
