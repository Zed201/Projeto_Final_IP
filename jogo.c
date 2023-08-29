#include <stdio.h>
#include "raylib.h"
#include "raymath.h"
void Joguinho();
int main()
{
    Joguinho();
    return 0;
}
#define G 400
#define PJS 350.0f
#define PHS 200.0f
typedef struct{
    Rectangle target;
    Texture2D textura;
    float speed;
}personagem;
void Joguinho(){
    int lar = 720, alt = 540, jump_height = 60;
    InitWindow(lar, alt, "Jogo");
    personagem persona1;
    persona1.target.height = 110;
    persona1.target.width = 110;
    Image imagem = LoadImage("fundo2.png");
    ImageResizeNN(&imagem, lar, alt);
    Image personagem = LoadImage("personagem.png");
    ImageResizeNN(&personagem, 110, 110);
    persona1.textura = LoadTextureFromImage(personagem);
    Texture2D textura = LoadTextureFromImage(imagem);
    persona1.target.x = lar/2, persona1.target.y = 404;
    int space = 0;
    bool Jump = true, hit = true;
    char dir = 'D';
    InitAudioDevice();
    Sound som = LoadSound("jump.sfx.rfx");
    while (!WindowShouldClose())
    {   
        float delta = GetFrameTime();
        
        //printf("%d\n", fps);
        if(Jump == 1 && space == 0){
            Jump = 0;
        }
        Vector2 mouse = GetMousePosition();
        //printf("%f-%f\n", mouse.x, mouse.y);
        if (IsKeyDown(KEY_RIGHT))
        {
            persona1.target.x += 5;
            if (dir == 'E')
            {
                dir = 'D';
                ImageFlipHorizontal(&personagem);
                persona1.textura = LoadTextureFromImage(personagem);
            }
            
        }
        if (IsKeyDown(KEY_LEFT))
        {
            persona1.target.x -= 5;
            if (dir == 'D')
            {
                dir = 'E';
                ImageFlipHorizontal(&personagem);
                persona1.textura = LoadTextureFromImage(personagem);
            }
        }
        if (IsKeyPressed(KEY_D))
        {
            if (dir == 'D')
            {
                persona1.target.x += 20;
            } else {
                persona1.target.x -= 20;
            }
            
        }
        if (persona1.target.y >= 404)
        {
            hit = true, Jump = true;
        }
        if (IsKeyPressed(KEY_SPACE) && Jump == true)
        { 
            persona1.speed = -PJS;
            Jump = false, hit = false;
        }
        if (!hit)
        {
            persona1.target.y += persona1.speed*delta;
            persona1.speed += G*delta;
            Jump = false;
        }
        
        
        //printf("%f\n", persona1.target.y);
        BeginDrawing();
        DrawTexture(textura, 0, 0, WHITE);
        DrawTexture(persona1.textura, persona1.target.x, persona1.target.y, WHITE);
        //DrawText("Jogo iniciado", 100, 100, 30, RED);
        EndDrawing();
    }
}