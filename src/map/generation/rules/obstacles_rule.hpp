#ifndef OBSTACLES_RULE
#define OBSTACLES_RULE

#include "../../map.hpp"
#include "../../../common/vector2d.hpp"

namespace Map
{
    enum class ObstaclesVariant {
        SPIRAL, ROOMS
    };

    template <ObstaclesVariant variant>
    class ObstaclesRule {
    public:
        static void changeMap(FieldMap &field) {
            const auto &size = field.getSize();
            if (variant == ObstaclesVariant::ROOMS) {
                // BORDERS
                for (int i = 0; i < size.y; i ++) {
                    field.setCell({0,i}, Cell(TileType::STONE, true));
                    field.setCell({(int)size.x-1,i}, Cell(TileType::STONE, true));
                }
                for (int i = 0; i < size.x; i ++) {
                    field.setCell({i,0}, Cell(TileType::STONE, true));
                    field.setCell({i,(int)size.y-1}, Cell(TileType::STONE, true));
                }

            } 
            else if (variant == ObstaclesVariant::SPIRAL) {
                
                int dirInd = 0;
                std::vector<Common::Vector2D<int>> dirs = { {1,0}, {0,1}, {-1,0}, {0,-1} };
                int stepsX = size.x, stepsY = size.y;
                Common::Vector2D<int> pos = {0,0};

                while(stepsX > 0 || stepsY > 0) {
                    for (int i = 0; i < (dirInd % 2 == 0 ? stepsX : stepsY); i ++) {
                        field.setCell(pos, Cell(TileType::STONE, true));
                        pos += dirs[dirInd];
                    }
                    stepsX --;
                    stepsY --;
                    dirInd ++;
                    dirInd %= 4;
                }
                
            }
        }
    };
} // namespace Map


#endif