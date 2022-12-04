#ifndef SAVE_FILE_LOADER_HPP 
#define SAVE_FILE_LOADER_HPP

#include <fstream>
#include "save_loader.hpp"
#include "../../exceptions/loading_map_exception.hpp"

namespace Map
{
    class SaveFileLoader : public SaveLoader {
    public:
        SaveFileLoader(const std::string &filename);
        ~SaveFileLoader();
        FieldMap loadMap();
    private:
        std::ifstream file; 
    };
} // namespace Map


#endif