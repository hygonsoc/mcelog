 
typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

#define __u64 u64
#define __u32 u32
#define __u16 u16
#define __u8  u8

/* kernel structure: */

/* Fields are zero when not available */
struct mce {
	__u64 status;
	__u64 misc;
	__u64 addr;
	__u64 mcgstatus;
	__u64 rip;
	__u64 tsc;	/* cpu time stamp counter */
	__u64 time;	/* wall time_t when error was detected */
	__u8  cpuvendor;	/* cpu vendor as encoded in system.h */
	__u8  pad1;
	__u16 pad2;
	__u32 cpuid;	/* CPUID 1 EAX */
	__u8  cs;	/* code segment */
	__u8  bank;	/* machine check bank */
	__u8  cpu;	/* cpu that raised the error */
	__u8  finished;   /* entry is valid */
	__u32 extcpu;	/* extended CPU number */
};

#define X86_VENDOR_INTEL	0
#define X86_VENDOR_CYRIX	1
#define X86_VENDOR_AMD		2
#define X86_VENDOR_UMC		3
#define X86_VENDOR_CENTAUR	5
#define X86_VENDOR_TRANSMETA	7
#define X86_VENDOR_NSC		8
#define X86_VENDOR_NUM		9

#define MCE_OVERFLOW 0		/* bit 0 in flags means overflow */

#define MCE_GET_RECORD_LEN   _IOR('M', 1, int)
#define MCE_GET_LOG_LEN      _IOR('M', 2, int)
#define MCE_GETCLEAR_FLAGS   _IOR('M', 3, int)

/* Software defined banks */
#define MCE_EXTENDED_BANK	128

#define MCE_THERMAL_BANK	(MCE_EXTENDED_BANK + 0)
#define MCE_TIMEOUT_BANK        (MCE_EXTENDED_BANK + 90)

#define MCI_THRESHOLD_OVER  (1ULL<<48)  /* threshold error count overflow */

#define MCI_STATUS_VAL   (1ULL<<63)  /* valid error */
#define MCI_STATUS_OVER  (1ULL<<62)  /* previous errors lost */
#define MCI_STATUS_UC    (1ULL<<61)  /* uncorrected error */
#define MCI_STATUS_EN    (1ULL<<60)  /* error enabled */
#define MCI_STATUS_MISCV (1ULL<<59)  /* misc error reg. valid */
#define MCI_STATUS_ADDRV (1ULL<<58)  /* addr reg. valid */
#define MCI_STATUS_PCC   (1ULL<<57)  /* processor context corrupt */

#define MCG_STATUS_RIPV  (1ULL<<0)   /* restart ip valid */
#define MCG_STATUS_EIPV  (1ULL<<1)   /* eip points to correct instruction */
#define MCG_STATUS_MCIP  (1ULL<<2)   /* machine check in progress */

#define NELE(x) (sizeof(x)/sizeof(*(x)))
#define err(x) perror(x),exit(1)

#ifdef __GNUC__
#define PRINTFLIKE __attribute__((format(printf,1,2)))
#else
#define PRINTFLIKE 
#endif

void Wprintf(char *fmt, ...) PRINTFLIKE;
void Eprintf(char *fmt, ...) PRINTFLIKE;
void Lprintf(char *fmt, ...) PRINTFLIKE;
void Gprintf(char *fmt, ...) PRINTFLIKE;

/* Don't forget to update mcelog.c:cputype_name[] too */
enum cputype {
	CPU_GENERIC,
	CPU_P6OLD,
	CPU_CORE2, /* 65nm and 45nm */
	CPU_K8,
	CPU_P4,
	CPU_NEHALEM,
	CPU_DUNNINGTON,
};
