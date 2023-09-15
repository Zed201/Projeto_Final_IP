#include "raylib.h"
#include "menus.h"
#include <string.h>
#include "structs.h"
#include "defs.h"
void transicao1(){
        Texture2D transicao1 = LoadTextureFromImage(LoadImage("assets/imgs/fase1-inicio.png"));
        while (!WindowShouldClose())
        {
            BeginDrawing();
            DrawTexture(transicao1, 0, 0, WHITE);
            EndDrawing();
            WaitTime(transition_time);
            UnloadTexture(transicao1);
            jogo_fase1();
        }
        
}

void transicao2(){
        Texture2D transicao2 = LoadTextureFromImage(LoadImage("assets/imgs/fase2-inicio.png"));
        while (!WindowShouldClose())
        {
            BeginDrawing();
            DrawTexture(transicao2, 0, 0, WHITE);
            EndDrawing();
            WaitTime(transition_time);
            UnloadTexture(transicao2);
            jogo_fase2();
            //Manual();
        }
        
}
void Manual(){
    botao comecar;
    comecar.frame.height = 160/2;
    comecar.frame.width = 255;
    comecar.frame.x = 225;
    comecar.frame.y = 400;

    comecar.ImagemOut = LoadImage("assets/imgs/comecar_out.png");
    comecar.ImagemIn = LoadImage("assets/imgs/comecar_in.png");
    ImageResize(&comecar.ImagemIn, comecar.frame.width, comecar.frame.height);
    ImageResize(&comecar.ImagemOut, comecar.frame.width, comecar.frame.height);
    Texture2D comecar_texture_out = LoadTextureFromImage(comecar.ImagemOut);
    Texture2D comecar_texture_in = LoadTextureFromImage(comecar.ImagemIn);
    Color fundo = {181, 190, 194, 232};

    Texture2D manual_png = LoadTextureFromImage(LoadImage("assets/imgs/manual.png"));

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_O))
        {
            CloseWindow();
        }
        Vector2 pos = GetMousePosition();
        BeginDrawing();
        ClearBackground(fundo);
        DrawTexture(manual_png, 80, 60, WHITE);
        
        if (CheckCollisionPointRec(pos, comecar.frame))
        {
            DrawTexture(comecar_texture_in, comecar.frame.x, comecar.frame.y, WHITE);
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                UnloadTexture(manual_png);
                //jogo_fase1();
                transicao1();
            }
        } else {
            DrawTexture(comecar_texture_out, comecar.frame.x, comecar.frame.y, WHITE);
        }
        EndDrawing();
    }
    UnloadTexture(manual_png);
}

void Menu_Inicial(){
    // tentar reduzir isso um pouco
    botao start, sair;
    start.frame.height = 160/2;
    start.frame.width = 250;
    start.frame.x = 240;
    start.frame.y = 170;

    sair.frame.height = 155/2;
    sair.frame.width = 255;
    sair.frame.x = 240;
    sair.frame.y = 350;

    Color fundo = {181, 190, 194, 232};
    InitWindow(lar, alt, "Joguinho Massa");
    start.ImagemOut = LoadImage("assets/imgs/start_out.png");
    start.ImagemIn = LoadImage("assets/imgs/start_in.png");
    ImageResize(&start.ImagemIn, start.frame.width, start.frame.height);
    ImageResize(&start.ImagemOut, start.frame.width, start.frame.height);
    Texture2D start_texture_out = LoadTextureFromImage(start.ImagemOut);
    Texture2D start_texture_in = LoadTextureFromImage(start.ImagemIn);

    sair.ImagemOut = LoadImage("assets/imgs/sair_out.png");
    sair.ImagemIn = LoadImage("assets/imgs/sair_in.png");
    ImageResize(&sair.ImagemIn, sair.frame.width, sair.frame.height);
    ImageResize(&sair.ImagemOut, sair.frame.width, sair.frame.height);
    Texture2D sair_texture_out = LoadTextureFromImage(sair.ImagemOut);
    Texture2D sair_texture_in = LoadTextureFromImage(sair.ImagemIn);

    
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_O))
        {
            CloseWindow();
        }
        Vector2 pos = GetMousePosition();
        BeginDrawing();
        ClearBackground(fundo);
        if (CheckCollisionPointRec(pos, start.frame))
        {
            DrawTexture(start_texture_in, start.frame.x, start.frame.y, WHITE);
            
             if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
             {
                UnloadImage(start.ImagemOut);
                UnloadImage(start.ImagemIn);
                UnloadTexture(start_texture_in);
                UnloadTexture(start_texture_out);
                UnloadImage(sair.ImagemOut);
                UnloadImage(sair.ImagemIn);
                UnloadTexture(start_texture_in);
                UnloadTexture(sair_texture_out);
                 Manual();
            }
        } else {
           DrawTexture(start_texture_out, start.frame.x, start.frame.y, WHITE);
        }
        if (CheckCollisionPointRec(pos, sair.frame))
        {
            DrawTexture(sair_texture_in, sair.frame.x, sair.frame.y, WHITE);
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                UnloadImage(start.ImagemOut);
                UnloadImage(start.ImagemIn);
                UnloadTexture(start_texture_in);
                UnloadTexture(start_texture_out);
                UnloadImage(sair.ImagemOut);
                UnloadImage(sair.ImagemIn);
                UnloadTexture(start_texture_in);
                UnloadTexture(sair_texture_out);
                CloseWindow();
            }
        
        } else {
           DrawTexture(sair_texture_out, sair.frame.x, sair.frame.y, WHITE);
        }
        EndDrawing();
    }
    
    CloseWindow();
}