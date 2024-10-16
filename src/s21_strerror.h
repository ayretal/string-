#ifndef S21_STRERROR_H
#define S21_STRERROR_H

#define S21_ERR_COUNT 106

#define S21_ADD_ERR(errnum, message) \
  { errnum, message }

typedef struct s21_error_t {
  const int s21_errnum;
  const char *const s21_message;
} s21_error_t;

#define S21_ERR_0 0
#define S21_ERR_1 1
#define S21_ERR_2 2
#define S21_ERR_3 3
#define S21_ERR_4 4
#define S21_ERR_5 5
#define S21_ERR_6 6
#define S21_ERR_7 7
#define S21_ERR_8 8
#define S21_ERR_9 9
#define S21_ERR_10 10
#define S21_ERR_11 11
#define S21_ERR_12 12
#define S21_ERR_13 13
#define S21_ERR_14 14
#define S21_ERR_15 15
#define S21_ERR_16 16
#define S21_ERR_17 17
#define S21_ERR_18 18
#define S21_ERR_19 19
#define S21_ERR_20 20
#define S21_ERR_21 21
#define S21_ERR_22 22
#define S21_ERR_23 23
#define S21_ERR_24 24
#define S21_ERR_25 25
#define S21_ERR_26 26
#define S21_ERR_27 27
#define S21_ERR_28 28
#define S21_ERR_29 29
#define S21_ERR_30 30
#define S21_ERR_31 31
#define S21_ERR_32 32
#define S21_ERR_33 33
#define S21_ERR_34 34
#define S21_ERR_35 35
#define S21_ERR_36 36
#define S21_ERR_37 37
#define S21_ERR_38 38
#define S21_ERR_39 39
#define S21_ERR_40 40
#define S21_ERR_41 41
#define S21_ERR_42 42
#define S21_ERR_43 43
#define S21_ERR_44 44
#define S21_ERR_45 45
#define S21_ERR_46 46
#define S21_ERR_47 47
#define S21_ERR_48 48
#define S21_ERR_49 49
#define S21_ERR_50 50
#define S21_ERR_51 51
#define S21_ERR_52 52
#define S21_ERR_53 53
#define S21_ERR_54 54
#define S21_ERR_55 55
#define S21_ERR_56 56
#define S21_ERR_57 57
#define S21_ERR_58 58
#define S21_ERR_59 59
#define S21_ERR_60 60
#define S21_ERR_61 61
#define S21_ERR_62 62
#define S21_ERR_63 63
#define S21_ERR_64 64
#define S21_ERR_65 65
#define S21_ERR_66 66
#define S21_ERR_67 67
#define S21_ERR_68 68
#define S21_ERR_69 69
#define S21_ERR_70 70
#define S21_ERR_71 71
#define S21_ERR_72 72
#define S21_ERR_73 73
#define S21_ERR_74 74
#define S21_ERR_75 75
#define S21_ERR_76 76
#define S21_ERR_77 77
#define S21_ERR_78 78
#define S21_ERR_79 79
#define S21_ERR_80 80
#define S21_ERR_81 81
#define S21_ERR_82 82
#define S21_ERR_83 83
#define S21_ERR_84 84
#define S21_ERR_85 85
#define S21_ERR_86 86
#define S21_ERR_87 87
#define S21_ERR_88 88
#define S21_ERR_89 89
#define S21_ERR_90 90
#define S21_ERR_91 91
#define S21_ERR_92 92
#define S21_ERR_93 93
#define S21_ERR_94 94
#define S21_ERR_95 95
#define S21_ERR_96 96
#define S21_ERR_97 97
#define S21_ERR_98 98
#define S21_ERR_99 99
#define S21_ERR_100 100
#define S21_ERR_101 101
#define S21_ERR_102 102
#define S21_ERR_103 103
#define S21_ERR_104 104
#define S21_ERR_105 105
#define S21_ERR_106 106
#define S21_ERR_107 107
#define S21_ERR_108 108
#define S21_ERR_109 109
#define S21_ERR_110 110
#define S21_ERR_111 111
#define S21_ERR_112 112
#define S21_ERR_113 113
#define S21_ERR_114 114
#define S21_ERR_115 115
#define S21_ERR_116 116
#define S21_ERR_117 117
#define S21_ERR_118 118
#define S21_ERR_119 119
#define S21_ERR_120 120
#define S21_ERR_121 121
#define S21_ERR_122 122
#define S21_ERR_123 123
#define S21_ERR_124 124
#define S21_ERR_125 125
#define S21_ERR_126 126
#define S21_ERR_127 127
#define S21_ERR_128 128
#define S21_ERR_129 129
#define S21_ERR_130 130
#define S21_ERR_131 131
#define S21_ERR_132 132
#define S21_ERR_133 133

