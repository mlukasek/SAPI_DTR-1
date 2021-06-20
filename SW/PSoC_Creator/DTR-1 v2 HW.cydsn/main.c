/* ========================================
 *
 * Copyright Martin Lukasek (c) 2021
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Martin Lukasek.
 *
 * ========================================
*/
#include <stdio.h>
#include <stdarg.h>
#include "project.h"
#include "ssd1306.h"

#define DISPLAY_ADDRESS 0x3C // 011110+SA0+RW - 0x3C or 0x3D

int noUART = 1;
uint16 extaddr = 0;
uint32 cntTime = 0;
uint32 cntLines = 0;
uint32 cntErrs = 0;
uint8 waitForBus = 1;

int noOLED = 1;

struct PortData
{
    uint8 port;
    uint8 data;
};

struct PortData intQueue[256];
volatile uint8 intCnt = 0;
volatile uint8 rdCnt = 0;

struct InstData
{
    uint16 addr;
    uint8 data;
};

struct InstData instQueue[256];
volatile uint8 instCnt = 0;
volatile uint8 instRdCnt = 0;

CY_ISR( UART_OUT_RCM_Handler )
{
    intQueue[intCnt].port = 0x10;
    intQueue[intCnt].data = RCM_Read();
    intCnt++;
}

CY_ISR( UART_OUT_RCU_Handler )
{
    intQueue[intCnt].port = 0x11;
    intQueue[intCnt].data = RCU_Read();
    intCnt++;
}

CY_ISR( UART_OUT_ROD_Handler )
{
    intQueue[intCnt].port = 0x12;
    intQueue[intCnt].data = ROD_Read();
    intCnt++;
}

CY_ISR( UART_OUT_RST_Handler )
{
    intQueue[intCnt].port = 0x13;
    intQueue[intCnt].data = RST_Read();
    intCnt++;
}

CY_ISR( UART_IN_RRD_Handler )
{
    RSU_Write( RSU_Read() & 0x7F );
}

CY_ISR( M1_Int_Handler )
{
    nWAIT_Write(0);
    //instQueue[instCnt].addr = (AddrH_Read()<<8) + AddrL_Read();
    //instQueue[instCnt].data = Dta_Read();
    //CyDelay(2);
    instQueue[instCnt].addr = (ADH_Reg_Read()<<8) + ADL_Reg_Read();
    instQueue[instCnt].data = DT_Reg_Read();
    instCnt++;
}

void SAPI_Reset() {
    RTL_Write(0);
    CyDelay(6);
    RTL_Write(1);
    //CyDelay(1);
}

int USBUART_printf(const char *format, ...)
{
    if(noUART)
        return -1;

    char tmpstr[128];
    int ret;
    
    va_list args;
    va_start(args, format);

    ret=vsprintf(tmpstr, format, args);
    while(!USBUART_CDCIsReady());
    USBUART_PutString(tmpstr);
    
    va_end(args);
    
    return ret;
}    

int UART_printf(const char *format, ...)
{
    char tmpstr[128];
    int ret;
    
    va_list args;
    va_start(args, format);

    ret=vsprintf(tmpstr, format, args);
    // while(!UART_CDCIsReady());
    UART_PutString(tmpstr);
    
    va_end(args);
    
    return ret;
}    

/*
void TermPutString(char * str) {
    if(noUART)
        return;
    if(strlen(str)>50) // aaa - correct later, but large string would block
        return;
    uint32 timeout = Millis_ReadCounter();
    if (0u != USBUART_GetConfiguration()) {    
        while (0u == USBUART_CDCIsReady())
        {
            if (Millis_ReadCounter()-timeout > 100) {
                return; // prevent getting stuck
            }
        }    
        USBUART_PutString(str);
    }
    timeout = Millis_ReadCounter();
    while((!USBUART_CDCIsReady()) && (Millis_ReadCounter()-timeout<100)){     // Wait for Tx to finish, timeout after 100 ms
        CyDelay(1);
    }
}    

void TermPutChar(char ch) {
    if(noUART)
        return;
    // USBUART_PutChar(ch);
    uint32 timeout = Millis_ReadCounter();
    if (0u != USBUART_GetConfiguration()) {    
        while (0u == USBUART_CDCIsReady())
        {
            if (Millis_ReadCounter()-timeout > 100) {
                return; // prevent getting stuck
            }
        }    
        USBUART_PutChar(ch);
    }
    timeout = Millis_ReadCounter();
    while((!USBUART_CDCIsReady()) && (Millis_ReadCounter()-timeout<100)){     // Wait for Tx to finish, timeout after 100 ms
        CyDelay(1);
    }
}    
*/

uint8 Get_SAPI_Bus() {
    // USBUART_printf("BUSAK = %d\r\n", BUSAK_Read());
    if(waitForBus==0)
        return 1;
    BUSRQ_Write(0);
    USBUART_printf("Waiting BUSAK ... ");
    while(BUSAK_Read()!=0) {
        USBUART_printf(".");
        CyDelay(10);
    }
    if(BUSAK_Read()==0) {
        USBUART_printf("OK\r\n");
        return 1;
    } else {
        USBUART_printf("FAILED\r\n");
        return 0;
    }
}

