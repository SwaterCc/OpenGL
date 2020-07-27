#ifndef _INCLUDE_H_
#define _INCLUDE_H_
#include<iostream>

#define GL3W_SETUP

#if defined(GLAD_SETUP)
#include<glad/glad.h>
#endif

#if defined(GL3W_SETUP)
#include<GL/gl3w.h>
#endif

#include<GLFW/glfw3.h>
#include<assert.h>
#include <cmath>

#include "data.h"




#endif // !_INCLUDE_H_
