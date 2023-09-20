#include "fase1.h"
#include "raylib.h"
#include "structs.h"
#include "defs.h"

void jogo_fase1() {
        //------------------------------------------------------
        Image amc_img = LoadImage("assets/imgs/amc_gif.png");
        ImageResizeNN( & amc_img, 600, 100);
        Texture2D amc = LoadTextureFromImage(amc_img);

        int sprite_w = 100, sprite_h = 100, sprite_index = 0;
        float frame_s = 0;
        bool left = true, right = false;
        //-------------------------------------------------------
        // Inicializacao do fundo
        Image fundo = LoadImage("assets/imgs/fundo2.png");
        ImageResizeNN( & fundo, lar, alt);
        Texture2D textura_fundo = LoadTextureFromImage(fundo);

        // Inicializacao do personagem
        personagem persona1;
        persona1.velo = 0;
        persona1.target.height = 97;
        persona1.target.width = 86;
        Image personagem = LoadImage("assets/imgs/acm1.png");
        ImageResizeNN( & personagem, 86, 97);
        ImageFlipHorizontal( & personagem);
        persona1.textura = LoadTextureFromImage(personagem);
        persona1.target.x = lar / 2, persona1.target.y = 414;
        persona1.vida = perso_lifes, persona1.dash = true, persona1.Jump = true;

        // Inicializacao da espada/arma e flip dela para acertar a posicao
        arma Espada;
        Espada.posEspada = 0;
        Image Espe_im = LoadImage("assets/imgs/espadinha.png");
        ImageFlipHorizontal( & Espe_im);
        // se ligar que se mudar o tamanho tem que verificar as alteracoes para ficar certinha com o personagem
        ImageResizeNN( & Espe_im, espe_tam, espe_tam);
        Espada.textura = LoadTextureFromImage(Espe_im);
        Espada.target.height = Espada.textura.height;
        Espada.target.width = Espada.textura.width;

        // Parte de audio
        Music musica = LoadMusicStream("assets/sounds/music.mp3");
        PlayMusicStream(musica);
        SetMusicVolume(musica, 5);
        Sound jumpS = LoadSoundFromWave(LoadWave("assets/sounds/sound.wav"));

        // Parte dos inimigos, inicializacao deles
        inimigo inimigos[enemy_qtd];
        Image ponteiros = LoadImage("assets/imgs/ponteiro.png");
        ImageResizeNN( & ponteiros, enemy_heigth, enemy_width);
        for (int i = 0; i < enemy_qtd; i++) {
                inimigos[i].textura = LoadTextureFromImage(ponteiros);
                if (GetRandomValue(0, 1) == 0) { // inimigo nascem na diretia
                        inimigos[i].target.x = GetRandomValue(100, 400) + lar;
                } else {
                        // inimigos que nascem na esquerda
                        inimigos[i].target.x = 0;
                        inimigos[i].target.x -= GetRandomValue(100, 400);
                }
                inimigos[i].target.y = floor_y;
                inimigos[i].target.width = enemy_width;
                inimigos[i].target.height = enemy_heigth;
                inimigos[i].velo = GetRandomValue(1, 3);
                inimigos[i].morto = 'N';
        }

        // Variaveis de controle
        int space = 0, dash_counter = 0, qtd_mortos = 0;
        char dir = 'D', Espa_Cont = 'C';
        bool hit = true;
        double tempo1 = GetTime();
        SetTargetFPS(40);
        while (!WindowShouldClose()) {
                //----------------------
                frame_s++;
                //----------------------        
                if (IsKeyPressed(KEY_O)) {
                        CloseWindow();
                }
                // Atualizacao da colisao da arma
                Espada.target.x = espe_pos_x;
                Espada.target.y = espe_pos_y;

                double time = GetTime() - tempo1;
                float delta = GetFrameTime();
                SetMasterVolume(5.0);
                UpdateMusicStream(musica);

                // Logica de movimentacao do personagem
                if (persona1.Jump == 1 && space == 0) {
                        persona1.Jump = 0;
                }

                sprite_index = 0;

                // Andar para os lados e flipar o sprite da arma
                if (IsKeyDown(KEY_RIGHT) && persona1.target.x + persona1.textura.width < lar) {
                        sprite_index = frame_s;
                        persona1.target.x += 5;
                        if (dir == 'E') {
                                dir = 'D';

                                ImageFlipHorizontal( & personagem);
                                ImageFlipHorizontal( & Espe_im);
                                Espada.textura = LoadTextureFromImage(Espe_im);
                                persona1.textura = LoadTextureFromImage(personagem);

                        }
                        //----------------------------------
                        if (left == true) {
                                sprite_w = sprite_w * -1;
                                right = true;
                                left = false;
                        }
                        //----------------------------------
                }
                if (IsKeyDown(KEY_LEFT) && persona1.target.x > 0) {
                        sprite_index = frame_s;
                        persona1.target.x -= 5;
                        if (dir == 'D') {
                                dir = 'E';
                                ImageFlipHorizontal( & personagem);
                                ImageFlipHorizontal( & Espe_im);
                                Espada.textura = LoadTextureFromImage(Espe_im);
                                persona1.textura = LoadTextureFromImage(personagem);
                        }
                        //---------------------------
                        if (right == true) {
                                sprite_w = sprite_w * -1;
                                left = true;
                                right = false;
                        }
                        //--------------------------
                }
                // dash
                if (IsKeyPressed(KEY_D) && persona1.dash == true) { // 70 é um valor arbitrário  que eu coloquei com base no sprite do personagem
                        if (persona1.target.x > border_extender && persona1.target.x + persona1.textura.width < lar - border_extender) {
                                persona1.dash = false;
                                dash_counter = 0;
                        } else if ((persona1.target.x < border_extender) && dir == 'D') {
                                persona1.dash = false;
                                dash_counter = 0;
                        } else if (persona1.target.x + persona1.textura.width > lar - border_extender && dir == 'E') {
                                persona1.dash = false;
                                dash_counter = 0;
                        }
                }
                if (!persona1.dash) {
                        if (dir == 'D') {
                                persona1.target.x += dash_tam;
                                WaitTime(0.001);
                        } else {
                                persona1.target.x -= dash_tam;
                                WaitTime(0.001);
                        }
                        dash_counter++;
                        if (dash_counter == dash_multiper) {
                                persona1.dash = true;
                        }
                }
                // limitador do chao do personagem
                if (persona1.target.y >= 414) {
                        hit = true, persona1.Jump = true;
                }
                // pulo
                if (IsKeyPressed(KEY_SPACE) && persona1.Jump == true) {
                        persona1.velo = -PJS;
                        persona1.Jump = false, hit = false;
                        //PlaySound(jumpS);
                }
                if (!hit) {
                        persona1.target.y += persona1.velo * delta;
                        persona1.velo += G * delta;
                        persona1.Jump = false;
                }
                // movimentacao da espada
                if (Espa_Cont == 'B') {
                        WaitTime(0.003);
                        Espa_Cont = 'C';
                        ImageFlipVertical( & Espe_im);
                        Espada.textura = LoadTextureFromImage(Espe_im);
                }
                if (IsKeyPressed(KEY_P) && Espa_Cont == 'C') {
                        ImageFlipVertical( & Espe_im);
                        Espada.textura = LoadTextureFromImage(Espe_im);
                        Espa_Cont = 'B';
                }
                if (dir == 'D') {
                        // serve para ajustar a posicao da espada junto ao personagem
                        Espada.posEspada = 60;
                } else {
                        Espada.posEspada = -5;
                }

                // Controle do inimigo
                for (int i = 0; i < enemy_qtd; i++) {
                        int dist = persona1.target.x - inimigos[i].target.x;
                        if (dist < 0) {
                                inimigos[i].target.x -= inimigos[i].velo;
                        }
                        if (dist > 0) {
                                inimigos[i].target.x += inimigos[i].velo;
                        }
                        // checagem da colisao do inimigo com a espada
                        if (CheckCollisionRecs(inimigos[i].target, Espada.target) && Espa_Cont == 'B') {
                                inimigos[i].morto = 'S';
                        }
                        // checagem da colisao do inimigo com o personagem
                        if (CheckCollisionRecs(persona1.target, inimigos[i].target) && inimigos[i].morto == 'N' && persona1.dash == true) {
                                persona1.vida -= 5;
                        }
                }

                BeginDrawing();
                DrawTexture(textura_fundo, 0, 0, WHITE);
                DrawTexture(persona1.textura, persona1.target.x, persona1.target.y, WHITE);
                //-------------------------------------------
                //define qual imagem vai escolher

                int sprite_select = sprite_index * sprite_w;
                Rectangle source = (Rectangle) {
                        sprite_select,
                        0,
                        sprite_w,
                        sprite_h
                };

                //define o onde ela a textura vai ficar
                DrawTextureRec(amc, source, (Vector2) {
                        persona1.target.x, persona1.target.y
                }, WHITE);
                //--------------------------------------------
                // barrinha de vida
                DrawText(TextFormat("Tempo: %.2fs\n", time), 35, 65, 20, RED);
                DrawText("Vida: ", 35, 90, 20, RED);
                // Barrinha de vida
                if ((persona1.vida / 10) >= 75) {
                        DrawRectangle(92, 93, (persona1.vida / 10), 17, GREEN);
                } else if ((persona1.vida / 10) < 75 && (persona1.vida / 10) >= 40) {
                        DrawRectangle(92, 93, (persona1.vida / 10), 17, ORANGE);
                } else if ((persona1.vida / 10) < 40 && (persona1.vida / 10) > 0) {
                        DrawRectangle(92, 93, (persona1.vida / 10), 17, RED);
                }
                if ((persona1.vida / 10) <= 0) {
                        MenuFinal();
                }
                if (dir == 'E') {
                        printf("E\n");
                        DrawTexture(Espada.textura, Espada.target.x + 15, Espada.target.y, WHITE);
                } else if (dir == 'D') {
                        printf("D\n");
                        DrawTexture(Espada.textura, Espada.target.x - 11, Espada.target.y, WHITE);
                }

                // so desenha o inimigo se ele estiver vivo
                for (int i = 0; i < enemy_qtd; i++) {

                        if (inimigos[i].morto == 'N') {
                                DrawTexture(inimigos[i].textura, inimigos[i].target.x, inimigos[i].target.y, WHITE);
                        }
                        if (inimigos[i].morto == 'S') {
                                qtd_mortos++;
                        }
                }
                if (qtd_mortos == enemy_qtd) {
                        ClearBackground(WHITE);
                        UnloadImage(fundo);
                        UnloadTexture(textura_fundo);
                        UnloadImage(personagem);
                        UnloadTexture(persona1.textura);
                        UnloadImage(Espe_im);
                        UnloadTexture(Espada.textura);
                        //UnloadMusicStream(musica);
                        //UnloadSound(jumpS);
                        UnloadImage(ponteiros);
                        //---------------------------
                        UnloadTexture(amc);
                        //---------------------------
                        for (int i = 0; i < enemy_qtd; i++) {
                                UnloadTexture(inimigos[i].textura);
                        }
                        transicao2(time);
                } else {
                        qtd_mortos = 0;
                }

                EndDrawing();
        }
}