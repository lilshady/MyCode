#ifndef  DLLTEST_H
#define DLLTEST_H extern "C" __declspec(dllimport)
#endif
#include <Windows.h>
#include <stdio.h>
DLLTEST_H int test();