#ifdef __APPLE__
static const s21_error_t s21_error_list[] = {
    S21_ADD_ERR(S21_ERR_0, "Undefined error: 0"),
    S21_ADD_ERR(S21_ERR_1, "Operation not permitted"),
    S21_ADD_ERR(S21_ERR_2, "No such file or directory"),
    S21_ADD_ERR(S21_ERR_3, "No such process"),
    S21_ADD_ERR(S21_ERR_4, "Interrupted system call"),
    S21_ADD_ERR(S21_ERR_5, "Input/output error"),
    S21_ADD_ERR(S21_ERR_6, "Device not configured"),
    S21_ADD_ERR(S21_ERR_7, "Argument list too long"),
    S21_ADD_ERR(S21_ERR_8, "Exec format error"),
    S21_ADD_ERR(S21_ERR_9, "Bad file descriptor"),
    S21_ADD_ERR(S21_ERR_10, "No child processes"),
    S21_ADD_ERR(S21_ERR_11, "Resource deadlock avoided"),
    S21_ADD_ERR(S21_ERR_12, "Cannot allocate memory"),
    S21_ADD_ERR(S21_ERR_13, "Permission denied"),
    S21_ADD_ERR(S21_ERR_14, "Bad address"),
    S21_ADD_ERR(S21_ERR_15, "Block device required"),
    S21_ADD_ERR(S21_ERR_16, "Resource busy"),
    S21_ADD_ERR(S21_ERR_17, "File exists"),
    S21_ADD_ERR(S21_ERR_18, "Cross-device link"),
    S21_ADD_ERR(S21_ERR_19, "Operation not supported by device"),
    S21_ADD_ERR(S21_ERR_20, "Not a directory"),
    S21_ADD_ERR(S21_ERR_21, "Is a directory"),
    S21_ADD_ERR(S21_ERR_22, "Invalid argument"),
    S21_ADD_ERR(S21_ERR_23, "Too many open files in system"),
    S21_ADD_ERR(S21_ERR_24, "Too many open files"),
    S21_ADD_ERR(S21_ERR_25, "Inappropriate ioctl for device"),
    S21_ADD_ERR(S21_ERR_26, "Text file busy"),
    S21_ADD_ERR(S21_ERR_27, "File too large"),
    S21_ADD_ERR(S21_ERR_28, "No space left on device"),
    S21_ADD_ERR(S21_ERR_29, "Illegal seek"),
    S21_ADD_ERR(S21_ERR_30, "Read-only file system"),
    S21_ADD_ERR(S21_ERR_31, "Too many links"),
    S21_ADD_ERR(S21_ERR_32, "Broken pipe"),
    S21_ADD_ERR(S21_ERR_33, "Numerical argument out of domain"),
    S21_ADD_ERR(S21_ERR_34, "Result too large"),
    S21_ADD_ERR(S21_ERR_35, "Resource temporarily unavailable"),
    S21_ADD_ERR(S21_ERR_36, "Operation now in progress"),
    S21_ADD_ERR(S21_ERR_37, "Operation already in progress"),
    S21_ADD_ERR(S21_ERR_38, "Socket operation on non-socket"),
    S21_ADD_ERR(S21_ERR_39, "Destination address required"),
    S21_ADD_ERR(S21_ERR_40, "Message too long"),
    S21_ADD_ERR(S21_ERR_41, "Protocol wrong type for socket"),
    S21_ADD_ERR(S21_ERR_42, "Protocol not available"),
    S21_ADD_ERR(S21_ERR_43, "Protocol not supported"),
    S21_ADD_ERR(S21_ERR_44, "Socket type not supported"),
    S21_ADD_ERR(S21_ERR_45, "Operation not supported"),
    S21_ADD_ERR(S21_ERR_46, "Protocol family not supported"),
    S21_ADD_ERR(S21_ERR_47, "Address family not supported by protocol family"),
    S21_ADD_ERR(S21_ERR_48, "Address already in use"),
    S21_ADD_ERR(S21_ERR_49, "Can't assign requested address"),
    S21_ADD_ERR(S21_ERR_50, "Network is down"),
    S21_ADD_ERR(S21_ERR_51, "Network is unreachable"),
    S21_ADD_ERR(S21_ERR_52, "Network dropped connection on reset"),
    S21_ADD_ERR(S21_ERR_53, "Software caused connection abort"),
    S21_ADD_ERR(S21_ERR_54, "Connection reset by peer"),
    S21_ADD_ERR(S21_ERR_55, "No buffer space available"),
    S21_ADD_ERR(S21_ERR_56, "Socket is already connected"),
    S21_ADD_ERR(S21_ERR_57, "Socket is not connected"),
    S21_ADD_ERR(S21_ERR_58, "Can't send after socket shutdown"),
    S21_ADD_ERR(S21_ERR_59, "Too many references: can't splice"),
    S21_ADD_ERR(S21_ERR_60, "Operation timed out"),
    S21_ADD_ERR(S21_ERR_61, "Connection refused"),
    S21_ADD_ERR(S21_ERR_62, "Too many levels of symbolic links"),
    S21_ADD_ERR(S21_ERR_63, "File name too long"),
    S21_ADD_ERR(S21_ERR_64, "Host is down"),
    S21_ADD_ERR(S21_ERR_65, "No route to host"),
    S21_ADD_ERR(S21_ERR_66, "Directory not empty"),
    S21_ADD_ERR(S21_ERR_67, "Too many processes"),
    S21_ADD_ERR(S21_ERR_68, "Too many users"),
    S21_ADD_ERR(S21_ERR_69, "Disc quota exceeded"),
    S21_ADD_ERR(S21_ERR_70, "Stale NFS file handle"),
    S21_ADD_ERR(S21_ERR_71, "Too many levels of remote in path"),
    S21_ADD_ERR(S21_ERR_72, "RPC struct is bad"),
    S21_ADD_ERR(S21_ERR_73, "RPC version wrong"),
    S21_ADD_ERR(S21_ERR_74, "RPC prog. not avail"),
    S21_ADD_ERR(S21_ERR_75, "Program version wrong"),
    S21_ADD_ERR(S21_ERR_76, "Bad procedure for program"),
    S21_ADD_ERR(S21_ERR_77, "No locks available"),
    S21_ADD_ERR(S21_ERR_78, "Function not implemented"),
    S21_ADD_ERR(S21_ERR_79, "Inappropriate file type or format"),
    S21_ADD_ERR(S21_ERR_80, "Authentication error"),
    S21_ADD_ERR(S21_ERR_81, "Need authenticator"),
    S21_ADD_ERR(S21_ERR_82, "Device power is off"),
    S21_ADD_ERR(S21_ERR_83, "Device error"),
    S21_ADD_ERR(S21_ERR_84, "Value too large to be stored in data type"),
    S21_ADD_ERR(S21_ERR_85, "Bad executable (or shared library)"),
    S21_ADD_ERR(S21_ERR_86, "Bad CPU type in executable"),
    S21_ADD_ERR(S21_ERR_87, "Shared library version mismatch"),
    S21_ADD_ERR(S21_ERR_88, "Malformed Mach-o file"),
    S21_ADD_ERR(S21_ERR_89, "Operation canceled"),
    S21_ADD_ERR(S21_ERR_90, "Identifier removed"),
    S21_ADD_ERR(S21_ERR_91, "No message of desired type"),
    S21_ADD_ERR(S21_ERR_92, "Illegal byte sequence"),
    S21_ADD_ERR(S21_ERR_93, "Attribute not found"),
    S21_ADD_ERR(S21_ERR_94, "Bad message"),
    S21_ADD_ERR(S21_ERR_95, "EMULTIHOP (Reserved)"),
    S21_ADD_ERR(S21_ERR_96, "No message available on STREAM"),
    S21_ADD_ERR(S21_ERR_97, "ENOLINK (Reserved)"),
    S21_ADD_ERR(S21_ERR_98, "No STREAM resources"),
    S21_ADD_ERR(S21_ERR_99, "Not a STREAM"),
    S21_ADD_ERR(S21_ERR_100, "Protocol error"),
    S21_ADD_ERR(S21_ERR_101, "STREAM ioctl timeout"),
    S21_ADD_ERR(S21_ERR_102, "Operation not supported on socket"),
    S21_ADD_ERR(S21_ERR_103, "Policy not found"),
    S21_ADD_ERR(S21_ERR_104, "State not recoverable"),
    S21_ADD_ERR(S21_ERR_105, "Previous owner died"),
    S21_ADD_ERR(S21_ERR_106, "Interface output queue is full"),
    S21_ADD_ERR(-1, "Unknown error")};
