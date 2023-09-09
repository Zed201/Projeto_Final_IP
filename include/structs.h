#ifndef STRUCTS_H
#define STRUCTS_H

#include "raylib.h"
// Posicao do botao do menu
#define posX_Ret 225
// Tamanho da janela
#define lar 720
#define alt 540

typedef struct{
    Rectangle target;
    Texture2D textura;
    float velo;
    float vida;
    bool dash;
    bool Jump;
} personagem;

typedef struct 
{
    Rectangle target;
    Color cor;
    Texture2D textura;
    float velo;
    char morto;
} inimigo;

typedef struct 
{
    Rectangle target;
    Texture2D textura;
    int posEspada;
} arma;

typedef struct 
{
    Rectangle frame;
    char string[100];
} botao;

typedef struct{
    char name[50];
    float time;
} Record;

#endif