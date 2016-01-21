#include "stm32f0xx.h";
#include "stm32f0xx_hal_gpio.h";

#include "pins.h"
void setDisplayClear(){
	HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_A_PIN,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_B_PIN,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_C_PIN,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_D_PIN,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_E_PIN,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_F_PIN,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_G_PIN,GPIO_PIN_RESET);
}
void setDisplayVal(int number){
	switch (number){
	case 0:
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_A_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_B_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_C_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_D_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_E_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_F_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_G_PIN,GPIO_PIN_RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_A_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_B_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_C_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_D_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_E_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_F_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_G_PIN,GPIO_PIN_RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_A_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_B_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_C_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_D_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_E_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_F_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_G_PIN,GPIO_PIN_SET);
		break;
	case 3:
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_A_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_B_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_C_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_D_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_E_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_F_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_G_PIN,GPIO_PIN_SET);
		break;
	case 4:
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_A_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_B_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_C_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_D_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_E_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_F_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_G_PIN,GPIO_PIN_SET);
		break;
	case 5:
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_A_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_B_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_C_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_D_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_E_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_F_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_G_PIN,GPIO_PIN_SET);
		break;
	case 6:
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_A_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_B_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_C_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_D_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_E_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_F_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_G_PIN,GPIO_PIN_SET);
		break;
	case 7:
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_A_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_B_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_C_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_D_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_E_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_F_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_G_PIN,GPIO_PIN_RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_A_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_B_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_C_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_D_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_E_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_F_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_G_PIN,GPIO_PIN_SET);
		break;
	case 9:
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_A_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_B_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_C_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_D_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_E_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_F_PIN,GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_G_PIN,GPIO_PIN_SET);
		break;
	default:
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_A_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_B_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_C_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_D_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_E_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_F_PIN,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEGMENT_PORT,SEGMENT_G_PIN,GPIO_PIN_RESET);
		break;
	}
}
void wait(int cycles){
	int j;
	for(j=0;j<cycles;j++);
}