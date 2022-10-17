#include "../src/include/App.h"


int main(int argc, char* argv[])
{
    App app;

    CreateApp(&app, "data/AppCfg.ini");

    Run(&app);

    return 0;
}
