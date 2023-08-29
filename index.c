#include <stdio.h>
#include "raylib.h"
#include "jogo.c"
#define posX_Ret 225
void Manual();
int main()
{
    int lar = 720, alt = 540;
    InitWindow(lar, alt, "Testando Menu");
    Image imagem = LoadImage("fundo.png");
    ImageResizeNN(&imagem, lar, alt);
    Texture2D textura = LoadTextureFromImage(imagem);
    while (!WindowShouldClose())
    {
        Vector2 pos = GetMousePosition();
        //printf("%f-%f\n", pos.x, pos.y);
        BeginDrawing();
        DrawTexture(textura, 0, 0, WHITE);
        if (pos.x > posX_Ret && pos.x < 451 && pos.y > 171 && pos.y < 258)
        {
            DrawRectangle(posX_Ret, 170, 280, 90, RED);
            DrawText("Start", posX_Ret + 80, 170 + 25, 35, WHITE);
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                Manual();
            }
        } else {
            DrawRectangle(posX_Ret, 170, 280, 90, GRAY);
            DrawText("Start", posX_Ret + 80, 170 + 25, 35, BLACK);
        }
        if (pos.x > posX_Ret && pos.x < 453 && pos.y > 353 && pos.y < 437)
        {
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                CloseWindow();
            }
            DrawRectangle(posX_Ret, 350, 280, 90, RED);
            DrawText("Sair", posX_Ret + 80, 350 + 25, 35, WHITE);
        } else {
            DrawRectangle(posX_Ret, 350, 280, 90, GRAY);
        DrawText("Sair", posX_Ret + 80, 350 + 25, 35, BLACK);
        }
        
        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
void Manual(){
    while (!WindowShouldClose())
    {
        Vector2 pos = GetMousePosition();
        //printf("%f-%f\n", pos.x, pos.y);
        BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangle(80, 60, 570, 305, GRAY);
        // dois /n e um bom espacamento de linha
        DrawText(TextFormat("MANUAL:\n\nTestando"), 80, 60, 20, BLACK);
        if (pos.x > posX_Ret && pos.x < 453 && pos.y > 400 && pos.y < 487)
        {
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                Joguinho();
            }
            DrawRectangle(posX_Ret, 400, 280, 90, RED);
            DrawText("Começar", posX_Ret + 80, 400 + 25, 35, WHITE);
        } else {
            DrawRectangle(posX_Ret, 400, 280, 90, GRAY);
            DrawText("Começar", posX_Ret + 80, 400 + 25, 35, BLACK);
        }
        EndDrawing();
    }
    
}