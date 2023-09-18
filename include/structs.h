#ifndef STRUCTS_H
#define STRUCTS_H

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
    Texture2D textura;
    float velo;
    char morto;
    char chao;
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
    Image ImagemIn;
    Image ImagemOut;
} botao;

typedef struct{
    char name[50];
    double time;
} Record;

typedef struct{
    Rectangle frame;
    char string[100];
}caixa_texto;

#endif