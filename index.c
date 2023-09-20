#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "raylib.h"
#include "include/defs.h"
#include "include/structs.h"
#include "include/menus.h"
#include "include/saveTime.h"
#include "include/fase1.h"
#include "include/fase2.h"

 
int main()
{
    InitAudioDevice();
    Menu_Inicial();
    CloseAudioDevice();
    return 0;
}


 
