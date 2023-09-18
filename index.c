
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "raylib.h"
#include "include/defs.h"
#include "include/structs.h"
#include "include/menus.h"
// por algum motivo os .h nao entendem, apenas os .c, mas em outros pcs parecem que funciona normal, nem no notpad ta funcionando
#include "include/saveTime.h"
#include "include/fase1.h"
#include "include/fase2.h"


int main()
{
    InitAudioDevice();
    Menu_Inicial();
    return 0;
}


 
