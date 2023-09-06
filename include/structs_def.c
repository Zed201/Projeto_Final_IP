// Posicao do botao do menu
#define posX_Ret 225
// Tamanho da janela
#define lar 720
#define alt 540
// Relacionados a mecanica de pulo
#define G 350
#define PJS 250.0f
#define PHS 110.0f
#define MAX_LEN 11
#define enemy_qtd 30
#define enemy_heigth 30
#define enemy_width 30
#define floor_y 484
#define espe_tam 60
#define dash_tam 25
#define dash_multiper 4
#define perso_lifes 1000

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