uint8 Get_SAPI_Bus_Silent() {
    // USBUART_printf("BUSAK = %d\r\n", BUSAK_Read());
    if(waitForBus==0)
        return 1;
    BUSRQ_Write(0);
    //USBUART_printf("Waiting BUSAK ... ");
    while(BUSAK_Read()!=0) {
        //USBUART_printf(".");
        CyDelay(1);
    }
    if(BUSAK_Read()==0) {
        //USBUART_printf("OK\r\n");
        return 1;
    } else {
        //USBUART_printf("FAILED\r\n");
        return 0;
    }
}

uint8 Release_SAPI_Bus() {
    if(waitForBus==0)
        return 1;
    BUSRQ_Write(1);
    USBUART_printf("Waiting BUS release ... ");
    while(BUSAK_Read()!=1) {
        USBUART_printf(".");
        CyDelay(10);
    }
    if(BUSAK_Read()==1) {
        USBUART_printf("OK\r\n");
        return 1;
    } else {
        USBUART_printf("FAILED\r\n");
        return 0;
    }
}

uint8 Release_SAPI_Bus_Silent() {
    if(waitForBus==0)
        return 1;
    BUSRQ_Write(1);
    //USBUART_printf("Waiting BUS release ... ");
    while(BUSAK_Read()!=1) {
        //USBUART_printf(".");
        CyDelay(1);
    }
    if(BUSAK_Read()==1) {
        //USBUART_printf("OK\r\n");
        return 1;
    } else {
        //USBUART_printf("FAILED\r\n");
        return 0;
    }
}

void DumpMem(uint16 addr);

void RAM_check() {
    uint32 testfrom = 0x0000;
    uint32 testlen = 0x10000;
    uint8 r;
    uint8 s;
    int err=0;
    
    if(!Get_SAPI_Bus()) {
        return;
    }

    AddrL_Write(0);
    AddrL_SetDriveMode(PIN_DM_STRONG);
    AddrH_Write(0);
    AddrH_SetDriveMode(PIN_DM_STRONG);
    
    // SRAM under my control DATAOUT CTL OER WE MSEL
    SRAM_Ctl_Write(0b01111);
    
    USBUART_printf("filling RAM with patttern\r\n");
    for(uint32 a=testfrom; a<testfrom+testlen; a=a+2) {
        AddrH_Write((a>>8)&0xFF);
        AddrL_Write(a&0xFF);
        BusDta_Write((a>>8)&0xFF);
        // DATAOUT + WE + MSEL
        SRAM_Ctl_Write(0b11100);
        CyDelayUs(1);
        SRAM_Ctl_Write(0b01111);
        CyDelayUs(1);
        AddrL_Write((a&0xFF)+1);
        BusDta_Write(a);
        SRAM_Ctl_Write(0b11100);
        CyDelayUs(1);
        SRAM_Ctl_Write(0b01111);
        CyDelayUs(1);
    }
    USBUART_printf("verifying RAM\r\n");

    // OER + MSEL = furt data ze SRAM na sbernici
    SRAM_Ctl_Write(0b01010);

    for(uint32 a=testfrom; a<testlen; a++) {
        AddrH_Write((a>>8)&0xFF);
        AddrL_Write(a&0xFF);
        CyDelayUs(2);
        r=Dta_Read();
        CyDelayUs(1);
        //USBUART_printf("%02X", r);
        //if((a&0x1F)==0x1F)
        //    USBUART_printf("\r\n");
        if(a&1) {
            s=(a&0xFF)-1;
        } else {
            s=(a>>8)&0xFF;
        }
        if(r!=s) {
            USBUART_printf("Error at %04X, expected %02X, but found %02X\r\n", a, s, r);
            err++;
            DumpMem(a & 0xFF00);
            if(!Get_SAPI_Bus()) {
                return;
            }
            AddrL_SetDriveMode(PIN_DM_STRONG);
            AddrH_SetDriveMode(PIN_DM_STRONG);
            SRAM_Ctl_Write(0b01010);
        }
    }

    // SRAM under my control DATAOUT CTL OER WE MSEL
    SRAM_Ctl_Write(0b01111);
    
    USBUART_printf("filling RAM with inverted patttern\r\n");
    for(uint32 a=testfrom; a<testfrom+testlen; a=a+2) {
        AddrH_Write((a>>8)&0xFF);
        AddrL_Write(a&0xFF);
        BusDta_Write(~((a>>8)&0xFF));
        // DATAOUT + WE + MSEL
        SRAM_Ctl_Write(0b11100);
        CyDelayUs(1);
        SRAM_Ctl_Write(0b01111);
        CyDelayUs(1);
        AddrL_Write((a&0xFF)+1);
        BusDta_Write(~a);
        SRAM_Ctl_Write(0b11100);
        CyDelayUs(1);
        SRAM_Ctl_Write(0b01111);
        CyDelayUs(1);
    }
    USBUART_printf("verifying RAM\r\n");

    // OER + MSEL = furt data ze SRAM na sbernici
    SRAM_Ctl_Write(0b01010);

    for(uint32 a=testfrom; a<testlen; a++) {
        AddrH_Write((a>>8)&0xFF);
        AddrL_Write(a&0xFF);
        CyDelayUs(1);
        r=Dta_Read();
        CyDelayUs(1);
        //USBUART_printf("%02X", r);
        //if((a&0x1F)==0x1F)
        //    USBUART_printf("\r\n");
        if(a&1) {
            s=~((a&0xFF)-1);
        } else {
            s=~((a>>8)&0xFF);
        }
        if(r!=s) {
            USBUART_printf("Error at %04X, expected %02X, but found %02X\r\n", a, s, r);
            err++;
        }
    }

    // relase SRAM to SAPI - CTL OER WE MSEL
    SRAM_Ctl_Write(0b00111);
    
    AddrL_Write(0);
    AddrL_SetDriveMode(PIN_DM_DIG_HIZ);
    AddrH_Write(0);
    AddrH_SetDriveMode(PIN_DM_DIG_HIZ);
    //Dta_Write(0xFF);
    //Dta_SetDriveMode(PIN_DM_RES_UP);
    
    if(err) {
        USBUART_printf("%d errors found :-(\r\n", err);
    } else {
        USBUART_printf("No errors found :-)\r\n");
    }
    Release_SAPI_Bus();

    USBUART_printf("Data has been corrupted by memory test, performing SAPI reset.\r\n");
    SAPI_Reset();
}

