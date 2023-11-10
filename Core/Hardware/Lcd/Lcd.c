
#include "stm32f10x.h"
#include "Lcd.h"
#include "delay.h"


#define LCD_SCL            GPIO_Pin_15    //PB13--->>TFT --SCL/SCK
#define LCD_SDA            GPIO_Pin_13    //PB15 MOSI--->>TFT --SDA/DIN

#define LCD_CS            GPIO_Pin_12  //B12 --CS/CE
#define LCD_RS            GPIO_Pin_14    //B14  --RS/DC
#define LCD_RST        GPIO_Pin_5    //PB5  --RST

#define    LCD_CS_SET    GPIOB->BSRR=LCD_CS
#define    LCD_CS_CLR    GPIOB->BRR=LCD_CS

#define    LCD_RS_SET    GPIOB->BSRR=LCD_RS
#define    LCD_RS_CLR    GPIOB->BRR=LCD_RS

#define    LCD_RST_SET    GPIOB->BSRR=LCD_RST
#define    LCD_RST_CLR    GPIOB->BRR=LCD_RST

void LCD_GPIO_Init(void) {

    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitStructure.GPIO_Pin = LCD_CS | LCD_RS | LCD_RST;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);


    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef gpio_spi_config = {
            .GPIO_Pin=LCD_SCL | LCD_SDA,
            .GPIO_Mode=GPIO_Mode_AF_PP,
            .GPIO_Speed=GPIO_Speed_50MHz
    };
    GPIO_Init(GPIOB, &gpio_spi_config);

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);

    SPI_InitTypeDef spi_config = {
            .SPI_Mode=SPI_Mode_Master,
            .SPI_Direction=SPI_Direction_2Lines_FullDuplex,
            .SPI_DataSize=SPI_DataSize_8b,//8 位数据
            .SPI_FirstBit=SPI_FirstBit_MSB,//高位先行
            .SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_2,
            .SPI_CPOL=SPI_CPOL_High,
            .SPI_CPHA=SPI_CPHA_2Edge,
            .SPI_NSS=SPI_NSS_Soft,
            .SPI_CRCPolynomial=7
    };

    SPI_Init(SPI2, &spi_config);
    SPI_Cmd(SPI2, ENABLE);
}

void SPI_WriteData(uint8_t Data) {
    while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) != SET);
    SPI_I2S_SendData(SPI2, Data);
    while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);
}


void Lcd_WriteIndex(uint8_t Index) {
    LCD_CS_CLR;
    LCD_RS_CLR;
    SPI_WriteData(Index);
    LCD_CS_SET;
}


void Lcd_WriteData(uint8_t Data) {
    LCD_CS_CLR;
    LCD_RS_SET;
    SPI_WriteData(Data);
    LCD_CS_SET;
}


void LCD_WriteData_16Bit(u16 Data) {
    LCD_CS_CLR;
    LCD_RS_SET;
    SPI_WriteData(Data >> 8);
    SPI_WriteData(Data);
    LCD_CS_SET;
}

void Lcd_WriteReg(uint8_t Index, uint8_t Data) {
    Lcd_WriteIndex(Index);
    Lcd_WriteData(Data);
}

void Lcd_Reset(void) {
    LCD_RST_CLR;
    Delay_ms(100);
    LCD_RST_SET;
    Delay_ms(50);
}

