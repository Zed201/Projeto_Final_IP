#include "raylib.h"
#include "saveTime.h"
#include <stdlib.h>
#include <stdio.h>
#include "structs.h"
#include "defs.h"

void save(char *name, float time){
    //salvar tempo em arquivo txt
    FILE *arq;
    arq = fopen("saves.txt", "a");
    if(arq == NULL){
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    fprintf(arq, "%s,%f\n", name, time);
    fclose(arq);
}
void viewSaves(){
    Color fundo = {181, 190, 194, 232};
    botao voltar;
    //coordenadas do botao
    voltar.frame.height = 160/2;
    voltar.frame.width = 280;
    //dimensoes do botao•
    voltar.frame.x = 225;
    voltar.frame.y = 440;

    voltar.ImagemOut = LoadImage("assets/imgs/sair_out.png");
    voltar.ImagemIn = LoadImage("assets/imgs/sair_in.png");
    ImageResize(&voltar.ImagemIn, voltar.frame.width, voltar.frame.height);
    ImageResize(&voltar.ImagemOut, voltar.frame.width, voltar.frame.height);
    Texture2D voltar_texture_out = LoadTextureFromImage(voltar.ImagemOut);
    Texture2D voltar_texture_in = LoadTextureFromImage(voltar.ImagemIn);
    
    Image imagem = LoadImage("assets/imgs/tv.png");
    ImageResizeNN(&imagem, lar, alt);
    Texture2D textura = LoadTextureFromImage(imagem);
    
    Record *saves=NULL;
    Record *aux=NULL;
    Record auxTroca;
    int qtdSaves=0;
    int i=0, j=0;
    
    //ler arquivo
    FILE *arq;
    arq = fopen("saves.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    while(!feof(arq)){
        aux = saves;
        saves = (Record*) realloc(aux, (qtdSaves+1)*sizeof(Record));
        if(saves == NULL){
            printf("Problema de alocacao!\n");
            free(aux);
            exit(1);
        }
        fscanf(arq, "%49[^,],%f\n", saves[qtdSaves].name, &saves[qtdSaves].time);
        qtdSaves++;
    }
    fclose(arq);
    //ordenar saves pelo tempo(menor)
    for(i=0; i<qtdSaves; i++){
        for(j=i; j<qtdSaves; j++){
            if(saves[i].time>saves[j].time){
                auxTroca=saves[i];
                saves[i]=saves[j];
                saves[j]=auxTroca;
            }
        }
    }

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_O))
        {
            CloseWindow();
        }
        BeginDrawing();
        ClearBackground(WHITE);
        DrawTexture(textura, 0, 0, WHITE);
        
        //animacao do botao
        Vector2 pos = GetMousePosition();
        if (CheckCollisionPointRec(pos, voltar.frame))
        {
            DrawTexture(voltar_texture_in, voltar.frame.x, voltar.frame.y, WHITE);
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                CloseWindow();
                //Menu_Inicial();
            }
        } else {
            DrawTexture(voltar_texture_out, voltar.frame.x, voltar.frame.y, WHITE);
        }
        DrawText(TextFormat("RECORDS"), 310, 150, 20, BLACK);
        
        for(i=0; i<qtdSaves; i++){
            if(i<10){
                if(i==0){
                    DrawText(TextFormat("%d. %s", i+1, saves[i].name), 160, 170+20*i, 20, RED);
                    DrawText(TextFormat("%.3f", saves[i].time), 510, 170+20*i, 20, RED);
                }
                else{
                    DrawText(TextFormat("%d. %s", i+1, saves[i].name), 160, 170+20*i, 20, BLACK);
                    DrawText(TextFormat("%.3f", saves[i].time), 510, 170+20*i, 20, BLACK);
                }
            }
        }
        EndDrawing();
    }
    UnloadImage(voltar.ImagemOut);
    UnloadImage(voltar.ImagemIn);
    UnloadTexture(voltar_texture_in);
    UnloadTexture(voltar_texture_out);
    UnloadImage(imagem);
    UnloadTexture(textura);
    CloseWindow();
}

