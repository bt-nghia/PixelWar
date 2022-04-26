#include "TileMap.h"
#include "Texture.h"

int PixelMap[20][25] = {
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
   {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
   {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
   {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
   {0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
   {0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
   {0,0,0,1,0,0,0,0,0,0,0,2,0,0,0,0,1,1,1,0,0,0,0,0,0},
   {0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0},
   {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
   {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
   {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

Map::Map() {
    // update texture de ko can truyen renderer vao ham load texture
    // load map theo tung o cua mang?
    floor_1 = Texture::LoadTexture("gameimg/tiles/floor/floor_1.png");//1
    floor_2 = Texture::LoadTexture("gameimg/tiles/floor/floor_2.png");//2
    floor_3 = Texture::LoadTexture("gameimg/tiles/floor/floor_3.png");//3
    floor_4 = Texture::LoadTexture("gameimg/tiles/floor/floor_4.png");//4
    floor_5 = Texture::LoadTexture("gameimg/tiles/floor/floor_5.png");//
    wall_1 = Texture::LoadTexture("gameimg/tiles/wall/wall_bottom.png");//5
    wall_2 = Texture::LoadTexture("gameimg/tiles/wall/wall_side_right.png");//6
    wall_3 = Texture::LoadTexture("gameimg/tiles/wall/wall_top_inner_right.png");//7
    wall_4 = Texture::LoadTexture("gameimg/tiles/wall/wall_top_inner_left.png");//8
    wall_5 = Texture::LoadTexture("gameimg/tiles/wall/wall_top_right.png");//9
    wall_6 = Texture::LoadTexture("gameimg/tiles/wall/wall_top_left.png");//10
    wall_7 = Texture::LoadTexture("gameimg/tiles/wall/wall_top_inner_left_2.png");//11
    wall_8 = Texture::LoadTexture("gameimg/tiles/wall/wall_top_inner_right_2.png");//12
    wall_9 = Texture::LoadTexture("gameimg/tiles/wall/wall_top_inner_right&2.png");//13
    wall_10 = Texture::LoadTexture("gameimg/tiles/wall/wall_top_inner_left&2.png");//14
    LoadMap(PixelMap);
    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;
    dest.x = dest.y = 0;
}

Map::~Map() {
    
}

void Map::LoadMap(int  PixelMap[20][25]) {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 25; j++) {
            map[i][j] = PixelMap[i][j];
        }
    }
}

void Map::DrawMap() {
    int type = 0;
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 25; j++) {
            type = map[i][j];
            // toa do render map cua tung o
            dest.x = j * 32;
            dest.y = i * 32;
            switch (type)
            {
            case 1:
                Texture::Draw(floor_1, src, dest);
                break;
            case 2:
                Texture::Draw(floor_2, src, dest);
                break;
            case 3:
                Texture::Draw(floor_3, src, dest);
                break;
            case 4:
                Texture::Draw(floor_4, src, dest);
                break;
            case 5:
                Texture::Draw(wall_1, src, dest);
                break;
            case 6:
                Texture::Draw(wall_2, src, dest);
                break;
            case 7:
                Texture::Draw(wall_3, src, dest);
                break;
            case 8:
                Texture::Draw(wall_4, src, dest);
                break;
            case 9:
                Texture::Draw(wall_5, src, dest);
                break;
            case 10:
                Texture::Draw(wall_6, src, dest);
                break;
            case 11:
                Texture::Draw(wall_7, src, dest);
                break;
            case 12:
                Texture::Draw(wall_8, src, dest);
                break;
            case 13:
                Texture::Draw(wall_9, src, dest);
                break;
            case 14:
                Texture::Draw(wall_10, src, dest);
                break;
            default:
                break;
            }
        }
    }
}