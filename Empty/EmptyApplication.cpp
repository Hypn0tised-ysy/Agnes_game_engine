#include "BaseApplication.hpp"
#include "GfxConfiguration.h"

namespace My {
    GfxConfiguration config;
    BaseApplication g_App(config);
    IApplication* g_pApp = &g_App;
}
