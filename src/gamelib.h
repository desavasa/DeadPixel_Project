// Equipo desarrollador - fundador
// Juego
// Viernes 07 de noviembre de 2026
// VERSIÓN 1.0
// ACTUALIZACIONES:
// 07-11-2026 -> Se creó la librería y se probaron funciones útiles.
// 20-11-2026 -> Se borraron las funciones y se optó por agregar sólo reutilizables.
//
#include <raylib.h>

// Prototipos
void mov_player(float *pX, float *pY);

void batalla();


// No hay main.

// Desarrollo
void mov_player(float *pX, float *pY)
{
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
}
//*********************************************************
void batalla()
{

}
//*********************************************************

//*********************************************************
