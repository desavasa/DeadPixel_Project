// Equipo desarrollador
// Juego
// Fecha de inicio
// retos semanales - Semana 2
#include "gamelib.h"

// Prototipos
void menu_principal(float *pX, float *pY, int *band, int *opc_menu, Color green, Texture2D flecha, Texture2D background);
void menu_interno();
void nivel1(int *band, float *pX, float *pY, Color green, Texture2D player, Texture2D background, Texture2D zombie);
void nivel2();
void nivel3();
void nivel4();
void nivel5();

int main()
{
    // Pantalla completa
    SetConfigFlags(FLAG_FULLSCREEN_MODE);

    int band = 0, opc_menu = 1;

    // En el menu
    // -> iniciar con 1450x y 730y, -> salir 1600x y 845y, -> creditos 1520x y 948y
    float pX = 1450.0f;
    float pY = 730.0f;
    Color green = {20, 160, 133, 255};

    InitWindow(800, 800, "Dead Pixel");
    SetTargetFPS(60);

    // Imagenes cargadas como Texturas 2D
    Texture2D player = LoadTexture("sprites/Spritee.png");
    Texture2D background2 = LoadTexture("sprites/Fondou.png");
    Texture2D flecha = LoadTexture("sprites/flecha.png");
    Texture2D back_menu = LoadTexture("sprites/menu.png");
    Texture2D block = LoadTexture("sprites/Zom1cpy.png");

    // Loop principal
    while (WindowShouldClose() == false && band != 6)
    {
        if (band == 0)
        {
            menu_principal(&pX, &pY, &band, &opc_menu, green, flecha, back_menu);
        }
        else
        {
            if (band == 1)
            {
                nivel1(&band, &pX, &pY, green, player, background2, block);
            }
            else
            {
                if(band == 2)
                {
                    nivel2();
                }
                else
                {
                    if(band == 3)
                    {
                        nivel3();
                    }
                    else
                    {
                        if(band == 4)
                        {
                            nivel4();
                        }
                        else
                        {
                            if(band == 5)
                            {
                                nivel5();
                            }
                        }
                    }
                }
            }
        }

        EndDrawing();
    }

    // Descarga de texturas
    UnloadTexture(player);
    UnloadTexture(flecha);
    UnloadTexture(back_menu);
    UnloadTexture(background2);
    UnloadTexture(block);

    CloseWindow();
    return 0;
}
//*********************************************************************
void menu_principal(float *pX, float *pY, int *band, int *opc_menu, Color green, Texture2D flecha, Texture2D background)
{

    // Movimiento de seleccionador
    if (IsKeyPressed(KEY_UP))
    {
        (*opc_menu)--;
        if (*opc_menu < 1)
        {
            (*opc_menu) = 3;
        }
        else
        {
            if (*opc_menu > 3)
            {
                (*opc_menu) = 1;
            }
        }
    }
    else
    {
        if (IsKeyPressed(KEY_DOWN))
        {
            (*opc_menu)++;
            if (*opc_menu > 3)
            {
                (*opc_menu) = 1;
            }
            else
            {
                if (*opc_menu < 1)
                {
                    (*opc_menu) = 3;
                }
            }
        }
    }

    if (*opc_menu == 1)
    {
        *pY = 730.0f;
        *pX = 1450.0f;
    }
    else
    {
        if (*opc_menu == 2)
        {
            *pY = 845.0f;
            *pX = 1600.0f;
        }
        else
        {
            *pY = 948.0f;
            *pX = 1520.0f;
        }
    }

    if (IsKeyPressed(KEY_ENTER))
    {
        if (*opc_menu == 1)
        {
            *band = 1;
            *pX = 975.0f;
            *pY = 550.0f;
        }
        else
        {
            if (*opc_menu == 2)
            {
                *band = 2;
            }
            else
            {
                *band = 3;
            }
        }
    }

    // Inicia el dibujado
    BeginDrawing();
    ClearBackground(green);

    Rectangle sourceRec = {0.0f, 0.0f, (float)flecha.width, (float)flecha.height};

    float nuevoAncho = 50.0f;
    float nuevoAlto = 80.0f;
    Rectangle destRec = {*pX, *pY, nuevoAncho, nuevoAlto};

    // 1. Origen: Tomamos la imagen de fondo completa
    Rectangle sourceBackground = {0.0f, 0.0f, (float)background.width, (float)background.height};

    // 2. Destino: Forzamos que se dibuje desde la esquina (0,0) con un tamaño de 800x800
    Rectangle destBackground = {0.0f, 0.0f, 1950.0f, 1100.0f};

    // 3. Origen de rotación (esquina superior izquierda)
    Vector2 bgOrigin = {0.0f, 0.0f};

    // 4. Dibujar el fondo estirado/ajustado a 800x800
    DrawTexturePro(background, sourceBackground, destBackground, bgOrigin, 0.0f, WHITE);

    // Dibujar el sprite usando DrawTextureRec en lugar de DrawCircle
    Vector2 origin = {0.0f, 0.0f};
    DrawTexturePro(flecha, sourceRec, destRec, origin, 0.0f, WHITE);
}
//*********************************************************************
void menu_interno()
{
}
//*********************************************************************
void nivel1(int *band, float *pX, float *pY, Color green, Texture2D player, Texture2D background, Texture2D zombie)
{
    // Movimientos de jugador
    if (IsKeyDown(KEY_RIGHT))
    {
        *pX += 3.0f;
    }
    else
    {
        if (IsKeyDown(KEY_LEFT))
        {
            *pX -= 3.0f;
        }
        else
        {
            if (IsKeyDown(KEY_UP))
            {
                *pY -= 3.0f;
            }
            else
            {
                if (IsKeyDown(KEY_DOWN))
                {
                    *pY += 3.0f;
                }
            }
        }
    }

    // Dibujado
    BeginDrawing();
    ClearBackground(green);

    // Interacción
    Rectangle sourceRec = {0.0f, 0.0f, (float)player.width, (float)player.height};
    Rectangle bloque = {0.0f, 0.0f, (float)zombie.width, (float)zombie.height};

    float nuevoAncho = 50.0f;
    float nuevoAlto = 80.0f;
    Rectangle destRec = {*pX, *pY, nuevoAncho, nuevoAlto};
    Rectangle destinoRec = {1000.0f, 950.0f, 50.0f, 80.0f};

    // 1. Origen: Tomamos la imagen de fondo completa
    Rectangle sourceBackground = {0.0f, 0.0f, (float)background.width, (float)background.height};

    // 2. Destino: Forzamos que se dibuje desde la esquina (0,0) con un tamaño de 800x800
    Rectangle destBackground = {0.0f, 0.0f, 1950.0f, 1100.0f};

    // 3. Origen de rotación (esquina superior izquierda)
    Vector2 bgOrigin = {0.0f, 0.0f};

    // 4. Dibujar el fondo estirado/ajustado a 800x800
    DrawTexturePro(background, sourceBackground, destBackground, bgOrigin, 0.0f, WHITE);

    // Dibujar el sprite usando DrawTextureRec en lugar de DrawCircle
    Vector2 origin = {0.0f, 0.0f};
    Vector2 place = {0.0f, 0.0f};

    if (CheckCollisionRecs(destRec, destinoRec))
    {
        *band = 0;
    }

    DrawTexturePro(player, sourceRec, destRec, origin, 0.0f, WHITE);
    DrawTexturePro(zombie, bloque, destinoRec, place, 0.0f, WHITE);
}
//*********************************************************************
void nivel2()
{
}
//*********************************************************************
void nivel3()
{
}
//*********************************************************************
void nivel4()
{
}
//*********************************************************************
void nivel5()
{
}
//*********************************************************************