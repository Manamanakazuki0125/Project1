#include "Debug.h"

void Debug::LogDxError(const char* msg, HRESULT hr, const char* file, int line)
{
    std::stringstream ss;
    ss << "[DX11 Error] " << msg << "\n"
        << "  HRESULT: 0x" << std::hex << std::setw(8) << std::setfill('0') << hr << "\n"
        << "  File   : " << file << "\n"
        << "  Line   : " << line << "\n";

    OutputDebugStringA(ss.str().c_str());
}





