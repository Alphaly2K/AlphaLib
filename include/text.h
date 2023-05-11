#pragma once
#include <string>
namespace alp{
    class Text{
        public:
        static int* GetNextArray(std::string);
        static int GetPatternPosition(std::string,std::string);
    };
}