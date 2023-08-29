#include <stdio.h>
#include "raylib.h"
#include "raymath.h"
void Joguinho();
int main()
{
    Joguinho();
    return 0;
}
void Joguinho(){
    int lar = 720, alt = 540;
    InitWindow(lar, alt, "Jogo");
    Image imagem = LoadImage("fundo2.png");
    ImageResizeNN(&imagem, lar, alt);
    Image personagem = LoadImage("personagem.png");
    ImageResizeNN(&personagem, 110, 110);
    Texture2D perso = LoadTextureFromImage(personagem);
    Texture2D textura = LoadTextureFromImage(imagem);
    int x = lar/2, y = 430, space = 0, cont = 0;
    char dir = 'D';
    while (!WindowShouldClose())
    {
        if (space >= 0 && y <= 430)
        {
            WaitTime(0.01);
            space -= 1;
            y += 1;
        }
        if(cont == 1 && space == 0){
            cont = 0;
        }
        Vector2 mouse = GetMousePosition();
        //printf("%f-%f\n", mouse.x, mouse.y);
        if (IsKeyDown(KEY_RIGHT))
        {
            x += 1;
            if (dir == 'E')
            {
                dir = 'D';
                ImageFlipHorizontal(&personagem);
                perso = LoadTextureFromImage(personagem);
            }
            
        }
        if (IsKeyDown(KEY_LEFT))
        {
            x -= 1;
            if (dir == 'D')
            {
                dir = 'E';
                ImageFlipHorizontal(&personagem);
                perso = LoadTextureFromImage(personagem);
            }
        }
        if (IsKeyPressed(KEY_SPACE) && cont == 0)
        {
            // for (int i = 1; i <= 40; i++)
            // {
            //     WaitTime(0.05);
            //     DrawTexture(perso, x, y - i, WHITE);
            // }
            y -= 40;
            space = 40;
            cont = 1;
        }
        printf("%d\n", y);
        BeginDrawing();
        DrawTexture(textura, 0, 0, WHITE);
        DrawTexture(perso, x, y, WHITE);
        DrawText("Jogo iniciado", 100, 100, 30, RED);
        EndDrawing();
    }
}