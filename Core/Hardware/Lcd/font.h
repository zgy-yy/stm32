//
// Created by acer-zgy on 2023/11/10.
//

#ifndef STM32_LEARN01_FONT_H
#define STM32_LEARN01_FONT_H
const unsigned char asc2_16x16[95][16] = {
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},/*" ",0*/
        {0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00,},/*"!",1*/
        {0x00, 0x00, 0x6C, 0x6C, 0x24, 0x24, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,},/*""",2*/
        {0x00, 0x24, 0x24, 0x24, 0x24, 0xFE, 0x48, 0x48, 0x48, 0x48, 0xFC, 0x90, 0x90, 0x90, 0x90, 0x00,},/*"#",3*/
        {0x00, 0x10, 0x3C, 0x54, 0x92, 0x90, 0x50, 0x38, 0x14, 0x12, 0x12, 0x92, 0x54, 0x78, 0x10, 0x00,},/*"$",4*/
        {0x00, 0x00, 0x22, 0x5C, 0x94, 0xA8, 0x48, 0x10, 0x10, 0x24, 0x2A, 0x52, 0x54, 0x88, 0x00, 0x00,},/*"%",5*/
        {0x00, 0x00, 0x30, 0x48, 0x48, 0x50, 0x20, 0x6E, 0x54, 0x94, 0x8C, 0x88, 0x8A, 0x74, 0x00, 0x00,},/*"&",6*/
        {0x00, 0x00, 0x30, 0x30, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},/*"'",7*/
        {0x00, 0x04, 0x08, 0x10, 0x10, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x08, 0x04, 0x00,},/*"(",8*/
        {0x00, 0x80, 0x40, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x20, 0x40, 0x80, 0x00,},/*")",9*/
        {0x00, 0x00, 0x00, 0x00, 0x10, 0x54, 0x38, 0x10, 0x38, 0x54, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,},/*"*",10*/
        {0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x10, 0xFE, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00,},/*"+",11*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x20, 0x00,},/*",",12*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},/*"-",13*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00,},/*".",14*/
        {0x00, 0x00, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00,},/*"/",15*/
        {0x00, 0x00, 0x38, 0x44, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x44, 0x38, 0x00, 0x00,},/*"0",16*/
        {0x00, 0x00, 0x10, 0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x7C, 0x00, 0x00,},/*"1",17*/
        {0x00, 0x00, 0x38, 0x44, 0x82, 0x82, 0x04, 0x08, 0x10, 0x20, 0x40, 0x82, 0x84, 0xFC, 0x00, 0x00,},/*"2",18*/
        {0x00, 0x00, 0x38, 0x44, 0x82, 0x02, 0x04, 0x38, 0x04, 0x02, 0x02, 0x82, 0x44, 0x38, 0x00, 0x00,},/*"3",19*/
        {0x00, 0x00, 0x04, 0x0C, 0x14, 0x14, 0x24, 0x24, 0x44, 0x44, 0xFE, 0x04, 0x04, 0x0E, 0x00, 0x00,},/*"4",20*/
        {0x00, 0x00, 0xFC, 0x80, 0x80, 0x80, 0xB8, 0xC4, 0x82, 0x02, 0x02, 0x82, 0x84, 0x78, 0x00, 0x00,},/*"5",21*/
        {0x00, 0x00, 0x3C, 0x42, 0x82, 0x80, 0xB8, 0xC4, 0x82, 0x82, 0x82, 0x82, 0x44, 0x38, 0x00, 0x00,},/*"6",22*/
        {0x00, 0x00, 0x7E, 0x42, 0x82, 0x04, 0x04, 0x08, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00,},/*"7",23*/
        {0x00, 0x00, 0x38, 0x44, 0x82, 0x82, 0x44, 0x38, 0x44, 0x82, 0x82, 0x82, 0x44, 0x38, 0x00, 0x00,},/*"8",24*/
        {0x00, 0x00, 0x38, 0x44, 0x82, 0x82, 0x82, 0x82, 0x46, 0x3A, 0x02, 0x82, 0x44, 0x38, 0x00, 0x00,},/*"9",25*/
        {0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00,},/*":",26*/
        {0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x20, 0x00, 0x00,},/*";",27*/
        {0x00, 0x00, 0x00, 0x00, 0x06, 0x18, 0x60, 0x80, 0x60, 0x18, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,},/*"<",28*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},/*"=",29*/
        {0x00, 0x00, 0x00, 0x00, 0xC0, 0x30, 0x0C, 0x02, 0x0C, 0x30, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,},/*">",30*/
        {0x00, 0x38, 0x44, 0x82, 0x82, 0x02, 0x04, 0x08, 0x10, 0x10, 0x10, 0x00, 0x10, 0x10, 0x00, 0x00,},/*"?",31*/
        {0x00, 0x00, 0x38, 0x44, 0x82, 0x9A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x96, 0x80, 0x42, 0x3C, 0x00,},/*"@",32*/
        {0x00, 0x00, 0x10, 0x10, 0x10, 0x28, 0x28, 0x28, 0x44, 0x44, 0x7C, 0x44, 0x44, 0xEE, 0x00, 0x00,},/*"A",33*/
        {0x00, 0x00, 0xFC, 0x42, 0x42, 0x42, 0x42, 0x7C, 0x42, 0x42, 0x42, 0x42, 0x42, 0xFC, 0x00, 0x00,},/*"B",34*/
        {0x00, 0x00, 0x3C, 0x44, 0x82, 0x80, 0x80, 0x80, 0x80, 0x80, 0x82, 0x82, 0x44, 0x38, 0x00, 0x00,},/*"C",35*/
        {0x00, 0x00, 0xF8, 0x44, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x44, 0xF8, 0x00, 0x00,},/*"D",36*/
        {0x00, 0x00, 0xFC, 0x44, 0x42, 0x40, 0x44, 0x7C, 0x44, 0x40, 0x40, 0x42, 0x44, 0xFC, 0x00, 0x00,},/*"E",37*/
        {0x00, 0x00, 0xFC, 0x44, 0x42, 0x40, 0x44, 0x7C, 0x44, 0x40, 0x40, 0x40, 0x40, 0xF0, 0x00, 0x00,},/*"F",38*/
        {0x00, 0x00, 0x34, 0x4C, 0x82, 0x80, 0x80, 0x80, 0x8E, 0x84, 0x84, 0x84, 0x4C, 0x34, 0x00, 0x00,},/*"G",39*/
        {0x00, 0x00, 0xEE, 0x44, 0x44, 0x44, 0x44, 0x7C, 0x44, 0x44, 0x44, 0x44, 0x44, 0xEE, 0x00, 0x00,},/*"H",40*/
        {0x00, 0x00, 0x7C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x7C, 0x00, 0x00,},/*"I",41*/
        {0x00, 0x00, 0x3E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x88, 0x88, 0x70, 0x00, 0x00,},/*"J",42*/
        {0x00, 0x00, 0xEE, 0x44, 0x48, 0x48, 0x50, 0x60, 0x50, 0x48, 0x48, 0x44, 0x44, 0xEE, 0x00, 0x00,},/*"K",43*/
        {0x00, 0x00, 0xE0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x42, 0x44, 0xFC, 0x00, 0x00,},/*"L",44*/
        {0x00, 0x00, 0xC6, 0x44, 0x6C, 0x6C, 0x6C, 0x54, 0x54, 0x54, 0x44, 0x44, 0x44, 0xEE, 0x00, 0x00,},/*"M",45*/
        {0x00, 0x00, 0xCE, 0x44, 0x64, 0x64, 0x64, 0x54, 0x54, 0x4C, 0x4C, 0x4C, 0x44, 0xE4, 0x00, 0x00,},/*"N",46*/
        {0x00, 0x00, 0x38, 0x44, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x44, 0x38, 0x00, 0x00,},/*"O",47*/
        {0x00, 0x00, 0xF8, 0x44, 0x42, 0x42, 0x42, 0x44, 0x78, 0x40, 0x40, 0x40, 0x40, 0xE0, 0x00, 0x00,},/*"P",48*/
        {0x00, 0x00, 0x38, 0x44, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0xBA, 0x44, 0x3C, 0x02, 0x00,},/*"Q",49*/
        {0x00, 0x00, 0xF0, 0x48, 0x44, 0x44, 0x44, 0x48, 0x70, 0x48, 0x44, 0x44, 0x44, 0xE6, 0x00, 0x00,},/*"R",50*/
        {0x00, 0x00, 0x3C, 0x44, 0x82, 0x80, 0x40, 0x30, 0x0C, 0x02, 0x02, 0x82, 0x44, 0x78, 0x00, 0x00,},/*"S",51*/
        {0x00, 0x00, 0x7C, 0x54, 0x92, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x00, 0x00,},/*"T",52*/
        {0x00, 0x00, 0xEE, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x38, 0x00, 0x00,},/*"U",53*/
        {0x00, 0x00, 0xEE, 0x44, 0x44, 0x44, 0x44, 0x28, 0x28, 0x28, 0x28, 0x10, 0x10, 0x10, 0x00, 0x00,},/*"V",54*/
        {0x00, 0x00, 0xEE, 0x44, 0x54, 0x54, 0x54, 0x54, 0x54, 0x54, 0x28, 0x28, 0x28, 0x28, 0x00, 0x00,},/*"W",55*/
        {0x00, 0x00, 0xEE, 0x44, 0x44, 0x28, 0x28, 0x10, 0x10, 0x28, 0x28, 0x44, 0x44, 0xEE, 0x00, 0x00,},/*"X",56*/
        {0x00, 0x00, 0xEE, 0x44, 0x44, 0x28, 0x28, 0x28, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x00, 0x00,},/*"Y",57*/
        {0x00, 0x00, 0x7E, 0x44, 0x84, 0x08, 0x08, 0x10, 0x20, 0x20, 0x40, 0x82, 0x84, 0xFC, 0x00, 0x00,},/*"Z",58*/
        {0x00, 0x1C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1C, 0x00,},/*"[",59*/
        {0x00, 0x00, 0xEE, 0x44, 0x54, 0x54, 0xFE, 0x54, 0x54, 0x54, 0x28, 0x28, 0x28, 0x28, 0x00, 0x00,},/*"\",60*/
        {0x00, 0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x70, 0x00,},/*"]",61*/
        {0x00, 0x30, 0x48, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},/*"^",62*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00,},/*"_",63*/
        {0x00, 0x40, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},/*"`",64*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x84, 0x04, 0x7C, 0x84, 0x84, 0x8C, 0x76, 0x00, 0x00,},/*"a",65*/
        {0x00, 0x00, 0xC0, 0x40, 0x40, 0x40, 0x58, 0x64, 0x42, 0x42, 0x42, 0x42, 0x64, 0x58, 0x00, 0x00,},/*"b",66*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x44, 0x80, 0x80, 0x80, 0x80, 0x44, 0x38, 0x00, 0x00,},/*"c",67*/
        {0x00, 0x00, 0x0C, 0x04, 0x04, 0x04, 0x34, 0x4C, 0x84, 0x84, 0x84, 0x84, 0x4C, 0x36, 0x00, 0x00,},/*"d",68*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x84, 0x84, 0xFC, 0x80, 0x80, 0x84, 0x78, 0x00, 0x00,},/*"e",69*/
        {0x00, 0x00, 0x18, 0x24, 0x20, 0x20, 0xF8, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70, 0x00, 0x00,},/*"f",70*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3A, 0x44, 0x44, 0x78, 0x80, 0x7C, 0x82, 0x82, 0x7C, 0x00,},/*"g",71*/
        {0x00, 0x00, 0xC0, 0x40, 0x40, 0x40, 0x58, 0x64, 0x44, 0x44, 0x44, 0x44, 0x44, 0xEE, 0x00, 0x00,},/*"h",72*/
        {0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x00, 0x00,},/*"i",73*/
        {0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x90, 0x60, 0x00,},/*"j",74*/
        {0x00, 0x00, 0xC0, 0x40, 0x40, 0x40, 0x5C, 0x48, 0x50, 0x60, 0x50, 0x48, 0x44, 0xEE, 0x00, 0x00,},/*"k",75*/
        {0x00, 0x00, 0x30, 0x10, 0x10, 0x10, 0x10, 0x11, 0x10, 0x10, 0x10, 0x10, 0x10, 0x39, 0x00, 0x00,},/*"l",76*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAC, 0xD2, 0x92, 0x92, 0x92, 0x92, 0x92, 0xD6, 0x00, 0x00,},/*"m",77*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x58, 0xE4, 0x44, 0x44, 0x44, 0x44, 0x44, 0xEE, 0x00, 0x00,},/*"n",78*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x44, 0x82, 0x82, 0x82, 0x82, 0x44, 0x38, 0x00, 0x00,},/*"o",79*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD8, 0x64, 0x42, 0x42, 0x42, 0x64, 0x58, 0x40, 0xE0, 0x00,},/*"p",80*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x4C, 0x84, 0x84, 0x84, 0x4C, 0x34, 0x04, 0x0E, 0x00,},/*"q",81*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6C, 0x30, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70, 0x00, 0x00,},/*"r",82*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x88, 0x84, 0x60, 0x18, 0x84, 0x44, 0x78, 0x00, 0x00,},/*"s",83*/
        {0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0xF8, 0x20, 0x20, 0x20, 0x20, 0x20, 0x24, 0x18, 0x00, 0x00,},/*"t",84*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC6, 0x42, 0x42, 0x42, 0x42, 0x42, 0x46, 0x3A, 0x00, 0x00,},/*"u",85*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEE, 0x44, 0x44, 0x28, 0x28, 0x28, 0x10, 0x10, 0x00, 0x00,},/*"v",86*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEE, 0x44, 0x44, 0x54, 0x54, 0x28, 0x28, 0x28, 0x00, 0x00,},/*"w",87*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEE, 0x44, 0x28, 0x10, 0x10, 0x28, 0x44, 0xEE, 0x00, 0x00,},/*"x",88*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEE, 0x44, 0x44, 0x28, 0x28, 0x10, 0x10, 0xA0, 0xC0, 0x00,},/*"y",89*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x44, 0x88, 0x10, 0x20, 0x42, 0x84, 0xFC, 0x00, 0x00,},/*"z",90*/
        {0x00, 0x0C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x60, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0C, 0x00,},/*"{",91*/
        {0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00,},/*"|",92*/
        {0x00, 0xC0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x18, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xC0, 0x00,},/*"}",93*/
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x72, 0x8C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,},/*"~",94*/
};

#endif //STM32_LEARN01_FONT_H
