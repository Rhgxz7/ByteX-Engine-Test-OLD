#include "byx_shader.hpp"

namespace byx {

    std::string file(const char* file) {
        std::ifstream in(file, std::ios::binary);

        if(in) {
            std::string read;
            in.seekg(0, std::ios::end);
            read.resize(in.tellg());
            in.seekg(0, std::ios::beg);
            in.read(&read[0], read.size());
            in.close();
            return(read);
        }
        throw(errno);
    }


}