#pragma once
namespace alp{
        class BigNumber{
        public:
        char* number;
        int adv;
        BigNumber();
        ~BigNumber();
        BigNumber(char*,int);
        BigNumber* Add(BigNumber);
        BigNumber* Add(char*,int);
        BigNumber* Add(int);
        BigNumber operator+(const BigNumber);
        public:
        static char* GetTotal(char*,char*,int);
        static int GetDec(char);
}; 
}
