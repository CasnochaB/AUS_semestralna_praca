#pragma once
#include <crtdbg.h>

#ifdef _DEBUG


#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)

/// <summary>
/// trieda pre vytvorenie constantneho objektu na indikaciu neuvolnenej pamati 
/// </summary>
class MemLeak
{
public:
	~MemLeak() { _CrtDumpMemoryLeaks(); }
};

const MemLeak dummyLeak;

#else
new
#endif // _DEBUG
