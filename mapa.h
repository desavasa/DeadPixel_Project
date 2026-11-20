#ifndef MAPA_H
#define MAPA_H

#define FILAS 16
#define COLUMNAS 16
#define TAM_TILE 40
#define NUM_NIVELES 5

#define ANCHO_PANTALLA (COLUMNAS * TAM_TILE)
#define ALTO_PANTALLA  (FILAS * TAM_TILE)

#define T_CALLE 0
#define T_OBSTACULO 1
#define T_REFUGIO 2
#define T_FUEGO 3
#define T_ENTRADA 4

extern int mapas[NUM_NIVELES][FILAS][COLUMNAS];

int tipoCelda(int nivel, float x, float y);
int esCaminable(int nivel, float x, float y);
void dibujarDebugMapa(int nivel);

#endif