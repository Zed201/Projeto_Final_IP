#include "raylib.h"
#include "menus.h"
#include <string.h>
#include "structs.h"
#include "defs.h"

void transicao1() {
        Texture2D transicao1 = LoadTextureFromImage(LoadImage("assets/imgs/fase1-inicio.png"));
        while (!WindowShouldClose()) {
                BeginDrawing();
                DrawTexture(transicao1, 0, 0, WHITE);
                EndDrawing();
                WaitTime(transition_time);
                UnloadTexture(transicao1);
                jogo_fase1();
        }

}

void transicao2(double tempo1) {
        Texture2D transicao2 = LoadTextureFromImage(LoadImage("assets/imgs/fase2-inicio.png"));
        while (!WindowShouldClose()) {
                BeginDrawing();
                DrawTexture(transicao2, 0, 0, WHITE);
                EndDrawing();
                WaitTime(transition_time);
                UnloadTexture(transicao2);
                jogo_fase2(tempo1);
        }

}

void MenuFinal() {
        caixa_texto titulo;
        titulo.frame.height = 90;
        titulo.frame.width = 450;
        titulo.frame.x = 150;
        titulo.frame.y = 93;
        strcpy(titulo.string, "Fim De Jogo");

        botao recomecar, sair;

        recomecar.frame.height = 160 / 2;
        recomecar.frame.width = 255;
        recomecar.frame.x = 225;
        recomecar.frame.y = 280;

        recomecar.ImagemOut = LoadImage("assets/imgs/reload_out.png");
        recomecar.ImagemIn = LoadImage("assets/imgs/reload_in.png");
        ImageResize( & recomecar.ImagemIn, recomecar.frame.width, recomecar.frame.height);
        ImageResize( & recomecar.ImagemOut, recomecar.frame.width, recomecar.frame.height);
        Texture2D recomecar_texture_out = LoadTextureFromImage(recomecar.ImagemOut);
        Texture2D recomecar_texture_in = LoadTextureFromImage(recomecar.ImagemIn);

        sair.frame.height = 160 / 2;
        sair.frame.width = 255;
        sair.frame.x = 225;
        sair.frame.y = 400;

        sair.ImagemOut = LoadImage("assets/imgs/sair_out.png");
        sair.ImagemIn = LoadImage("assets/imgs/sair_in.png");
        ImageResize( & sair.ImagemIn, sair.frame.width, sair.frame.height);
        ImageResize( & sair.ImagemOut, sair.frame.width, sair.frame.height);
        Texture2D sair_texture_out = LoadTextureFromImage(sair.ImagemOut);
        Texture2D sair_texture_in = LoadTextureFromImage(sair.ImagemIn);

        Color fundo = {181,190,194,232};

        bool botao_pressionado, mouse_sobre1, mouse_sobre2;
        while (!WindowShouldClose()) {

                Vector2 pos_mouse = GetMousePosition();
                mouse_sobre1 = CheckCollisionPointRec(pos_mouse, recomecar.frame);
                mouse_sobre2 = CheckCollisionPointRec(pos_mouse, sair.frame);
                botao_pressionado = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

                BeginDrawing();
                ClearBackground(fundo);
                // Titulo

                DrawRectangleRec(titulo.frame, fundo);
                DrawText(titulo.string, posX_Ret - 55, 100, 70, BLACK);
                if (mouse_sobre1) {

                        DrawTexture(recomecar_texture_in, recomecar.frame.x, recomecar.frame.y, WHITE);
                } else {
                        DrawTexture(recomecar_texture_out, recomecar.frame.x, recomecar.frame.y, WHITE);
                }

                if (mouse_sobre1 && botao_pressionado) { // Se o botao "Recomecar" for pressionado...
                        UnloadImage(recomecar.ImagemIn);
                        UnloadImage(recomecar.ImagemOut);
                        UnloadImage(sair.ImagemIn);
                        UnloadImage(sair.ImagemOut);
                        UnloadTexture(sair_texture_in);
                        UnloadTexture(sair_texture_out);
                        UnloadTexture(recomecar_texture_in);
                        UnloadTexture(recomecar_texture_out);
                        Manual();
                }
                //----------------------------------------------------------------------------------------------------------
                //Sair

                if (mouse_sobre2) {
                        DrawTexture(sair_texture_in, sair.frame.x, sair.frame.y, WHITE);
                } else {
                        DrawTexture(sair_texture_out, sair.frame.x, sair.frame.y, WHITE);
                }

                if (mouse_sobre2 && botao_pressionado) { // Se o botao "Sair" for pressionado...
                        CloseWindow();
                }
                EndDrawing();
        }

        CloseWindow();
}

