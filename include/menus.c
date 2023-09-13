#include "raylib.h"
#include "menus.h"
#include <string.h>
#include "structs.h"
#include "defs.h"

void Manual(){
    // concertar a atualizar para a nova struct de botao
    botao comecar;
    comecar.frame.height = 90;
    comecar.frame.width = 280;
    comecar.frame.x = 225;
    comecar.frame.y = 400;
    strcpy(comecar.string, "Começar");
    Color fundo;
    fundo.r = 181;
    fundo.g = 190;
    fundo.b = 194;
    fundo.a = 232;
    Texture2D manual_png = LoadTextureFromImage(LoadImage("assets/imgs/manual.png"));
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_O))
        {
            CloseWindow();
        }

        Vector2 pos = GetMousePosition();
        BeginDrawing();
        ClearBackground(WHITE);
        DrawTexture(manual_png, 80, 60, WHITE);
        
        if (CheckCollisionPointRec(pos, comecar.frame))
        {
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                // colocar pequena transicao que tancreto fez
                jogo_fase1();
            }
            DrawRectangleRec(comecar.frame, RED);
            DrawText(comecar.string, posX_Ret + 80, 400 + 25, 35, WHITE);
        } else {
            DrawRectangleRec(comecar.frame, fundo);
            DrawText(comecar.string, posX_Ret + 80, 400 + 25, 35, BLACK);
        }
        EndDrawing();
    }
    UnloadTexture(manual_png);
}

void Menu_Inicial(){
    // atualizar para a nova struct de botao
    botao start, sair;
    start.frame.height = 90;
    start.frame.width = 280;
    sair.frame.height = 90;
    sair.frame.width = 280;
    start.frame.x = 225;
    start.frame.y = 170;
    sair.frame.x = 225;
    sair.frame.y = 350;
    Color fundo;
    fundo.r = 181;
    fundo.g = 190;
    fundo.b = 194;
    fundo.a = 232;
    strcpy(start.string, "Start");
    strcpy(sair.string, "Sair");
    InitWindow(lar, alt, "Joguinho Massa");
    Image start_image_out = LoadImage("assets/imgs/start_out.png");
    Image start_image_in = LoadImage("assets/imgs/start_in.png");
    ImageResize(&start_image_in, 300, 162/2);
    ImageResize(&start_image_out, 300, 162/2);
    Texture2D start_texture_out = LoadTextureFromImage(start_image_out);
    Texture2D start_texture_in = LoadTextureFromImage(start_image_in);
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_O))
        {
            CloseWindow();
        }
        Vector2 pos = GetMousePosition();
        BeginDrawing();
        ClearBackground(WHITE);
        if (CheckCollisionPointRec(pos, start.frame))
        {
            DrawTexture(start_texture_in, start.frame.x, start.frame.y, WHITE);
            
             if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
             {
                 Manual();
            }
        } else {
           DrawTexture(start_texture_out, start.frame.x, start.frame.y, WHITE);
        }
        if (CheckCollisionPointRec(pos, sair.frame))
        {
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                CloseWindow();
            }
            DrawRectangleRec(sair.frame, RED);
            DrawText(sair.string, posX_Ret + 80, 350 + 25, 35, WHITE);
        } else {
            DrawRectangleRec(sair.frame, fundo);
            DrawText(sair.string, posX_Ret + 80, 350 + 25, 35, BLACK);
        }
        EndDrawing();
    }
    UnloadImage(start_image_out);
    UnloadImage(start_image_in);
    UnloadTexture(start_texture_in);
    UnloadTexture(start_texture_out);
    CloseWindow();
}