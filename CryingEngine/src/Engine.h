#pragma once

#ifdef __linux__
#define __declspec(v)
#endif

namespace Engine{
    __declspec(ddlexport) void printWelcome();
}