void DumpMem(uint16 addr) {
    uint8 r;

    if(!Get_SAPI_Bus()) {
        return;
    }

    // SRAM under my control DATAOUT CTL OER WE MSEL
    SRAM_Ctl_Write(0b01111);
    
    AddrL_Write(0);
    AddrL_SetDriveMode(PIN_DM_STRONG);
    AddrH_Write(0);
    AddrH_SetDriveMode(PIN_DM_STRONG);
    
    // USBUART_printf("reading RAM\r\n");

    // OER + MSEL = furt SRAM data na sbernici
    SRAM_Ctl_Write(0b01010);

    for(uint32 a=addr; a<addr+256; a++) {
        AddrH_Write((a>>8)&0xFF);
        AddrL_Write(a&0xFF);
        CyDelayUs(5);
        r=Dta_Read();
        CyDelayUs(5);
        if((a&0x1F)==0x00)
            USBUART_printf("%04X: ", a);
        USBUART_printf("%02X", r);
        if((a&0x1F)==0x1F)
            USBUART_printf("\r\n");
    }

    // relase SRAM to SAPI - DATAOUT CTL OER WE MSEL
    SRAM_Ctl_Write(0b00111);
    
    AddrL_Write(0);
    AddrL_SetDriveMode(PIN_DM_DIG_HIZ);
    AddrH_Write(0);
    AddrH_SetDriveMode(PIN_DM_DIG_HIZ);
    
    Release_SAPI_Bus();
}

