#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "raylib.h"
#include "defs.h"
#include "saveTime.c"
#include "fase1.c"
#include "menus.c"

int main()
{ 
    jogo_fase2();
    return 0 ;
}
void jogo_fase2() {
    InitWindow(lar, alt, "Testando");
    Image fundo = LoadImage("assets/imgs/fundo2.png");
    ImageResizeNN(&fundo, lar, alt);
    Texture2D textura_fundo = LoadTextureFromImage(fundo);

    // Inicializacao do personagem
    personagem persona1;
    persona1.target.height = 97;
    persona1.target.width = 86;
    Image personagem = LoadImage("assets/imgs/acm.png");
    ImageResizeNN(&personagem, 86, 97);
    ImageFlipHorizontal(&personagem);
    persona1.textura = LoadTextureFromImage(personagem);
    // ajustar esse valor onde ele começa, o 414 no caso, quando for trocar de sprite
    persona1.target.x = lar / 2, persona1.target.y = 414;
    // ajustar a qtd de vida
    persona1.vida = perso_lifes, persona1.dash = true, persona1.Jump = true;

    // Inicializacao da espada/arma e flip dela para acertar a posicao
    arma Espada;
    Espada.posEspada = 0;
    Image Espe_im = LoadImage("assets/imgs/espada.png");
    ImageFlipHorizontal(&Espe_im);
    // se ligar que se mudar o tamanho tem que verificar as alteracoes para ficar certinha com o personagem
    ImageResizeNN(&Espe_im, espe_tam, espe_tam);
    Espada.textura = LoadTextureFromImage(Espe_im);
    Espada.target.height = Espada.textura.height;
    Espada.target.width = Espada.textura.width;

    // Parte de audio
    InitAudioDevice();
    Music musica = LoadMusicStream("assets/sounds/zelda.mp3");
    PlayMusicStream(musica);
    Sound jumpS = LoadSoundFromWave(LoadWave("assets/sounds/sound.wav"));

    // Parte dos inimigos, inicializacao deles
    Color cores[5] = {RED, BLACK, YELLOW, GREEN, BLUE};
    inimigo inimigos[enemy_qtd];
    Image ponteiros = LoadImage("assets/imgs/ponteiro.png");
    ImageResizeNN(&ponteiros, enemy_heigth, enemy_width);
    for (int i = 0; i < enemy_qtd; i++)
    {
        inimigos[i].textura = LoadTextureFromImage(ponteiros);
        inimigos[i].target.x = GetRandomValue(0, lar - 20);
        inimigos[i].target.y = -45;
        inimigos[i].target.width = enemy_width;
        inimigos[i].target.height = enemy_heigth;
        // por enquanto nenhuma textura
        inimigos[i].velo = GetRandomValue(1,3);
        inimigos[i].morto = 'N';
        inimigos[i].chao = 'N';
    }

    // Variaveis de controle
    int space = 0, dash_counter = 0, qtd_mortos = 0, lol = 0;
    char dir = 'D', Espa_Cont = 'C';
    bool hit = true;
    SetTargetFPS(40);
    while (!WindowShouldClose())
    {
        // Atualizacao da colisao da arma
        Espada.target.x = Espada.posEspada + persona1.target.x;
        Espada.target.y = persona1.target.y + 55;

        Vector2 mouse = GetMousePosition();
        double time = GetTime();
        float delta = GetFrameTime();
        SetMasterVolume(5.0);
        //UpdateMusicStream(musica);

        // Logica de movimentacao do personagem
        if(persona1.Jump == 1 && space == 0){
            persona1.Jump = 0;
        }
        // Andar para os lados e flipar o sprite da arma
        if (IsKeyDown(KEY_RIGHT))
        {
            persona1.target.x += 5;
            if (dir == 'E')
            {
                dir = 'D';
                ImageFlipHorizontal(&personagem);
                ImageFlipHorizontal(&Espe_im);
                Espada.textura = LoadTextureFromImage(Espe_im);
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
                ImageFlipHorizontal(&Espe_im);
                Espada.textura = LoadTextureFromImage(Espe_im);
                persona1.textura = LoadTextureFromImage(personagem);
            }
        }
        // dash
        if (IsKeyPressed(KEY_D) && persona1.dash == true)
        {
            persona1.dash = false;
            dash_counter = 0;
        }
        if (!persona1.dash)
        {
            if (dir == 'D')
            {
                persona1.target.x += dash_tam;
                WaitTime(0.001);
            } else {
                persona1.target.x -= dash_tam;
                WaitTime(0.001);
            }
            dash_counter++;
            if (dash_counter == dash_multiper)
            {
                persona1.dash = true;
            }
        }
        // limitador do chao do personagem
        if (persona1.target.y >= 414)
        {
            hit = true, persona1.Jump = true;
        }
        // pulo
        if (IsKeyPressed(KEY_SPACE) && persona1.Jump == true)
        { 
            persona1.velo = -PJS;
            persona1.Jump = false, hit = false;
            PlaySound(jumpS);
        }
        if (!hit)
        {
            persona1.target.y += persona1.velo*delta;
            persona1.velo += G*delta;
            persona1.Jump = false;
        }
        // movimentacao da espada
        if (Espa_Cont == 'B')
        {
            WaitTime(0.003);
            Espa_Cont = 'C';
            ImageFlipVertical(&Espe_im);
            Espada.textura = LoadTextureFromImage(Espe_im);
        }
        if (IsKeyPressed(KEY_P) && Espa_Cont == 'C')
        {
                ImageFlipVertical(&Espe_im);
                Espada.textura = LoadTextureFromImage(Espe_im);
                Espa_Cont = 'B';
        }
        if (dir == 'D')
        {
            // serve para ajustar a posicao da espada junto ao personagem
            Espada.posEspada = 60;
        } else {
            Espada.posEspada = -5;
        }
        
       
        // Controle do inimigo
        if(inimigos[lol].target.y == floor_y) {
           lol += 1;
           inimigos[lol].chao = 'S';
        }
        else {
            inimigos[lol].target.y += 23;
        }
        
            
        for (int i = 0; i < enemy_qtd; i++) {  

            // checagem da colisao do inimigo com a espada
            if (inimigos[i].chao == 'S')
            {
                // primeiro inimigo nao se move por algum motivo
                int dist = persona1.target.x - inimigos[i].target.x;
                if (dist < 0)
                {
                    inimigos[i].target.x -= inimigos[i].velo;
                }
                if (dist > 0)
                {
                    inimigos[i].target.x += inimigos[i].velo;
                }
            }
            if (CheckCollisionRecs(inimigos[i].target, Espada.target) && Espa_Cont == 'B')
            {
                inimigos[i].morto = 'S';
            }
            // checagem da colisao do inimigo com o personagem
            if (CheckCollisionRecs(persona1.target, inimigos[i].target) && inimigos[i].morto == 'N' && persona1.dash == true)
            {
                persona1.vida -= 5;
            }
        }

        BeginDrawing();
        DrawTexture(textura_fundo, 0, 0, WHITE);
        DrawTexture(persona1.textura, persona1.target.x, persona1.target.y, WHITE);
        DrawTexture(Espada.textura, Espada.posEspada + persona1.target.x, persona1.target.y + 55, WHITE);
        // barrinha de vida
        DrawText(TextFormat("Tempo: %.2fs\n", time), 60, 80, 20, RED);
        DrawText("Vida: ", 60, 105, 20, RED);
        // Barrinha de vida
        if ((persona1.vida/10) >= 75)
        {
            DrawRectangle(115, 107, (persona1.vida/10), 17, GREEN);
        } else if ((persona1.vida/10) < 75 && (persona1.vida/10) >= 40)
        {
            DrawRectangle(115, 107, (persona1.vida/10), 17, ORANGE);
        } else if ((persona1.vida/10) < 40 && (persona1.vida/10) > 0)
        {
            DrawRectangle(115, 107, (persona1.vida/10), 17, RED);
        }
        if ((persona1.vida/10) <= 0)
        {
            ClearBackground(WHITE);
            CloseWindow();
        }

        // so desenha o inimigo se ele estiver vivo
        for (int i = 0; i < enemy_qtd; i++)
        {
            
            if (inimigos[i].morto == 'N')
            {
                //DrawRectangleRec(inimigos[i].target, inimigos[i].cor);
                DrawTexture(inimigos[i].textura, inimigos[i].target.x, inimigos[i].target.y, WHITE);
                
            }
            if (inimigos[i].morto == 'S')
            {
                qtd_mortos++;
            }
        }
        if (qtd_mortos == enemy_qtd)
        {
            ClearBackground(WHITE);
            putName(time);
        } else {
            qtd_mortos = 0;
        }

        EndDrawing();
    }
 
    CloseWindow();
}