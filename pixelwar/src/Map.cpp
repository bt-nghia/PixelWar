#include "Map.h"
#include "Game.h"
#include <fstream>

int mp[6][6] = {
    {1,2,3,1,2,3},
    {1,2,1,2,1,1},
    {1,1,1,1,1,2},
    {2,2,2,3,3,1},
    {1,2,3,3,2,1},
    {1,1,1,1,3,1}
};

Map::Map() {

}

Map::~Map() {

}

void Map::LoadMap(/*std::string path,*/ int sizeX, int sizeY) {
    // char tile ;
    // std::fstream mapFile;
    // mapFile.open(path);
    for(int y = 0; y < sizeY; y++) {
        for(int x = 0; x < sizeX; x++) {
            // mapFile.get(tile);
            Game::AddTile(mp[x][y], x*32, y*32);
            // mapFile.ignore();
        }
    }
}