//LCD Init For 1.44Inch LCD Panel with ST7735R.
void Lcd_Init(void) {
    LCD_GPIO_Init();
    Lcd_Reset(); //Reset before LCD Init.

    //LCD Init For 1.44Inch LCD Panel with ST7735R.
    Lcd_WriteIndex(0x11);//Sleep exit
    Delay_ms(120);

    //ST7735R Frame Rate
    Lcd_WriteIndex(0xB1);
    Lcd_WriteData(0x01);
    Lcd_WriteData(0x2C);
    Lcd_WriteData(0x2D);

    Lcd_WriteIndex(0xB2);
    Lcd_WriteData(0x01);
    Lcd_WriteData(0x2C);
    Lcd_WriteData(0x2D);

    Lcd_WriteIndex(0xB3);
    Lcd_WriteData(0x01);
    Lcd_WriteData(0x2C);
    Lcd_WriteData(0x2D);
    Lcd_WriteData(0x01);
    Lcd_WriteData(0x2C);
    Lcd_WriteData(0x2D);

    Lcd_WriteIndex(0xB4); //Column inversion
    Lcd_WriteData(0x07);

    //ST7735R Power Sequence
    Lcd_WriteIndex(0xC0);
    Lcd_WriteData(0xA2);
    Lcd_WriteData(0x02);
    Lcd_WriteData(0x84);
    Lcd_WriteIndex(0xC1);
    Lcd_WriteData(0xC5);

    Lcd_WriteIndex(0xC2);
    Lcd_WriteData(0x0A);
    Lcd_WriteData(0x00);

    Lcd_WriteIndex(0xC3);
    Lcd_WriteData(0x8A);
    Lcd_WriteData(0x2A);
    Lcd_WriteIndex(0xC4);
    Lcd_WriteData(0x8A);
    Lcd_WriteData(0xEE);

    Lcd_WriteIndex(0xC5); //VCOM
    Lcd_WriteData(0x0E);

    Lcd_WriteIndex(0x36); //MX, MY, RGB mode
    Lcd_WriteData(0xC0);

    //ST7735R Gamma Sequence
    Lcd_WriteIndex(0xe0);
    Lcd_WriteData(0x0f);
    Lcd_WriteData(0x1a);
    Lcd_WriteData(0x0f);
    Lcd_WriteData(0x18);
    Lcd_WriteData(0x2f);
    Lcd_WriteData(0x28);
    Lcd_WriteData(0x20);
    Lcd_WriteData(0x22);
    Lcd_WriteData(0x1f);
    Lcd_WriteData(0x1b);
    Lcd_WriteData(0x23);
    Lcd_WriteData(0x37);
    Lcd_WriteData(0x00);
    Lcd_WriteData(0x07);
    Lcd_WriteData(0x02);
    Lcd_WriteData(0x10);

    Lcd_WriteIndex(0xe1);
    Lcd_WriteData(0x0f);
    Lcd_WriteData(0x1b);
    Lcd_WriteData(0x0f);
    Lcd_WriteData(0x17);
    Lcd_WriteData(0x33);
    Lcd_WriteData(0x2c);
    Lcd_WriteData(0x29);
    Lcd_WriteData(0x2e);
    Lcd_WriteData(0x30);
    Lcd_WriteData(0x30);
    Lcd_WriteData(0x39);
    Lcd_WriteData(0x3f);
    Lcd_WriteData(0x00);
    Lcd_WriteData(0x07);
    Lcd_WriteData(0x03);
    Lcd_WriteData(0x10);

    Lcd_WriteIndex(0x2a);
    Lcd_WriteData(0x00);
    Lcd_WriteData(0x00);
    Lcd_WriteData(0x00);
    Lcd_WriteData(0x7f);

    Lcd_WriteIndex(0x2b);
    Lcd_WriteData(0x00);
    Lcd_WriteData(0x00);
    Lcd_WriteData(0x00);
    Lcd_WriteData(0x9f);

    Lcd_WriteIndex(0xF0); //Enable test command
    Lcd_WriteData(0x01);
    Lcd_WriteIndex(0xF6); //Disable ram power save mode
    Lcd_WriteData(0x00);

    Lcd_WriteIndex(0x3A); //65k mode
    Lcd_WriteData(0x05);


    Lcd_WriteIndex(0x29);//Display on
}


void Lcd_SetRegion(u16 x_start, u16 y_start, u16 x_end, u16 y_end) {
    Lcd_WriteIndex(0x2a);
    Lcd_WriteData(x_start >> 8);
    Lcd_WriteData(x_start);//Lcd_WriteData(x_start+2);
    Lcd_WriteData(x_end >> 8);
    Lcd_WriteData(x_end);

    Lcd_WriteIndex(0x2b);
    Lcd_WriteData(y_start >> 8);
    Lcd_WriteData(y_start);
    Lcd_WriteData(y_end >> 8);
    Lcd_WriteData(y_end);

    Lcd_WriteIndex(0x2c);
}


void Lcd_SetXY(u16 x, u16 y) {
    Lcd_SetRegion(x, y, x, y);
}


void Lcd_DrawPoint(u16 x, u16 y, u16 Data) {
    Lcd_SetRegion(x, y, x + 1, y + 1);
    LCD_WriteData_16Bit(Data);
}


unsigned int Lcd_ReadPoint(u16 x, u16 y) {
    unsigned int Data;
    Lcd_SetXY(x, y);

    //Data=Lcd_ReadData();
    Lcd_WriteData(Data);
    return Data;
}

void Lcd_Clear(u16 Color) {
    unsigned int i, m;
    Lcd_SetRegion(0, 0, X_MAX_PIXEL - 1, Y_MAX_PIXEL - 1);

    for (i = 0; i < X_MAX_PIXEL; i++)
        for (m = 0; m < Y_MAX_PIXEL; m++) {
            LCD_WriteData_16Bit(Color);
        }
}

