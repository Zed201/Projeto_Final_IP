
void Manual(){
    botao comecar;
    comecar.frame.height = 90;
    comecar.frame.width = 280;
    comecar.frame.x = 225;
    comecar.frame.y = 400;
    strcpy(comecar.string, "Começar");
    while (!WindowShouldClose())
    {
        Vector2 pos = GetMousePosition();
        BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangle(80, 60, 570, 305, GRAY);
        DrawText(TextFormat("MANUAL:\n\nTestando"), 80, 60, 20, BLACK);
        
        if (CheckCollisionPointRec(pos, comecar.frame))
        {
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                jogo_fase1();
            }
            DrawRectangleRec(comecar.frame, RED);
            DrawText(comecar.string, posX_Ret + 80, 400 + 25, 35, WHITE);
        } else {
            DrawRectangleRec(comecar.frame, GRAY);
            DrawText(comecar.string, posX_Ret + 80, 400 + 25, 35, BLACK);
        }
        EndDrawing();
    }
    
}

void Menu_Inicial(){
    botao start, sair, comecar;
    start.frame.height = 90;
    start.frame.width = 280;
    sair.frame.height = 90;
    sair.frame.width = 280;
    start.frame.x = 225;
    start.frame.y = 170;
    sair.frame.x = 225;
    sair.frame.y = 350;
    strcpy(start.string, "Start");
    strcpy(sair.string, "Sair");
    InitWindow(lar, alt, "Testando Menu");
    Image imagem = LoadImage("assets/imgs/fundo.png");
    ImageResizeNN(&imagem, lar, alt);
    Texture2D textura = LoadTextureFromImage(imagem);
    while (!WindowShouldClose())
    {
        Vector2 pos = GetMousePosition();
        BeginDrawing();
        DrawTexture(textura, 0, 0, WHITE);
        if (CheckCollisionPointRec(pos, start.frame))
        {
            DrawRectangleRec(start.frame, RED);
            DrawText(start.string, posX_Ret + 80, 170 + 25, 35, WHITE);
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                Manual();
            }
        } else {
            DrawRectangleRec(start.frame, GRAY);
            DrawText(start.string, posX_Ret + 80, 170 + 25, 35, BLACK);
        }
        if (CheckCollisionPointRec(pos, sair.frame))
        {
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                CloseWindow();
            }
            DrawRectangleRec(sair.frame, RED);
            DrawText(sair.string, posX_Ret + 80, 350 + 25, 35, WHITE);
        } else {
            DrawRectangleRec(sair.frame, GRAY);
            DrawText(sair.string, posX_Ret + 80, 350 + 25, 35, BLACK);
        }
        EndDrawing();
    }
    CloseWindow();
}