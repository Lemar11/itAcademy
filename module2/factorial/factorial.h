
#ifdef USE_INT
	typedef uint32_t myType;
#elif defined(USE_FLOAT)
	typedef float myType;
#else
	#error "You must define either USE_INT or USE_FLOAT"
#endif

myType factorial(myType val);


