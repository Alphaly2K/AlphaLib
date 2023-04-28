#pragma once
namespace alp
{
        class BigNumber
        {
        private:
                char *number;
                int radi;
                static char *GetTotal(char *, char *, int);
                static int GetDec(char);
                BigNumber Add(char *, int);

        public:
                BigNumber();
                BigNumber(char *, int);
                BigNumber Add(BigNumber);
                BigNumber Add(int);
                BigNumber operator+(const BigNumber);
        };
        class BigDecimical : BigNumber
        {
        private:
                char *number;
                int radi = 10;

        public:
                BigDecimical();
                BigDecimical(char *);
        };
        class RadixNotEqualException
        {
        public:
                RadixNotEqualException(int adva, int advb) : m_adva(adva), m_advb(advb)
                {
                        if (m_adva == m_advb)
                                return;
                        if (m_adva > m_advb)
                                m_flag = 1;
                        else
                                m_flag = 2;
                };
                void Print() const;

        private:
                int m_flag;
                int m_adva;
                int m_advb;
        };
}
