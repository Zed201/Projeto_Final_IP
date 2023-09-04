typedef struct{
    Rectangle target;
    Texture2D textura;
    float velo;
} personagem;
typedef struct 
{
    Rectangle target;
    Texture2D textura;
} arma;
typedef struct 
{
    Rectangle frame;
    char string[100];
} botao;
// Posicao do botao do menu
#define posX_Ret 225
// Tamanho da janela
#define lar 720
#define alt 540
// Relacionados a mecanica de pulo
#define G 350
#define PJS 250.0f
#define PHS 110.0f