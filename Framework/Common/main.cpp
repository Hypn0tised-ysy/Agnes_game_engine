#include <stdio.h>
#include "IApplication.hpp"

using namespace My;

namespace My{
    extern IApplication* g_pApp;//g stands for global while p stands for pointer 
}

int main()
{
    int ret;

    if(( ret=( g_pApp->Initialize()) )!=0)
    {
        printf("Application Initialize failed with error code %d\n", ret);
        return ret;
    }

    while(!g_pApp->IsQuit())
    {
        g_pApp->Tick();
    }

    g_pApp->Finalize();

    return 0;
}