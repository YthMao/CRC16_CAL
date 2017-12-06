/*************************************************************************
	> File Name: crc16.c
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Dec 2017 04:42:02 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdint.h>

void InvertUint16(unsigned short *dBuf,unsigned short *srcBuf)  
{  
    int i;  
    unsigned short tmp[4];  
    tmp[0] = 0;  
    for(i=0;i< 16;i++)  
    {  
          if(srcBuf[0]& (1 << i))  
            tmp[0]|=1<<(15 - i);  
        }  
    dBuf[0] = tmp[0];  
}  

void InvertUint8(unsigned char *dBuf,unsigned char *srcBuf)
{
    int i;
    unsigned char tmp[4];
    tmp[0] = 0;
    for(i=0;i< 8;i++)
    {
        if(srcBuf[0]& (1 << i))
        tmp[0]|=1<<(7-i);

    }
    dBuf[0] = tmp[0];
}
unsigned short CRC16_CCITT(unsigned char *puchMsg, unsigned int usDataLen)  
{  
    unsigned short wCRCin = 0x0000;  
    unsigned short wCPoly = 0x1021;  
    unsigned char wChar = 0;  
    
    int i;
    while (usDataLen--)     
    {  
        wChar = *(puchMsg++);  
        InvertUint8(&wChar,&wChar);  
        wCRCin ^= (wChar << 8);  
        for(i = 0;i < 8;i++)  
        {  
            if(wCRCin & 0x8000)  
                wCRCin = (wCRCin << 1) ^ wCPoly;  
            else  
                wCRCin = wCRCin << 1;  
        }  
    }  
    InvertUint16(&wCRCin,&wCRCin);  
    return (wCRCin) ;  
}  
unsigned short CRC16_CCITT_FALSE(unsigned char *puchMsg, unsigned int usDataLen)  
{  
    unsigned short wCRCin = 0xFFFF;  
    unsigned short wCPoly = 0x1021;  
    unsigned char wChar = 0;  
    
    int i;
    while (usDataLen--)     
    {  
        wChar = *(puchMsg++);  
        wCRCin ^= (wChar << 8);  
        for(i = 0;i < 8;i++)  
        {  
            if(wCRCin & 0x8000)  
                wCRCin = (wCRCin << 1) ^ wCPoly;  
            else  
                wCRCin = wCRCin << 1;  
        }  
    }  
    return (wCRCin) ;  
}  
unsigned short CRC16_XMODEM(unsigned char *puchMsg, unsigned int usDataLen)  
{  
    unsigned short wCRCin = 0x0000;  
    unsigned short wCPoly = 0x1021;  
    unsigned char wChar = 0;  
    
    int i;
    while (usDataLen--)     
    {  
        wChar = *(puchMsg++);  
        wCRCin ^= (wChar << 8);  
        for(i = 0;i < 8;i++)  
        {  
            if(wCRCin & 0x8000)  
                wCRCin = (wCRCin << 1) ^ wCPoly;  
            else  
                wCRCin = wCRCin << 1;  
        }  
    }  
    return (wCRCin) ;  
}  
  
unsigned short CRC16_X25(unsigned char *puchMsg, unsigned int usDataLen)  
{  
    unsigned short wCRCin = 0xFFFF;  
    unsigned short wCPoly = 0x1021;  
    unsigned char wChar = 0;  
 
    int i;
    while (usDataLen--)     
    {  
        wChar = *(puchMsg++);  
        InvertUint8(&wChar,&wChar);  
        wCRCin ^= (wChar << 8);  
        for(i = 0;i < 8;i++)  
        {  
            if(wCRCin & 0x8000)  
                wCRCin = (wCRCin << 1) ^ wCPoly;  
            else  
                wCRCin = wCRCin << 1;  
        }  
    }  
    InvertUint16(&wCRCin,&wCRCin);  
    return (wCRCin^0xFFFF) ;  
}  
    
unsigned short CRC16_MODBUS(unsigned char *puchMsg, unsigned int usDataLen)  
{  
    unsigned short wCRCin = 0xFFFF;  
    unsigned short wCPoly = 0x8005;  
    unsigned char wChar = 0;  
   
    int i;
    while (usDataLen--)     
    {  
        wChar = *(puchMsg++);  
        InvertUint8(&wChar,&wChar);  
        wCRCin ^= (wChar << 8);  
        for(i = 0;i < 8;i++)  
        {  
           if(wCRCin & 0x8000)  
               wCRCin = (wCRCin << 1) ^ wCPoly;  
           else  
               wCRCin = wCRCin << 1;  
        }  
    }  
    InvertUint16(&wCRCin,&wCRCin);  
    return (wCRCin) ;  
}  
unsigned short CRC16_IBM(unsigned char *puchMsg, unsigned int usDataLen)  
{  
   unsigned short wCRCin = 0x0000;  
   unsigned short wCPoly = 0x8005;  
   unsigned char wChar = 0;  
   
    int i;
   while (usDataLen--)     
   {  
       wChar = *(puchMsg++);  
       InvertUint8(&wChar,&wChar);  
       wCRCin ^= (wChar << 8);  
       for(i = 0;i < 8;i++)  
       {  
           if(wCRCin & 0x8000)  
               wCRCin = (wCRCin << 1) ^ wCPoly;  
           else  
               wCRCin = wCRCin << 1;  
       }  
   }  
   InvertUint16(&wCRCin,&wCRCin);  
   return (wCRCin) ;  
}  
unsigned short CRC16_MAXIM(unsigned char *puchMsg, unsigned int usDataLen)  
{  
   unsigned short wCRCin = 0x0000;  
   unsigned short wCPoly = 0x8005;  
   unsigned char wChar = 0;  
   
    int i;
   while (usDataLen--)     
   {  
       wChar = *(puchMsg++);  
       InvertUint8(&wChar,&wChar);  
       wCRCin ^= (wChar << 8);  
       for(i = 0;i < 8;i++)  
       {  
           if(wCRCin & 0x8000)  
               wCRCin = (wCRCin << 1) ^ wCPoly;  
           else  
               wCRCin = wCRCin << 1;  
       }  
   }  
   InvertUint16(&wCRCin,&wCRCin);  
   return (wCRCin^0xFFFF) ;  
}  

int main(int argc, char *argv[])
{
    unsigned short crc16_result = 0;  
    unsigned char buff[] = {0x61, 0x62 , 0x63 , 0x64 , 0x65 , 0x66};

    printf("Source buf: %s\r\n",buff);

    crc16_result = CRC16_CCITT(buff,6);  
    printf("CRC16_CCITT result = %04X\r\n",crc16_result); 

    crc16_result = CRC16_CCITT_FALSE(buff,6);  
    printf("CRC16_CCITT_FALSE result = %04X\r\n",crc16_result); 

    crc16_result = CRC16_XMODEM(buff,6);  
    printf("CRC16_XMODEM result = %04X\r\n",crc16_result); 
    
    crc16_result = CRC16_MODBUS(buff,6);  
    printf("CRC16_MODBUS result = %04X\r\n",crc16_result); 

    crc16_result = CRC16_IBM(buff,6);  
    printf("CRC16_IBM result = %04X\r\n",crc16_result); 

    crc16_result = CRC16_X25(buff,6);  
    printf("CRC16_X25 result = %04X\r\n",crc16_result); 

    crc16_result = CRC16_MAXIM(buff,6);  
    printf("CRC16_MAXIM result = %04X\r\n",crc16_result); 
}

