#include "raylib.h"
#include "mapa.h"

int mapas[NUM_NIVELES][FILAS][COLUMNAS] = {
    // ---- Nivel 1: cruce de calles (medido sobre Fondou.PNG) ----
    {
        {1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1},
        {1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,3,3,3,3,1,1,1,1,1,1},
        {1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,4,4,4,4,1,1,1,1,1,1}
    },
    // ---- Niveles 2 a 5: pendientes (por ahora todo en 0) ----
    {{0}}, {{0}}, {{0}}, {{0}}
};

int tipoCelda(int nivel, float x, float y) {
    // Primero revisamos negativos (antes de convertir a int)
    if (x < 0) return T_OBSTACULO;
    if (y < 0) return T_OBSTACULO;

    int col = (int)(x / TAM_TILE);
    int fila = (int)(y / TAM_TILE);

    if (col >= COLUMNAS) return T_OBSTACULO;
    if (fila >= FILAS) return T_OBSTACULO;

    return mapas[nivel][fila][col];
}

int esCaminable(int nivel, float x, float y) {
    return tipoCelda(nivel, x, y) != T_OBSTACULO;
}

// Pinta la matriz encima del fondo para comprobar que coincide
void dibujarDebugMapa(int nivel) {
    for (int f = 0; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS; c++) {
            Color col = BLANK;
            switch (mapas[nivel][f][c]) {
                case T_OBSTACULO: col = RED;    break;
                case T_REFUGIO:   col = GREEN;  break;
                case T_FUEGO:     col = ORANGE; break;
                case T_ENTRADA:   col = BLUE;   break;
            }
            DrawRectangle(c * TAM_TILE, f * TAM_TILE, TAM_TILE, TAM_TILE, Fade(col, 0.4f));
        }
    }
}