#endif  // __APPLE__

#if defined(__linux) || defined(__linux__)
static const s21_error_t s21_error_list[] = {
    S21_ADD_ERR(S21_ERR_0, "Success"),
    S21_ADD_ERR(S21_ERR_1, "Operation not permitted"),
    S21_ADD_ERR(S21_ERR_2, "No such file or directory"),
    S21_ADD_ERR(S21_ERR_3, "No such process"),
    S21_ADD_ERR(S21_ERR_4, "Interrupted system call"),
    S21_ADD_ERR(S21_ERR_5, "Input/output error"),
    S21_ADD_ERR(S21_ERR_6, "No such device or address"),
    S21_ADD_ERR(S21_ERR_7, "Argument list too long"),
    S21_ADD_ERR(S21_ERR_8, "Exec format error"),
    S21_ADD_ERR(S21_ERR_9, "Bad file descriptor"),
    S21_ADD_ERR(S21_ERR_10, "No child processes"),
    S21_ADD_ERR(S21_ERR_11, "Resource temporarily unavailable"),
    S21_ADD_ERR(S21_ERR_12, "Cannot allocate memory"),
    S21_ADD_ERR(S21_ERR_13, "Permission denied"),
    S21_ADD_ERR(S21_ERR_14, "Bad address"),
    S21_ADD_ERR(S21_ERR_15, "Block device required"),
    S21_ADD_ERR(S21_ERR_16, "Device or resource busy"),
    S21_ADD_ERR(S21_ERR_17, "File exists"),
    S21_ADD_ERR(S21_ERR_18, "Invalid cross-device link"),
    S21_ADD_ERR(S21_ERR_19, "No such device"),
    S21_ADD_ERR(S21_ERR_20, "Not a directory"),
    S21_ADD_ERR(S21_ERR_21, "Is a directory"),
    S21_ADD_ERR(S21_ERR_22, "Invalid argument"),
    S21_ADD_ERR(S21_ERR_23, "Too many open files in system"),
    S21_ADD_ERR(S21_ERR_24, "Too many open files"),
    S21_ADD_ERR(S21_ERR_25, "Inappropriate ioctl for device"),
    S21_ADD_ERR(S21_ERR_26, "Text file busy"),
    S21_ADD_ERR(S21_ERR_27, "File too large"),
    S21_ADD_ERR(S21_ERR_28, "No space left on device"),
    S21_ADD_ERR(S21_ERR_29, "Illegal seek"),
    S21_ADD_ERR(S21_ERR_30, "Read-only file system"),
    S21_ADD_ERR(S21_ERR_31, "Too many links"),
    S21_ADD_ERR(S21_ERR_32, "Broken pipe"),
    S21_ADD_ERR(S21_ERR_33, "Numerical argument out of domain"),
    S21_ADD_ERR(S21_ERR_34, "Numerical result out of range"),
    S21_ADD_ERR(S21_ERR_35, "Resource deadlock avoided"),
    S21_ADD_ERR(S21_ERR_36, "File name too long"),
    S21_ADD_ERR(S21_ERR_37, "No locks available"),
    S21_ADD_ERR(S21_ERR_38, "Function not implemented"),
    S21_ADD_ERR(S21_ERR_39, "Directory not empty"),
    S21_ADD_ERR(S21_ERR_40, "Too many levels of symbolic links"),
    S21_ADD_ERR(S21_ERR_41, "Unknown error 41"),
    S21_ADD_ERR(S21_ERR_42, "No message of desired type"),
    S21_ADD_ERR(S21_ERR_43, "Identifier removed"),
    S21_ADD_ERR(S21_ERR_44, "Channel number out of range"),
    S21_ADD_ERR(S21_ERR_45, "Level 2 not synchronized"),
    S21_ADD_ERR(S21_ERR_46, "Level 3 halted"),
    S21_ADD_ERR(S21_ERR_47, "Level 3 reset"),
    S21_ADD_ERR(S21_ERR_48, "Link number out of range"),
    S21_ADD_ERR(S21_ERR_49, "Protocol driver not attached"),
    S21_ADD_ERR(S21_ERR_50, "No CSI structure available"),
    S21_ADD_ERR(S21_ERR_51, "Level 2 halted"),
    S21_ADD_ERR(S21_ERR_52, "Invalid exchange"),
    S21_ADD_ERR(S21_ERR_53, "Invalid request descriptor"),
    S21_ADD_ERR(S21_ERR_54, "Exchange full"),
    S21_ADD_ERR(S21_ERR_55, "No anode"),
    S21_ADD_ERR(S21_ERR_56, "Invalid request code"),
    S21_ADD_ERR(S21_ERR_57, "Invalid slot"),
    S21_ADD_ERR(S21_ERR_58, "Unknown error 58"),
    S21_ADD_ERR(S21_ERR_59, "Bad font file format"),
    S21_ADD_ERR(S21_ERR_60, "Device not a stream"),
    S21_ADD_ERR(S21_ERR_61, "No data available"),
    S21_ADD_ERR(S21_ERR_62, "Timer expired"),
    S21_ADD_ERR(S21_ERR_63, "Out of streams resources"),
    S21_ADD_ERR(S21_ERR_64, "Machine is not on the network"),
    S21_ADD_ERR(S21_ERR_65, "Package not installed"),
    S21_ADD_ERR(S21_ERR_66, "Object is remote"),
    S21_ADD_ERR(S21_ERR_67, "Link has been severed"),
    S21_ADD_ERR(S21_ERR_68, "Advertise error"),
    S21_ADD_ERR(S21_ERR_69, "Srmount error"),
    S21_ADD_ERR(S21_ERR_70, "Communication error on send"),
    S21_ADD_ERR(S21_ERR_71, "Protocol error"),
    S21_ADD_ERR(S21_ERR_72, "Multihop attempted"),
    S21_ADD_ERR(S21_ERR_73, "RFS specific error"),
    S21_ADD_ERR(S21_ERR_74, "Bad message"),
    S21_ADD_ERR(S21_ERR_75, "Value too large for defined data type"),
    S21_ADD_ERR(S21_ERR_76, "Name not unique on network"),
    S21_ADD_ERR(S21_ERR_77, "File descriptor in bad state"),
    S21_ADD_ERR(S21_ERR_78, "Remote address changed"),
    S21_ADD_ERR(S21_ERR_79, "Can not access a needed shared library"),
    S21_ADD_ERR(S21_ERR_80, "Accessing a corrupted shared library"),
    S21_ADD_ERR(S21_ERR_81, ".lib section in a.out corrupted"),
    S21_ADD_ERR(S21_ERR_82, "Attempting to link in too many shared libraries"),
    S21_ADD_ERR(S21_ERR_83, "Cannot exec a shared library directly"),
    S21_ADD_ERR(S21_ERR_84,
                "Invalid or incomplete multibyte or wide character"),
    S21_ADD_ERR(S21_ERR_85, "Interrupted system call should be restarted"),
    S21_ADD_ERR(S21_ERR_86, "Streams pipe error"),
    S21_ADD_ERR(S21_ERR_87, "Too many users"),
    S21_ADD_ERR(S21_ERR_88, "Socket operation on non-socket"),
    S21_ADD_ERR(S21_ERR_89, "Destination address required"),
    S21_ADD_ERR(S21_ERR_90, "Message too long"),
    S21_ADD_ERR(S21_ERR_91, "Protocol wrong type for socket"),
    S21_ADD_ERR(S21_ERR_92, "Protocol not available"),
    S21_ADD_ERR(S21_ERR_93, "Protocol not supported"),
    S21_ADD_ERR(S21_ERR_94, "Socket type not supported"),
    S21_ADD_ERR(S21_ERR_95, "Operation not supported"),
    S21_ADD_ERR(S21_ERR_96, "Protocol family not supported"),
    S21_ADD_ERR(S21_ERR_97, "Address family not supported by protocol"),
    S21_ADD_ERR(S21_ERR_98, "Address already in use"),
    S21_ADD_ERR(S21_ERR_99, "Cannot assign requested address"),
    S21_ADD_ERR(S21_ERR_100, "Network is down"),
    S21_ADD_ERR(S21_ERR_101, "Network is unreachable"),
    S21_ADD_ERR(S21_ERR_102, "Network dropped connection on reset"),
    S21_ADD_ERR(S21_ERR_103, "Software caused connection abort"),
    S21_ADD_ERR(S21_ERR_104, "Connection reset by peer"),
    S21_ADD_ERR(S21_ERR_105, "No buffer space available"),
    S21_ADD_ERR(S21_ERR_106, "Transport endpoint is already connected"),
    S21_ADD_ERR(S21_ERR_107, "Cannot send after transport endpoint shutdown"),
    S21_ADD_ERR(S21_ERR_108, "Too many references: cannot splice"),
    S21_ADD_ERR(S21_ERR_109, "Connection timed out"),
    S21_ADD_ERR(S21_ERR_110, "Connection refused"),
    S21_ADD_ERR(S21_ERR_111, "Host is down"),
    S21_ADD_ERR(S21_ERR_112, "No route to host"),
    S21_ADD_ERR(S21_ERR_113, "Operation already in progress"),
    S21_ADD_ERR(S21_ERR_114, "Operation now in progress"),
    S21_ADD_ERR(S21_ERR_115, "Stale file handle"),
    S21_ADD_ERR(S21_ERR_116, "Structure needs cleaning"),
    S21_ADD_ERR(S21_ERR_117, "Not a XENIX named type file"),
    S21_ADD_ERR(S21_ERR_118, "No XENIX semaphores available"),
    S21_ADD_ERR(S21_ERR_119, "Is a named type file"),
    S21_ADD_ERR(S21_ERR_120, "Remote I/O error"),
    S21_ADD_ERR(S21_ERR_121, "Disk quota exceeded"),
    S21_ADD_ERR(S21_ERR_122, "No medium found"),
    S21_ADD_ERR(S21_ERR_123, "Wrong medium type"),
    S21_ADD_ERR(S21_ERR_124, "Operation canceled"),
    S21_ADD_ERR(S21_ERR_125, "Required key not available"),
    S21_ADD_ERR(S21_ERR_126, "Key has expired"),
    S21_ADD_ERR(S21_ERR_127, "Key has been revoked"),
    S21_ADD_ERR(S21_ERR_128, "Key was rejected by service"),
    S21_ADD_ERR(S21_ERR_129, "Owner died"),
    S21_ADD_ERR(S21_ERR_130, "State not recoverable"),
    S21_ADD_ERR(S21_ERR_131, "Operation not possible due to RF-kill"),
    S21_ADD_ERR(S21_ERR_132, "Memory page has hardware error"),
    S21_ADD_ERR(-1, "")};
#endif  // __linux

#endif  // S21_STRERROR_H