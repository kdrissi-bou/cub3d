#include "../include/cub3d.h"


// DRAW A CIRCLE FOR MY PLAYER
void	draw_player(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int xChange = 1 - (radius << 1);
    int yChange = 0;
    int radiusError = 0;

    while (x >= y)
    {
        for (int i = x0 - x; i <= x0 + x; i++)
        {
        //                 mlx_pixel_put(g_mlx.mlx, g_mlx.win, i, y0 + y, 0xFFFF00); 
        //     mlx_pixel_put(g_mlx.mlx, g_mlx.win, i, y0 - y, 0xFFFF00); 
            my_mlx_pixel_put(&g_img, i, y0 + y, 0xFFFF00);
            my_mlx_pixel_put(&g_img, i, y0 - y, 0xFFFF00); 
        }
        for (int i = x0 - y; i <= x0 + y; i++)
        {
            //            mlx_pixel_put(g_mlx.mlx, g_mlx.win, i, y0 + x, 0xFFFF00); 
            // mlx_pixel_put(g_mlx.mlx, g_mlx.win, i, y0 - x, 0xFFFF00); 
            my_mlx_pixel_put(&g_img, i, y0 + x, 0xFFFF00);
            my_mlx_pixel_put(&g_img, i, y0 - x, 0xFFFF00);
        }

        y++;
        radiusError += yChange;
        yChange += 2;
        if (((radiusError << 1) + xChange) > 0)
        {
            x--;
            radiusError += xChange;
            xChange += 2;
        }
    }
}


void            my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

// LINE
void	draw_line(int X0, int Y0, int X1, int Y1, int color) 
{ 
    // calculate dx & dy 
    int dx = X1 - X0; 
    int dy = Y1 - Y0; 
  
    // calculate steps required for generating pixels 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
    // calculate increment in x & y for each steps 
    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
  
    // Put pixel for each step 
    float X = X0; 
    float Y = Y0; 
    for (int i = 0; i <= steps; i++) 
    { 
        my_mlx_pixel_put(&g_img, X, Y, color);
       // mlx_pixel_put (g_mlx.mlx, g_mlx.win, X, Y, color);  // put pixel at (X,Y) 
        X += Xinc;           // increment in x at each step 
        Y += Yinc;           // increment in y at each step  
    } 
}


// DRAW SQ
void	draw_square(int width, int height, int x, int y)
{
    int i;
    int j;
    int k;
    i = 0;
    j = 0;
    k = x;
    while(i <= height)
    { 
        k  = x;
        j = 0;
      while(j <= width)
       {
           my_mlx_pixel_put(&g_img, k, y, 0xFFFFFF);
           k++;
           j++;
       }
    y++; 
    i++;
    }
}

void    draw_map(void)
{
    int i;
    int j;
    float Mx = 0;
    float My = 0;

    i = 0;
    while (i < MAP_ROWS )
    {
        j = 0;
        while (j < MAP_COLUMNS )
        {
            //printf("%d,%d\n",i,j);
            if (g_map[i][j] == '1')
                draw_square(TILE_SIZE, TILE_SIZE, Mx, My);
            Mx += TILE_SIZE;
            j++;
        }
    Mx = 0;
    My += TILE_SIZE;
    i++;   
    }
}














// void    drawRay (int rx, int ry)
// {
//     rx = player.px;
//     ry = player.py;
//     int i=0;
//     // printf("[%f]\n", player.pa);
//     mlx_pixel_put(g_mlx.mlx, g_mlx.win, player.px, player.py, 0xFFFFFF);
//     float newx = rx + 20;
//     float newy = ry+ (sin(player.pa) * 20);

//     DDA(rx, ry, newx, newy);
// //     while(i <= 40)
// //     {
// //     mlx_pixel_put(g_mlx.mlx, g_mlx.win, rx, ry, 0xFFFFFF);
// //     i++;
// //     rx += cos(player.pa)*3;
// //     ry += sin(player.pa)*3;
// //     }
// }
