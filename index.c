#include <stdio.h>
#include "raylib.h"

int main(){
    int lar = 600, alt = 600;
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
        if (pos.x > 172 && pos.x < 451 && pos.y > 171 && pos.y < 258)
        {
            DrawRectangle(170, 170, 280, 90, RED);
            DrawText("Start", 170 + 80, 170 + 25, 35, WHITE);
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                teste();
            }
        } else {
            DrawRectangle(170, 170, 280, 90, GRAY);
            DrawText("Start", 170 + 80, 170 + 25, 35, BLACK);
        }
        if (pos.x > 172 && pos.x < 453 && pos.y > 353 && pos.y < 437)
        {
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                CloseWindow();
            }
            DrawRectangle(170, 350, 280, 90, RED);
            DrawText("Sair", 170 + 80, 350 + 25, 35, WHITE);
        } else {
            DrawRectangle(170, 350, 280, 90, GRAY);
        DrawText("Sair", 170 + 80, 350 + 25, 35, BLACK);
        }
        
        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
void teste(){
    while (!WindowShouldClose())
    {
        Vector2 pos = GetMousePosition();
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("TEstando", 100, 100, 20, BLACK);
        if (pos.x > 172 && pos.x < 453 && pos.y > 353 && pos.y < 437)
        {
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                CloseWindow();
            }
            DrawRectangle(170, 350, 280, 90, RED);
            DrawText("Sair", 170 + 80, 350 + 25, 35, WHITE);
        } else {
            DrawRectangle(170, 350, 280, 90, GRAY);
        DrawText("Sair", 170 + 80, 350 + 25, 35, BLACK);
        }
        EndDrawing();
    }
    
}