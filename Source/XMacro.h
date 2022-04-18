typedef  void(*p_func_t)();

#define STATE_TABLE \
        ENTRY(STATE0, fun0) \
		ENTRY(STATE1, fun1) \
		ENTRY(STATE2, fun2) \
		ENTRY(STATE3, fun3) \
		ENTRY(STATE4, fun4)


// X-MACRO

enum
{
#define ENTRY(a, b) a,
	STATE_TABLE
#undef ENTRY
	NUM_STATES
};

p_func_t jumptable[NUM_STATES] =
{
#define ENTRY(a, b) b,
	STATE_TABLE
#undef ENTRY
};

#define ENTRY(a,b) static void b(void);
STATE_TABLE
#undef ENTRY