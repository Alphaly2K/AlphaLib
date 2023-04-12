#pragma once
class BigNumber{
        private:
        char* number;
        int adv;
        public:
        BigNumber();
        ~BigNumber();
        int Alt(char);
        BigNumber(char*,int);
        char* Add(char*,char*,int);
}; 