void tela_creditos() {
        botao sair;

        sair.frame.height = 155 / 2;
        sair.frame.width = 255;
        sair.frame.x = 237;
        sair.frame.y = 440;

        sair.ImagemOut = LoadImage("assets/imgs/sair_out.png");
        sair.ImagemIn = LoadImage("assets/imgs/sair_in.png");
        ImageResize( & sair.ImagemIn, sair.frame.width, sair.frame.height);
        ImageResize( & sair.ImagemOut, sair.frame.width, sair.frame.height);
        Texture2D sair_texture_out = LoadTextureFromImage(sair.ImagemOut);
        Texture2D sair_texture_in = LoadTextureFromImage(sair.ImagemIn);

        Image imagem = LoadImage("assets/imgs/tv.png");
        ImageResizeNN( & imagem, lar, alt);
        Texture2D textura = LoadTextureFromImage(imagem);

        Image asterisco = LoadImage("assets/imgs/ponteiro.png");
        ImageResizeNN( & asterisco, 20, 20);
        Texture2D textAsterisco = LoadTextureFromImage(asterisco);

        while (!WindowShouldClose()) {
                if (IsKeyPressed(KEY_O)) {
                        CloseWindow();
                }
                Vector2 pos = GetMousePosition();
                BeginDrawing();
                DrawTexture(textura, 0, 0, WHITE);
                DrawTexture(textAsterisco, 150, 160, WHITE);
                DrawText("ANA MARIA CUNHA", 180, 160, 20, BLACK);
                DrawTexture(textAsterisco, 150, 195, WHITE);
                DrawText("GLEYBSON", 180, 195, 20, BLACK);
                DrawTexture(textAsterisco, 150, 230, WHITE);
                DrawText("RAFAEL PAZ", 180, 230, 20, BLACK);
                DrawTexture(textAsterisco, 150, 265, WHITE);
                DrawText("LUIZ GUSTAVO", 180, 265, 20, BLACK);
                DrawTexture(textAsterisco, 150, 300, WHITE);
                DrawText("TANCREDO", 180, 300, 20, BLACK);
                DrawTexture(textAsterisco, 150, 335, WHITE);
                DrawText("FLAVIO", 180, 335, 20, BLACK);
                if (CheckCollisionPointRec(pos, sair.frame)) {
                        DrawTexture(sair_texture_in, sair.frame.x, sair.frame.y, WHITE);
                        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                                UnloadImage(imagem);
                                UnloadTexture(textura);
                                UnloadImage(asterisco);
                                UnloadTexture(textAsterisco);
                                CloseWindow();
                                Menu_Inicial();
                        }
                } else {
                        DrawTexture(sair_texture_out, sair.frame.x, sair.frame.y, WHITE);
                }
                EndDrawing();
        }
        UnloadImage(imagem);
        UnloadTexture(textura);
        UnloadImage(asterisco);
        UnloadTexture(textAsterisco);
}

void Manual() {
        botao comecar;
        comecar.frame.height = 160 / 2;
        comecar.frame.width = 255;
        comecar.frame.x = 237;
        comecar.frame.y = 440;

        comecar.ImagemOut = LoadImage("assets/imgs/comecar_out.png");
        comecar.ImagemIn = LoadImage("assets/imgs/comecar_in.png");
        ImageResize( & comecar.ImagemIn, comecar.frame.width, comecar.frame.height);
        ImageResize( & comecar.ImagemOut, comecar.frame.width, comecar.frame.height);
        Texture2D comecar_texture_out = LoadTextureFromImage(comecar.ImagemOut);
        Texture2D comecar_texture_in = LoadTextureFromImage(comecar.ImagemIn);
        Color fundo = {181,190,194,232};

        Image imagem = LoadImage("assets/imgs/tv.png");
        ImageResizeNN( & imagem, lar, alt);
        Texture2D textura = LoadTextureFromImage(imagem);

        Texture2D manual_png = LoadTextureFromImage(LoadImage("assets/imgs/manual.png"));

        while (!WindowShouldClose()) {
                if (IsKeyPressed(KEY_O)) {
                        CloseWindow();
                }
                Vector2 pos = GetMousePosition();
                BeginDrawing();

                DrawTexture(textura, 0, 0, WHITE);
                DrawTexture(manual_png, 145, 150, WHITE);

                if (CheckCollisionPointRec(pos, comecar.frame)) {
                        DrawTexture(comecar_texture_in, comecar.frame.x, comecar.frame.y, WHITE);
                        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                                UnloadTexture(manual_png);
                                UnloadTexture(textura);
                                transicao1();
                        }
                } else {
                        DrawTexture(comecar_texture_out, comecar.frame.x, comecar.frame.y, WHITE);
                }
                EndDrawing();
        }
        UnloadTexture(manual_png);
        UnloadTexture(textura);
}

