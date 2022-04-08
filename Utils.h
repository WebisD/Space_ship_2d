#pragma once
#include <random>

#ifndef _UTILS_H_
#define _UTILS_H_

class Utils
{
public:
	static int RandNumberX();
	static int RandNumberY();
	static inline int MIN_Y = 100;
	static inline int MAX_Y = 668;
	static inline int MIN_X = 1024;
	static inline int MAX_X = 1324;
};

#endif
