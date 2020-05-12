/*
 * File:   USART_libreria.c
 * Author: GUSTAVO
 *
 * Created on 17 de marzo de 2020, 06:00 PM
 */


#include <xc.h>
#include "Configuracion.h"
#include "USART_libreria.h"

void USART_Init(long BAUD){
            
    //Baudios
    SPBRG = 103;
    
    //Configuración 
    TXSTAbits.BRGH = 1;     //high Speed
    TXSTAbits.SYNC = 0;     //Asincrono
    RCSTAbits.SPEN = 1;     //Habilitar Tx y Rx
    
    //Transmisión
    TXSTAbits.TX9 = 0;      //8 bits
    TXSTAbits.TXEN = 1;     //Activamos transmisión
    
    //Recepción
    RCSTAbits.RX9 = 0;      //8 bits
    RCSTAbits.CREN = 1;     //Activamos recepción
    BAUDCONbits.BRG16=1;
    
}

void USART_Tx(char data){
    TXREG = data;
}

char USART_Rx(){
    return RCREG; 
}

void INTE_CONFIG(){
INTCONbits.GIE=1;
INTCONbits.INTE=1;
INTCONbits.INTF=0;
INTCONbits.IOCIF=0;
IOCBPbits.IOCBP7=1;//interupcion por flanco positivo en rb7    
}