void Historia() {
        botao comecar1;
        comecar1.frame.height = 160 / 2;
        comecar1.frame.width = 255;
        comecar1.frame.x = 387;
        comecar1.frame.y = 440;

        comecar1.ImagemOut = LoadImage("assets/imgs/comecar_out.png");
        comecar1.ImagemIn = LoadImage("assets/imgs/comecar_in.png");
        ImageResize( & comecar1.ImagemIn, comecar1.frame.width, comecar1.frame.height);
        ImageResize( & comecar1.ImagemOut, comecar1.frame.width, comecar1.frame.height);
        Texture2D comecar_texture_out = LoadTextureFromImage(comecar1.ImagemOut);
        Texture2D comecar_texture_in = LoadTextureFromImage(comecar1.ImagemIn);
        Color fundo = {181,190,194,232};

        Image historia_png = LoadImage("assets/imgs/Historia.png");
        ImageResizeNN( & historia_png, lar, alt);
        Texture2D textura = LoadTextureFromImage(historia_png);

        while (!WindowShouldClose()) {
                if (IsKeyPressed(KEY_O)) {
                        CloseWindow();
                }
                Vector2 pos = GetMousePosition();
                BeginDrawing();
                DrawTexture(textura, 0, 0, WHITE);

                if (CheckCollisionPointRec(pos, comecar1.frame)) {
                        DrawTexture(comecar_texture_in, comecar1.frame.x, comecar1.frame.y, WHITE);
                        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                                UnloadTexture(textura);
                                UnloadImage(historia_png);
                                UnloadTexture(comecar_texture_out);
                                UnloadTexture(comecar_texture_in);
                                Manual();

                        }
                } else {
                        DrawTexture(comecar_texture_out, comecar1.frame.x, comecar1.frame.y, WHITE);
                }
                EndDrawing();
        }
}