void TestVideo() {
    uint8 r;
    uint16 err=0;

    if(!Get_SAPI_Bus()) {
        return;
    }

    AddrL_Write(0);
    AddrL_SetDriveMode(PIN_DM_STRONG);
    AddrH_Write(0);
    AddrH_SetDriveMode(PIN_DM_STRONG);
    MW_Write(1);
    MW_SetDriveMode(PIN_DM_STRONG);
    MR_Write(1);
    MR_SetDriveMode(PIN_DM_STRONG);
    
    USBUART_printf("Checking AND-1Z video RAM 0xF800-0xFCFF\r\n");

    /*
    for(uint32 a=0xF000; a<0xF000+256; a++) {
        AddrH_Write((a>>8)&0xFF);
        AddrL_Write(a&0xFF);
        MR_Write(0);
        CyDelayUs(5);
        r=Dta_Read();
        CyDelayUs(5);
        if((a&0x1F)==0x00)
            USBUART_printf("%04X: ", a);
        USBUART_printf("%02X", r);
        if((a&0x1F)==0x1F)
            USBUART_printf("\r\n");
    }
    */
    for(uint32 a=0xF800; a<0xF800+1280; a++) {
        AddrH_Write((a>>8)&0xFF);
        AddrL_Write(a&0xFF);
        // read current value
        MR_Write(0);
        CyDelayUs(5);
        r=Dta_Read();
        MR_Write(1);
        CyDelayUs(5);
        
        // write 0xA5
        BusDta_Write(0xA5);
        // BusData to bus (DATAOUT CTL OER WE MSEL)
        SRAM_Ctl_Write(0b10111);
        MW_Write(0);
        CyDelayUs(5);
        MW_Write(1);
        SRAM_Ctl_Write(0b00111);
        CyDelayUs(5);
        // check 0xA5
        MR_Write(0);
        CyDelayUs(5);
        if(Dta_Read()!=0xA5) {
            USBUART_printf("Error at %04X, expected %02X, found %02X\r\n", a, 0xA5, Dta_Read());
            err++;
        }
        MR_Write(1);
        CyDelayUs(5);
        
        // write 0x5A
        BusDta_Write(0x5A);
        // BusData to bus (DATAOUT CTL OER WE MSEL)
        SRAM_Ctl_Write(0b10111);
        MW_Write(0);
        CyDelayUs(5);
        MW_Write(1);
        SRAM_Ctl_Write(0b00111);
        CyDelayUs(5);
        // check 0x5A
        MR_Write(0);
        CyDelayUs(5);
        if(Dta_Read()!=0x5A) {
            USBUART_printf("Error at %04X, expected %02X, found %02X\r\n", a, 0x5A, Dta_Read());
            err++;
        }
        MR_Write(1);
        CyDelayUs(5);

        CyDelay(1);
        
        // write back original value
        BusDta_Write(r);
        // BusData to bus (DATAOUT CTL OER WE MSEL)
        SRAM_Ctl_Write(0b10111);
        MW_Write(0);
        CyDelayUs(5);
        MW_Write(1);
        SRAM_Ctl_Write(0b00111);
        CyDelayUs(5);
    }
    
    SRAM_Ctl_Write(0b00111);
    AddrL_Write(0);
    AddrL_SetDriveMode(PIN_DM_DIG_HIZ);
    AddrH_Write(0);
    AddrH_SetDriveMode(PIN_DM_DIG_HIZ);
    MR_Write(1);
    MR_SetDriveMode(PIN_DM_DIG_HIZ);
    MW_Write(1);
    MW_SetDriveMode(PIN_DM_DIG_HIZ);
    
    if(err==0) {
        USBUART_printf("No erros found :-)\r\n", err);
    } else {
        USBUART_printf("Found %d errors :-(\r\n", err);
    }
    
    Release_SAPI_Bus();
}

void WriteIO8(uint8 port, uint8 value) {
    // do not call this without reserving bus first
    AddrL_Write(port);
    BusDta_Write(value);
    SRAM_Ctl_Write(0b10111);
    //CyDelayUs(5);
    IOW_Write(0);
    CyDelayUs(4);
    IOW_Write(1);
    SRAM_Ctl_Write(0b00111);
    //CyDelayUs(5);
}

uint8 ReadIO8(uint8 port) {
    // do not call this without reserving bus first
    uint8 res;
    
    AddrL_Write(port);
    //CyDelayUs(5);
    IOR_Write(0);
    CyDelayUs(4);
    res = Dta_Read();
    IOR_Write(1);
    //CyDelayUs(5);
    
    return res;
}

