#ifndef MAC_GRID_H
#define MAC_GRID_H

#include <stddef.h>

typedef struct
{
    size_t nx;
    size_t ny;
    double dx;
    double dy;

    /* Field buffers aligned to 64-byte cached lines*/
    double *p; /* Pressure at cell centers : (nx + 2) * (ny + 2)*/
    double *div; /* Intermediate velocity divergence*/
    double *u; /* Horizontal velocity: (nx + 1) * (ny +2)*/
    double *v; /* Vertical Velocity: (nx + 2) * (ny + 1)*/
    double *u_star; /* Predictor buffer */
    double *v_star; /* Predictor buffer */
} MacGrid;

int mac_grid_allocate(MacGrid *grid, size_t nx, size_t ny, double lx, double ly);
void mac_grid_free(MacGrid *grid);

#endif