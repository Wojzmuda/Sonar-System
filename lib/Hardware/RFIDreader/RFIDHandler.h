#pragma once
#include <MFRC522.h>


class RFIDHandler{
    private:
        byte _SSPin;
        byte _RSTPin;
        MFRC522 _mfrc522;
    public:
        RFIDHandler(byte sspin, byte rstpin);
        void init();
        bool is_authorized();
        void printCardInfo();
};