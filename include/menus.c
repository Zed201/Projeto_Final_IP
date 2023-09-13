#include "raylib.h"
#include "menus.h"
#include <string.h>
#include "structs.h"
#include "defs.h"

void Manual(){
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
    botao start, sair, comecar;
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
    Texture2D start_image = LoadTexture("assets/imgs/start.png");
    Texture2D sair_image = LoadTexture("assets/imgs/sair.png");

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
            //DrawRectangleRec(start.frame, RED);
            //DrawText(start.string, posX_Ret + 80, 170 + 25, 35, WHITE);
            // se for colocar essas imagens tem que concertar a colisao, tomando como base a propria imagem
             Rectangle frameRec = { 0.0f, start_image.height/2, start_image.width, start_image.height/2 };
             Vector2 position = {posX_Ret + 80, 170 + 25};
             DrawTextureRec(start_image, frameRec, position, WHITE);

             if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
             {
                 Manual();
            }
        } else {
            Rectangle frameRec = { 0.0f, 0.0f, start_image.width, start_image.height/2 };
             Vector2 position = {posX_Ret + 80, 170 + 25};
             DrawTextureRec(start_image, frameRec, position, WHITE);
           /* DrawRectangleRec(start.frame, fundo);
            DrawText(start.string, posX_Ret + 80, 170 + 25, 35, BLACK);
            */
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
    CloseWindow();
}