void putName(float time){
    Color fundo;
    fundo.r = 181;
    fundo.g = 190;
    fundo.b = 194;
    fundo.a = 232;
    botao hist, sair;
    hist.frame.height = 160/2;
    hist.frame.width = 250;
    hist.frame.x = 440;
    hist.frame.y = 440;
    hist.ImagemOut = LoadImage("assets/imgs/hist_out.png");
    hist.ImagemIn = LoadImage("assets/imgs/hist_in.png");
    ImageResize(&hist.ImagemIn, hist.frame.width, hist.frame.height);
    ImageResize(&hist.ImagemOut, hist.frame.width, hist.frame.height);
    Texture2D hist_texture_out = LoadTextureFromImage(hist.ImagemOut);
    Texture2D hist_texture_in = LoadTextureFromImage(hist.ImagemIn);

    sair.frame.height = 160/2;
    sair.frame.width = 250;
    sair.frame.x = 40;
    sair.frame.y = 440;
    sair.ImagemOut = LoadImage("assets/imgs/sair_out.png");
    sair.ImagemIn = LoadImage("assets/imgs/sair_in.png");
    ImageResize(&sair.ImagemIn, sair.frame.width, sair.frame.height);
    ImageResize(&sair.ImagemOut, sair.frame.width, sair.frame.height);
    Texture2D sair_texture_out = LoadTextureFromImage(sair.ImagemOut);
    Texture2D sair_texture_in = LoadTextureFromImage(sair.ImagemIn);

    Image imagem = LoadImage("assets/imgs/tv.png");
    ImageResizeNN(&imagem, lar, alt);
    Texture2D textura = LoadTextureFromImage(imagem);

    Rectangle textBox;
    //dimensoes do botao
    textBox.height = 70;
    textBox.width = 300;
    //coordenadas do botao
    textBox.x = 220;
    textBox.y = 280;
    
    char *name=NULL;
    char *aux=NULL;
    int tam=0;
    
    int flag_name=0;
    
    SetTargetFPS(10);
    int frameCounter=0;
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_O))
        {
            CloseWindow();
        }
        BeginDrawing();
        ClearBackground(WHITE);
        DrawTexture(textura, 0, 0, WHITE);
        DrawText(TextFormat("PARABENS!"), 265, 170, 35, BLACK);
        DrawText(TextFormat("INSIRA SEU NOME"), 210, 220, 35, BLACK);
        
        //animacoes dos "retangulos"
        Vector2 pos = GetMousePosition();
        if (CheckCollisionPointRec(pos, hist.frame))
        {
             DrawTexture(hist_texture_in, hist.frame.x, hist.frame.y, WHITE);
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                if(flag_name==1){
                     save(name, time);
                    viewSaves();
                }
                else{
                    DrawText(TextFormat("INSIRA SEU NOME"), 210, 220, 35, RED);
                }
            }
        } else {
            DrawTexture(hist_texture_out, hist.frame.x, hist.frame.y, WHITE);
        }
        
        if (CheckCollisionPointRec(pos, sair.frame))
        {
             DrawTexture(sair_texture_in, sair.frame.x, sair.frame.y, WHITE);
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                if(flag_name==1){
                    save(name, time);
                    CloseWindow();
                    Menu_Inicial();
                }
                else{
                   DrawText(TextFormat("INSIRA SEU NOME"), 210, 220, 35, RED);
                }
            }
        } else {
            DrawTexture(sair_texture_out, sair.frame.x, sair.frame.y, WHITE);
        }
        
        if (CheckCollisionPointRec(pos, textBox))
        {
            DrawRectangleRec(textBox, fundo);
            DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            frameCounter++;
            if((frameCounter/5)%2==0){
                DrawText("_", (int)textBox.x+10+MeasureText(name, 40), (int)textBox.y + 28, 40, MAROON);
            }
            int key = GetCharPressed();
            while(key > 0){
                if ((key >= 32) && (key <= 125) && (tam < MAX_LEN))
                {   
                    flag_name=1;
                    aux = name;
                    name = (char *) realloc(aux, (tam+1));
                    if(name == NULL){
                        printf("Problema de alocacao!\n");
                        free(aux);
                        exit(1);
                    }
                    name[tam] = (char)key;
                    name[tam+1] = '\0';
                    tam++;
                }
                key = GetCharPressed();
            }
            if (IsKeyPressed(KEY_BACKSPACE))
            {
                tam--;
                if (tam < 0) tam = 0;
                name[tam] = '\0';
            }
        } else {
            DrawRectangleRec(textBox, fundo);
            DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, BLACK);
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
            frameCounter=0;
        }
        DrawText(name, (int)textBox.x + 10, (int)textBox.y + 15, 40, MAROON);
        EndDrawing();
    }
    UnloadImage(hist.ImagemOut);
    UnloadImage(hist.ImagemIn);
    UnloadTexture(hist_texture_in);
    UnloadTexture(hist_texture_out);
    UnloadImage(sair.ImagemOut);
    UnloadImage(sair.ImagemIn);
    UnloadTexture(hist_texture_in);
    UnloadTexture(sair_texture_out);
    UnloadImage(imagem);
    UnloadTexture(textura);
}