char HexChar[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
char dva[3];

void DumpZRMD() {
    if(!Get_SAPI_Bus()) {
        return;
    }

    uint8 i = 0;
    char tmpstr[64];
    
    // pripravime si vychozi hodnoty pro sbernici
    AddrL_Write(0);
    AddrH_Write(0);
    IOR_Write(1);
    IOW_Write(1);

    AddrL_SetDriveMode(PIN_DM_STRONG);
    AddrH_SetDriveMode(PIN_DM_STRONG);
    IOR_SetDriveMode(PIN_DM_STRONG);
    IOW_SetDriveMode(PIN_DM_STRONG);

    /*gfx_setCursor(0,32);
    gfx_println("Dump ZRMD ");
    gfx_println("          ");
    display_update();*/
    
    // a jdeme zkusit precist RD
    uint16 r, had, mad, lad, chk;
    for(had=0; had<64; had++) {
        chk = 2 + 0 + 0 + 4 + ((had & 0xFF00)>>8) + (had & 0x00FF);
        chk = (0x100 - (chk & 0x00FF)) & 0xFF;
        USBUART_printf(":02000004%04X%02X\r\n", had, chk);
        /*gfx_setCursor(0,48);
        sprintf(tmpstr, "Seg.%02X%3d%%", had, (had*100)/64);
        gfx_println(tmpstr);
        display_update();*/
        for(mad=0; mad<256; mad++) {
            
            // dolni cast adresy
            WriteIO8(0x61, 0);
            // stredni cast adresy
            WriteIO8(0x62, mad);
            // horni cast adresy
            WriteIO8(0x63, had);
            
            for(lad=0; lad<256; lad+=1) {
                if((lad & 0x001F)==0x0000) {
                    chk = 0x20 + mad + lad;
                    USBUART_printf(":20%02X%02X00", mad, lad);
                }
                
                //for(i=0; i<2; i++) {
                    r = ReadIO8(0x60);
                    chk += r;
                    tmpstr[i*2]=HexChar[r>>4];
                    tmpstr[i*2+1]=HexChar[r&0x0F];
                //}
                tmpstr[2]=0;
                while(!USBUART_CDCIsReady());
                USBUART_PutString(tmpstr);
                //USBUART_printf(tmpstr);
                
                if((lad & 0x001F)==0x001F) {
                    chk = (0x100 - (chk & 0x00FF)) & 0xFF;
                    USBUART_printf("%02X\r\n", chk);
                }
            }
        }
    }
    USBUART_printf(":00000001FF\r\n");
    
    // uvolnime sbernici        
    AddrL_SetDriveMode(PIN_DM_DIG_HIZ);
    AddrH_SetDriveMode(PIN_DM_DIG_HIZ);
    IOR_SetDriveMode(PIN_DM_DIG_HIZ);
    IOW_SetDriveMode(PIN_DM_DIG_HIZ);

    /*gfx_setCursor(0,32);
    gfx_print("Ready     ");
    gfx_print("          ");
    display_update();*/

    Release_SAPI_Bus();
}

void Write_ZRMD(uint8 had, uint8 mad, uint8 lad, uint8 *dta, uint16 len) {
    if(!Get_SAPI_Bus_Silent()) {
        return;
    }

    //uint32 WZbegin = Millis_ReadCounter();
    
    // pripravime si vychozi hodnoty pro sbernici
    AddrL_Write(0);
    AddrH_Write(0);
    IOR_Write(1);
    IOW_Write(1);

    // sbernici bychom si bez dovoleni vzali pros sebe, jestli je pripojena JPR-1Z pujde to kolize
    AddrL_SetDriveMode(PIN_DM_STRONG);
    AddrH_SetDriveMode(PIN_DM_STRONG);
    IOR_SetDriveMode(PIN_DM_STRONG);
    IOW_SetDriveMode(PIN_DM_STRONG);

    //uint32 WZsetpins = Millis_ReadCounter();

    //gfx_setCursor(0,32);
    //gfx_print("Write ZRMD");
    //gfx_print("          ");
    //display_update();

    //uint32 WZdisp1 = Millis_ReadCounter();

    // dolni cast adresy
    WriteIO8(0x61, lad);
    // stredni cast adresy
    WriteIO8(0x62, mad);
    // horni cast adresy
    WriteIO8(0x63, had);

    for(int i=0; i<len; i++) {
        WriteIO8(0x60, *(dta+i));
    }

    // dolni cast adresy
    WriteIO8(0x61, lad);
    // stredni cast adresy
    WriteIO8(0x62, mad);
    // horni cast adresy
    WriteIO8(0x63, had);

    //uint32 WZwritten = Millis_ReadCounter();

    // jdeme cist (verifikovat)
    
    uint8 r;
    int err=0;
    for(int i=0; i<len; i++) {
        r = ReadIO8(0x60);
        if(r!=*(dta+i))
            err++;
    }
    
    //uint32 WZverified = Millis_ReadCounter();

    //gfx_setCursor(0,32);
    //gfx_print("Write ZRMD");
    if(err==0) {
        USBUART_printf("OK\r\n");
        //gfx_print("OK        ");
    } else {
        USBUART_printf("%d ERRORs writing data :-(\r\n", err);
        //gfx_print("FAILED    ");
    }
    //display_update();

    //uint32 WZdisp2 = Millis_ReadCounter();

    // uvolnime sbernici        
    AddrL_SetDriveMode(PIN_DM_DIG_HIZ);
    AddrH_SetDriveMode(PIN_DM_DIG_HIZ);
    IOR_SetDriveMode(PIN_DM_DIG_HIZ);
    IOW_SetDriveMode(PIN_DM_DIG_HIZ);
    
    //uint32 WZend = Millis_ReadCounter();
    //USBUART_printf("Write ZRMD line took %d ms.\r\n", WZend-WZbegin);
    //USBUART_printf("WZbegin %d, WZsetpins %d, WZdisp1 %d, WZwritten %d, WZverified %d, WZdisp2 %d, WZend %d\r\n", WZbegin, WZsetpins, WZdisp1, WZwritten, WZverified, WZdisp2, WZend);
    Release_SAPI_Bus_Silent();
}

void ProcessHEX(char *cmdline) {
    char *bptr = cmdline+1;
    uint8 hexdata[37];
    uint8 hexlen = 0;
    
    // USBUART_printf("\r\nHEX >%s<\r\n", bptr);

    //uint32 PHbegin = Millis_ReadCounter();
    
    cntLines++;

    while(strlen(bptr)>1 && hexlen<37) {
        switch(*bptr) {
            case '0' ... '9':
                hexdata[hexlen] = (*bptr - '0')<<4;
                break;
            case 'A' ... 'F':
                hexdata[hexlen] = (*bptr - 'A' + 10)<<4;
                break;
            default:
                USBUART_printf("Bad data on pos %d", bptr-cmdline);
                cntErrs++;
                return;
        }
        bptr++;
        switch(*bptr) {
            case '0' ... '9':
                hexdata[hexlen] += (*bptr - '0');
                break;
            case 'A' ... 'F':
                hexdata[hexlen] += (*bptr - 'A' + 10);
                break;
            default:
                USBUART_printf("Bad data on pos %d", bptr-cmdline);
                cntErrs++;
                return;
        }
        bptr++;
        hexlen++;            
    }
    uint16 chk = 0;
    if(hexlen<5) {
        USBUART_printf("Not enough data bytes, only %d\r\n", hexlen);
        cntErrs++;
        return;
    }
    for(int i=0; i<hexlen-1; i++) {
        chk += hexdata[i];
    }
    chk = (0x100 - (chk & 0x00FF)) & 0xFF;
    if(chk!=hexdata[hexlen-1]) {
        USBUART_printf("Bad checksum! Found %02X, but should be %02X :-(\r\n", hexdata[hexlen-1], chk);
        cntErrs++;
        return;
    }
    if(hexdata[0]!=hexlen-5) {
        USBUART_printf("Bad length! Found %02X, but should be %02X :-(\r\n", hexdata[0], hexlen-5);
        cntErrs++;
        return;
    }
    // uint32 WZbegin, WZend;
    switch(hexdata[3]) {
        case 0x00: // Data
            // USBUART_printf("Data\r\n");
            //WZbegin = Millis_ReadCounter();
            Write_ZRMD(extaddr & 0x3F, hexdata[1], hexdata[2], &hexdata[4], hexdata[0]);
            //WZend = Millis_ReadCounter();
            //USBUART_printf("Write ZRMD line took %d ms.\r\n", WZend-WZbegin);
            break;
        case 0x01: // End Of File
            USBUART_printf("End Of File\r\n");
            break;
        case 0x04: // Extended Linear Address
            if(hexlen<7) {
                USBUART_printf("Not enough data bytes for Extended Linear Address, only %d\r\n", hexlen);
                cntErrs++;
                return;
            }
            extaddr = (hexdata[4]<<8) + hexdata[5];
            USBUART_printf("Extended Linear Address set to %04X\r\n", extaddr);
            break;
    }
    
    //uint32 PHend = Millis_ReadCounter();
    //USBUART_printf("Process HEX line took %d ms.\r\n", PHend-PHbegin);
}

void HEX_read() {
    char inbuf[128];
    char cmdline[128];
    char *crpos;
    int dtalen=0;
    int rem=0;
    for(;;) {
        if(USBUART_DataIsReady()) {
            dtalen += USBUART_GetAll((uint8 *)(inbuf+rem+dtalen));
            // USBUART_printf("received %d\r\n", dtalen);
        }
        if(dtalen+rem>0 && inbuf[0]!=':') {
            USBUART_printf("Invalid content received\r\n");
            return;
        }
        while(dtalen+rem>0 && (crpos = memchr(inbuf, 0x0D, dtalen+rem))!=NULL) {
            strncpy(cmdline, inbuf, crpos-inbuf);
            cmdline[crpos-inbuf]=0;
            rem=dtalen+rem-(crpos-inbuf)-1;
            //USBUART_printf("inbuf %04X, crpos %04X, datalen %d, rem %d\r\n", inbuf, crpos, dtalen, rem);
            memcpy(inbuf, crpos+1, rem);
            USBUART_printf("%s\r\n", cmdline);
            ProcessHEX(cmdline);
            dtalen=0;
        }
        
    }
}

void ShowHelp() {
    USBUART_printf("\r\n");
    USBUART_printf("zdump   ... dump ZRMD as HEX to USB serial\r\n");
    //USBUART_printf("dumpu ... dump ZRMD as HEX to RS232 UART\r\n");
    USBUART_printf(":       ... line starting with : will be interpreted as Intel HEX line to ZRMD\r\n");
    USBUART_printf("hex     ... start special and faster Intel HEX input mode for ZRMD\r\n");
    USBUART_printf("rescnt  ... reset time counter, number of imported lines and errors\r\n");
    USBUART_printf("cnt     ... show time counter, number of imported lines and errors\r\n");
    USBUART_printf("dm      ... dump memory\r\n");
    USBUART_printf("tron    ... trace for 16 instructions\r\n");
    USBUART_printf("vidtest ... test of AND-1Z video RAM (non destructive)\r\n");
    USBUART_printf("memtest ... test of DTR-1 RAM, test is destructive and needs reset at end\r\n");
    USBUART_printf("reset   ... SAPI-1 reset (RTL pulse)\r\n");
    USBUART_printf("help, ? or h ... show this help\r\n");
    USBUART_printf("\r\n");

    /*
    if(rdCnt!=intCnt) {
        USBUART_printf("\r\nProcessing %d OUT interrupts:\r\n", intCnt-rdCnt);
        while(rdCnt!=intCnt) {
            USBUART_printf("OUT: port=%d data=%d\r\n", intQueue[rdCnt].port, intQueue[rdCnt].data);
            // uint8 intStatus = CyEnterCriticalSection();
            rdCnt++;
            //CyExitCriticalSection(intStatus);
        }
    }
    */
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    RCM_Int_StartEx( UART_OUT_RCM_Handler );
    RCU_Int_StartEx( UART_OUT_RCU_Handler );
    ROD_Int_StartEx( UART_OUT_ROD_Handler );
    RST_Int_StartEx( UART_OUT_RST_Handler );
    RRD_Int_StartEx( UART_IN_RRD_Handler );
    M1_Int_StartEx( M1_Int_Handler );
    M1_Int_Disable();
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    //AddrL_Write(0);
    
    Millis_Start();
    I2COLED_Start();
    UART_Start();
    // uint8 oledStatus = I2COLED_MasterStatus();
    // UART_printf("I2COLED_MasterStatus() = %02X\r\n", oledStatus);
    if(I2COLED_MasterSendStart(DISPLAY_ADDRESS, 0)) {
        I2COLED_MasterSendStop();
        // UART_printf("OLED display NOT present on the bus\r\n");
        noOLED = 1;
    } else {
        I2COLED_MasterSendStop();
        // UART_printf("OLED display present in the bus\r\n");
        //uint8 iniseq[] = {0xA8, 0x3F, 0xD3, 0x00, 0x40, 0xA0, 0xC0, 0xDA, 0x02, 0x81, 0x7F, 0xA4, 0xA6, 0xD5, 0x80, 0x8D, 0x14, 0xAF};
        // I2COLED_MasterClearStatus();
        //I2COLED_MasterWriteBuf(DISPLAY_ADDRESS, &iniseq, 18, 0 ); //I2C_MODE_COMPLETE_XFER
        //CyDelay(1000);
        noOLED = 0;
        display_init(DISPLAY_ADDRESS);
        display_clear();    
        gfx_setTextSize(2);
        gfx_setTextColor(WHITE);
        gfx_setTextBg(BLACK);
        gfx_setCursor(0,0);
        gfx_println("SAPI DTR-1");
        gfx_println("8bity.cz");
        gfx_println("2021042501");
        display_update();
    }

    cntTime = Millis_ReadCounter();
    
    USBUART_Start(0, USBUART_5V_OPERATION); //!!NOTE!! Make sure this matches your board voltage!
    uint32 timeout = Millis_ReadCounter();
    while((!USBUART_GetConfiguration()) && (Millis_ReadCounter()-timeout<2000)){
        CyDelay(1);
    }
    if(Millis_ReadCounter()-timeout<2000) {
        USBUART_CDC_Init();
        noUART = 0;
        /*gfx_setCursor(0,32);
        gfx_print("Ready     ");
        gfx_print("          ");
        display_update();*/
    } else {
        noUART = 1;
        /*gfx_setCursor(0,32);
        gfx_print("No USBUART");
        gfx_print("          ");
        display_update();*/
    }
    USBUART_printf("");
    USBUART_printf("\r\nSAPI-1 DTR-1 board based on CY8CKIT-059           ");
    USBUART_printf("     (c) 2021 martin@8bity.cz\r\n\r\n");

    //USBUART_printf("CTS = %d\r\n", CTS_Read());
    if( CTS_Read()==1 ) {
        RSM_Write(0x20);
        USBUART_printf("Console set to AND-1Z and Consul 262.3/259.11\r\n");
    } else {
        RSM_Write(0x00);
        USBUART_printf("Console set to RS-232c RTS/CTS flow control\r\n");
        UART_printf("\r\nHello to UART RS-232c console\r\n");
    }
    
    if(noOLED) {
        USBUART_printf("OLED display not found.\r\n");
    } else {
        USBUART_printf("OLED display detected.\r\n");
    }
    instCnt=0;
    instRdCnt=0;
    nWAIT_Write(1);
    //CyDelay(2);
    SAPI_Reset();
    int getInst=0;
    int tron=0;
    M1_Int_ClearPending();
    // M1_Int_Enable();
    
    
    char cmdline[128];
    uint8 inbuf[64];
    cmdline[0] = 0;
    char ch;
    // char tmpstr[256];
    int len;
    uint8 noPrompt = 0;

    USBUART_printf("DTR>");
    for(;;)
    {
        // process DSM-1 Register interrupt queue
        if(rdCnt!=intCnt) {
            // USBUART_printf("\r\nProcessing %d OUT interrupts:\r\n", intCnt-rdCnt);
            while(rdCnt!=intCnt) {
                // USBUART_printf("OUT: port=%d data=%d\r\n", intQueue[rdCnt].port, intQueue[rdCnt].data);
                // uint8 intStatus = CyEnterCriticalSection();
                switch(intQueue[rdCnt].port) {
                    case 0x10: // RCM
                        break;
                    case 0x11: // RCU
                        break;
                    case 0x12: // ROD
                        UART_PutChar(intQueue[rdCnt].data);
                        break;
                    case 0x13: // RST
                        break;
                }
                rdCnt++;
                //CyExitCriticalSection(intStatus);
            }
        }

        // process Instruction (M1) interrupt queue
        if(instRdCnt!=instCnt) {
            if(getInst>0) {
                USBUART_printf("TR %04X:%02X\r\n", instQueue[instRdCnt].addr, instQueue[instRdCnt].data);
                getInst--;
                if(getInst==0) {
                    M1_Int_Disable();
                    M1_Int_ClearPending();
                    tron=0;
                    USBUART_printf("DTR>");
                    noPrompt = 0;
                }
            }
            //USBUART_printf("%02X ", instQueue[instRdCnt].data);
            instRdCnt++;
            if(instRdCnt==instCnt)
                nWAIT_Write(1);
        }
        
        if(UART_GetRxBufferSize()>0) {
            RRD_Write( UART_GetByte() & 0x00FF );
            RSU_Write( RSU_Read() | 0x80 );
        }
        // process USBUART - command line
        if(USBUART_DataIsReady()>0) {
            int dtalen = USBUART_GetAll(inbuf);
            for(int i=0; i<dtalen; i++) {
                ch = inbuf[i];
                switch(ch) {
                  case 0x08: // backpasce
                    len = strlen(cmdline);
                    if(len>0) {
                        cmdline[len-1] = 0;
                        USBUART_printf("\b \b");            
                    }
                    break;
                  case 0x0D: // Enter
                    // USBUART_printf("\r\nWill process: [%s]\r\n", cmdline);
                    USBUART_printf("\r\n");
                    int cmdprocessed = 0;
                    if(cmdline[0]==':' && !cmdprocessed) {
                        ProcessHEX(cmdline);
                        cmdprocessed = 1;
                        noPrompt = 0;
                    }
                    if((strncmp(cmdline, "help", 4)==0 || strcmp(cmdline, "?")==0 || strcmp(cmdline, "h")==0) && !cmdprocessed) {
                        ShowHelp();
                        cmdprocessed = 1;
                        noPrompt = 0;
                    }
                    if(strcmp(cmdline, "zdump")==0 && !cmdprocessed) {
                        DumpZRMD();
                        cmdprocessed = 1;
                        noPrompt = 0;
                    }
                    if(strcmp(cmdline, "dumpu")==0 && !cmdprocessed) {
                        // DumpZRMD_UART();
                        cmdprocessed = 1;
                        noPrompt = 0;
                    }
                    if(strcmp(cmdline, "dm")==0 && !cmdprocessed) {
                        DumpMem(0xF000);
                        cmdprocessed = 1;
                        noPrompt = 0;
                    }
                    if(strcmp(cmdline, "vidtest")==0 && !cmdprocessed) {
                        TestVideo();
                        cmdprocessed = 1;
                        noPrompt = 0;
                    }
                    if(strcmp(cmdline, "hex")==0 && !cmdprocessed) {
                        HEX_read();
                        cmdprocessed = 1;
                        noPrompt = 0;
                    }
                    if(strcmp(cmdline, "memtest")==0 && !cmdprocessed) {
                        RAM_check();
                        cmdprocessed = 1;
                        noPrompt = 0;
                    }
                    if(strcmp(cmdline, "reset")==0 && !cmdprocessed) {
                        SAPI_Reset();
                        cmdprocessed = 1;
                        noPrompt = 0;
                    }
                    if(strcmp(cmdline, "rescnt")==0 && !cmdprocessed) {
                        cntTime = Millis_ReadCounter();
                        cntLines = 0;
                        cntErrs = 0;
                        USBUART_printf("Counter reset.\r\n", cmdline);
                        cmdprocessed = 1;
                        noPrompt = 0;
                    }
                    if(strcmp(cmdline, "cnt")==0 && !cmdprocessed) {
                        USBUART_printf("Elapsed time = %d ms, %d lines processed, %d errors\r\n", Millis_ReadCounter()-cntTime, cntLines, cntErrs);
                        cmdprocessed = 1;
                        noPrompt = 0;
                    }
                    if(strcmp(cmdline, "tron")==0 && !cmdprocessed) {
                        if(!tron) {
                            instCnt=0;
                            instRdCnt=0;
                            M1_Int_ClearPending();
                            M1_Int_Enable();
                            tron=1;
                        }
                        getInst=16;
                        cmdprocessed = 1;
                        noPrompt = 1;
                    }
                    /*
                    if(strcmp(cmdline, "troff")==0 && !cmdprocessed) {
                        if(tron) {
                            M1_Int_Disable();
                            M1_Int_ClearPending();
                            tron=0;
                        }
                        cmdprocessed = 1;
                    } */
                    if(strlen(cmdline)!=0 && !cmdprocessed) {
                        USBUART_printf("\r\nUnknown command [%s], use \"help\" or \"?\" for help.\r\n\r\n", cmdline);
                    }
                    if(noPrompt==0)
                        USBUART_printf("DTR>");
                    cmdline[0] = 0;
                    break;
                  case 0x20 ... 0x7F:
                    // strncat(tmpstr, &ch, 1);
                    len = strlen(cmdline);
                    if(len<127) {
                        cmdline[len] = ch;
                        cmdline[len+1] = 0;
                        while(!USBUART_CDCIsReady()){}
                        USBUART_PutChar(ch);
                    }
                    break;
                }
            }
        }
        // after USBUART process
    }
}

/* [] END OF FILE */
