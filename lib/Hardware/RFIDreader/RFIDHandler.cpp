#include "RFIDHandler.h"
#include <SPI.h>

RFIDHandler::RFIDHandler(byte sspin, byte rstpin){
    _mfrc522 = MFRC522(sspin, rstpin);
}

void RFIDHandler::init(){
    if(!(SPCR &_BV(SPE))){
        SPI.begin();
    }
    _mfrc522.PCD_Init();
}

void RFIDHandler::printCardInfo(){
        if ( ! _mfrc522.PICC_IsNewCardPresent() || ! _mfrc522.PICC_ReadCardSerial()) {
        return;
    }
    _mfrc522.PICC_DumpToSerial(&(_mfrc522.uid));
    _mfrc522.PICC_HaltA();
}