#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "raylib.h"
#include "include/defs.h"
#include "include/structs.h"
// por algum motivo os .h nao entendem, apenas os .c, mas em outros pcs parecem que funciona normal, nem no notpad ta funcionando
#include "include/saveTime.c"
#include "include/fase1.c"
#include "include/menus.c"

int main()
{ 
    Menu_Inicial();
    return 0;
}