void Menu_Inicial() {
        botao start, sair, creditos;
        start.frame.height = 160 / 2;
        start.frame.width = 250;
        start.frame.x = 245;
        start.frame.y = 350;

        sair.frame.height = 155 / 2;
        sair.frame.width = 255;
        sair.frame.x = 245;
        sair.frame.y = 440;

        creditos.frame.height = 155 / 4;
        creditos.frame.width = 255 / 2;
        creditos.frame.x = 20;
        creditos.frame.y = 20;

        Color fundo = {181,190,194,232};
        InitWindow(lar, alt, "Joguinho Massa");
        start.ImagemOut = LoadImage("assets/imgs/start_out.png");
        start.ImagemIn = LoadImage("assets/imgs/start_in.png");
        ImageResize( & start.ImagemIn, start.frame.width, start.frame.height);
        ImageResize( & start.ImagemOut, start.frame.width, start.frame.height);
        Texture2D start_texture_out = LoadTextureFromImage(start.ImagemOut);
        Texture2D start_texture_in = LoadTextureFromImage(start.ImagemIn);

        sair.ImagemOut = LoadImage("assets/imgs/sair_out.png");
        sair.ImagemIn = LoadImage("assets/imgs/sair_in.png");
        ImageResize( & sair.ImagemIn, sair.frame.width, sair.frame.height);
        ImageResize( & sair.ImagemOut, sair.frame.width, sair.frame.height);
        Texture2D sair_texture_out = LoadTextureFromImage(sair.ImagemOut);
        Texture2D sair_texture_in = LoadTextureFromImage(sair.ImagemIn);

        creditos.ImagemOut = LoadImage("assets/imgs/creditos_out.png");
        creditos.ImagemIn = LoadImage("assets/imgs/creditos_in.png");
        ImageResize( & creditos.ImagemIn, creditos.frame.width, creditos.frame.height);
        ImageResize( & creditos.ImagemOut, creditos.frame.width, creditos.frame.height);
        Texture2D creditos_texture_out = LoadTextureFromImage(creditos.ImagemOut);
        Texture2D creditos_texture_in = LoadTextureFromImage(creditos.ImagemIn);

        Image imagem = LoadImage("assets/imgs/grad.png");
        ImageResizeNN( & imagem, lar, alt);
        Texture2D textura = LoadTextureFromImage(imagem);

        Texture2D title1 = LoadTextureFromImage(LoadImage("assets/imgs/titulo1.png"));
        Texture2D title2 = LoadTextureFromImage(LoadImage("assets/imgs/titulo2.png"));

        while (!WindowShouldClose()) {
                if (IsKeyPressed(KEY_O)) {
                        CloseWindow();
                }
                Vector2 pos = GetMousePosition();
                BeginDrawing();
                DrawTexture(textura, 0, 0, WHITE);
                DrawTexture(title1, 300, 210, WHITE);
                DrawTexture(title2, 225, 260, WHITE);
                if (CheckCollisionPointRec(pos, start.frame)) {
                        DrawTexture(start_texture_in, start.frame.x, start.frame.y, WHITE);

                        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                                UnloadImage(imagem);
                                UnloadTexture(textura);
                                UnloadImage(start.ImagemOut);
                                UnloadImage(start.ImagemIn);
                                UnloadTexture(start_texture_in);
                                UnloadTexture(start_texture_out);
                                UnloadImage(sair.ImagemOut);
                                UnloadImage(sair.ImagemIn);
                                UnloadTexture(sair_texture_in);
                                UnloadTexture(sair_texture_out);
                                UnloadImage(creditos.ImagemOut);
                                UnloadImage(creditos.ImagemIn);
                                UnloadTexture(creditos_texture_in);
                                UnloadTexture(creditos_texture_out);
                                Historia();
                        }
                } else {
                        DrawTexture(start_texture_out, start.frame.x, start.frame.y, WHITE);
                }
                if (CheckCollisionPointRec(pos, sair.frame)) {
                        DrawTexture(sair_texture_in, sair.frame.x, sair.frame.y, WHITE);
                        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                                UnloadImage(imagem);
                                UnloadTexture(textura);
                                UnloadImage(start.ImagemOut);
                                UnloadImage(start.ImagemIn);
                                UnloadTexture(start_texture_in);
                                UnloadTexture(start_texture_out);
                                UnloadImage(sair.ImagemOut);
                                UnloadImage(sair.ImagemIn);
                                UnloadTexture(sair_texture_in);
                                UnloadTexture(sair_texture_out);
                                UnloadImage(creditos.ImagemOut);
                                UnloadImage(creditos.ImagemIn);
                                UnloadTexture(creditos_texture_in);
                                UnloadTexture(creditos_texture_out);
                                CloseWindow();
                        }

                } else {
                        DrawTexture(sair_texture_out, sair.frame.x, sair.frame.y, WHITE);
                }

                if (CheckCollisionPointRec(pos, creditos.frame)) {
                        DrawTexture(creditos_texture_in, creditos.frame.x, creditos.frame.y, WHITE);
                        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                                tela_creditos();
                        }

                } else {
                        DrawTexture(creditos_texture_out, creditos.frame.x, creditos.frame.y, WHITE);
                }

                EndDrawing();
        }
        UnloadImage(imagem);
        UnloadTexture(textura);
        UnloadImage(start.ImagemOut);
        UnloadImage(start.ImagemIn);
        UnloadTexture(start_texture_in);
        UnloadTexture(start_texture_out);
        UnloadImage(sair.ImagemOut);
        UnloadImage(sair.ImagemIn);
        UnloadTexture(sair_texture_in);
        UnloadTexture(sair_texture_out);
        UnloadImage(creditos.ImagemOut);
        UnloadImage(creditos.ImagemIn);
        UnloadTexture(creditos_texture_in);
        UnloadTexture(creditos_texture_out);
        CloseWindow();
}