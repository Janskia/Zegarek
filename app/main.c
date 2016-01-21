#include "stm32f0xx.h";
#include "stm32f0xx_hal.h";
#include "stm32f0xx_hal_rcc.h";
#include "stm32f0xx_hal_pwr.h";
#include "stm32f0xx_hal_gpio.h";
#include "stm32f0xx_hal_cortex.h";

#include "pins.h"
#include "segment_display.h"
int a;
int i,j;
RTC_TimeTypeDef newtime;
RTC_DateTypeDef newdate;
RTC_HandleTypeDef RTC_handle;
int main(void)
{

		GPIO_InitTypeDef GPIO_InitDef;
		HAL_RCC_EnableCSS();
		__GPIOA_CLK_ENABLE();
		__GPIOB_CLK_ENABLE();

	    GPIO_InitDef.Pin = LED_DOT1_PIN|LED_DOT2_PIN;
	    GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP;

	    GPIO_InitDef.Pull = GPIO_NOPULL;
	    GPIO_InitDef.Speed = GPIO_SPEED_LOW;
	    //Initialize pins
	    HAL_GPIO_Init(LED_DOT_PORT, &GPIO_InitDef);


	    GPIO_InitDef.Pin = MUX1_PIN|MUX2_PIN|MUX3_PIN|MUX4_PIN;
		GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP;

		GPIO_InitDef.Pull = GPIO_NOPULL;
		GPIO_InitDef.Speed = GPIO_SPEED_LOW;
		//Initialize pins
		HAL_GPIO_Init(MUX1_PORT, &GPIO_InitDef);


	    GPIO_InitDef.Pin = SEGMENT_G_PIN|SEGMENT_F_PIN|SEGMENT_A_PIN|SEGMENT_B_PIN|SEGMENT_C_PIN|SEGMENT_D_PIN|SEGMENT_E_PIN;
		GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP;

		GPIO_InitDef.Pull = GPIO_NOPULL;
		GPIO_InitDef.Speed = GPIO_SPEED_LOW;
		//Initialize pins
		HAL_GPIO_Init(SEGMENT_PORT, &GPIO_InitDef);


		GPIO_InitDef.Pin = BUTTON_MIN_PIN|BUTTON_HOUR_PIN;
		GPIO_InitDef.Mode = GPIO_MODE_INPUT;

		GPIO_InitDef.Pull = GPIO_PULLUP;
		GPIO_InitDef.Speed = GPIO_SPEED_LOW;
		//Initialize pins
		HAL_GPIO_Init(BUTTON_PORT, &GPIO_InitDef);

		//INICJHALIZACJA RTC
		__PWR_CLK_ENABLE();
		HAL_PWR_EnableBkUpAccess();
		__HAL_RCC_LSE_CONFIG(RCC_LSE_ON);
		__HAL_RCC_RTC_CONFIG(RCC_RTCCLKSOURCE_LSE);
		__HAL_RCC_RTC_ENABLE();

		RTC_InitTypeDef RTC_Init;
		RTC_Init.HourFormat=RTC_HOURFORMAT_24;
		RTC_Init.AsynchPrediv=127;
		RTC_Init.SynchPrediv=255;

		RTC_handle.Instance=RTC;
		RTC_handle.Init=RTC_Init;
		HAL_RTC_Init(&RTC_handle);

		RTC_TimeTypeDef time;
		time.Hours=0;
		time.Minutes=0;
		time.Seconds=40;
		RTC_DateTypeDef date;
		HAL_RTC_SetTime(&RTC_handle,&time,FORMAT_BIN);
	//	HAL_PWR_DisableBkUpAccess();

		//SYSTICK TIMER
		HAL_SYSTICK_Config(4000000/10);

    	HAL_GPIO_WritePin(MUX2_PORT,MUX2_PIN,GPIO_PIN_SET);
    	int T_ON= 2000;
    	int T_OFF =500;
    	int tmp=0;
    while(1)
    {


    	HAL_RTC_GetTime(&RTC_handle,&time,FORMAT_BCD);
    	HAL_RTC_GetDate(&RTC_handle,&date,FORMAT_BCD);

    	tmp=time.Hours;
    	if(tmp>=0x24){
    		time.Hours=0x0;
    		HAL_RTC_SetTime(&RTC_handle,&time,FORMAT_BCD);
    		HAL_RTC_GetDate(&RTC_handle,&date,FORMAT_BCD);
    	}
    	if(tmp>=0x22||tmp<=0x06){
    		T_ON= 500;
    		T_OFF =1200;
    	}else{
    		T_ON= 2000;
			T_OFF =500;
    	}


    		tmp=time.Minutes&0x0f;
    		setDisplayVal(tmp);
    		HAL_GPIO_WritePin(MUX1_PORT,MUX1_PIN,GPIO_PIN_SET);
    		wait(T_ON);
    		setDisplayClear();
    		HAL_GPIO_WritePin(MUX1_PORT,MUX1_PIN,GPIO_PIN_RESET);
    		wait(T_OFF);

    		tmp=(time.Minutes&0xf0)>>4;
    		setDisplayVal(tmp);
    		HAL_GPIO_WritePin(MUX2_PORT,MUX2_PIN,GPIO_PIN_SET);
    		wait(T_ON);
    		setDisplayClear();
    		HAL_GPIO_WritePin(MUX2_PORT,MUX2_PIN,GPIO_PIN_RESET);
    		wait(T_OFF);

    		tmp=time.Hours&0x0f;
    		setDisplayVal(tmp);
    		HAL_GPIO_WritePin(MUX3_PORT,MUX3_PIN,GPIO_PIN_SET);
			wait(T_ON);
			setDisplayClear();
			HAL_GPIO_WritePin(MUX3_PORT,MUX3_PIN,GPIO_PIN_RESET);
			wait(T_OFF);

			tmp=(time.Hours&0xf0)>>4;
			setDisplayVal(tmp);
			HAL_GPIO_WritePin(MUX4_PORT,MUX4_PIN,GPIO_PIN_SET);
			wait(T_ON);
			setDisplayClear();
			HAL_GPIO_WritePin(MUX4_PORT,MUX4_PIN,GPIO_PIN_RESET);
			wait(T_OFF);

			if(time.Seconds&0x01){
				HAL_GPIO_WritePin(LED_DOT_PORT,LED_DOT2_PIN,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED_DOT_PORT,LED_DOT1_PIN,GPIO_PIN_RESET);
			}else{
				HAL_GPIO_WritePin(LED_DOT_PORT,LED_DOT2_PIN,GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_DOT_PORT,LED_DOT1_PIN,GPIO_PIN_SET);
			}



    }
}


void SysTick_Handler(){
	static int cnt0=0,speed0=1,cnt1=0,speed1=1;


	if(HAL_GPIO_ReadPin(BUTTON_PORT,BUTTON_MIN_PIN)==GPIO_PIN_RESET){


		cnt0+=speed0;
		if(cnt0>15){
			cnt0=0;
			speed0++;
	     	HAL_GPIO_TogglePin(LED_DOT_PORT,LED_DOT2_PIN);

	     	HAL_RTC_GetTime(&RTC_handle,&newtime,FORMAT_BIN);
			HAL_RTC_GetDate(&RTC_handle,&newdate,FORMAT_BIN);
			newtime.Minutes++;
			if(newtime.Minutes>59)
				newtime.Minutes=0;
			HAL_RTC_SetTime(&RTC_handle,&newtime,FORMAT_BIN);
			HAL_RTC_SetDate(&RTC_handle,&newdate,FORMAT_BIN);
		}
	}else{
		cnt0=15;
		speed0=1;
	}


	if(HAL_GPIO_ReadPin(BUTTON_PORT,BUTTON_HOUR_PIN)==GPIO_PIN_RESET){


		cnt1+=speed1;
		if(cnt1>15){
			cnt1=0;
			speed1++;
	     	HAL_GPIO_TogglePin(LED_DOT_PORT,LED_DOT2_PIN);
			HAL_RTC_GetTime(&RTC_handle,&newtime,FORMAT_BIN);
			HAL_RTC_GetDate(&RTC_handle,&newdate,FORMAT_BIN);
			newtime.Hours++;
			if(newtime.Hours>23)
				newtime.Hours=0;
			HAL_RTC_SetTime(&RTC_handle,&newtime,FORMAT_BIN);
			HAL_RTC_SetDate(&RTC_handle,&newdate,FORMAT_BIN);
		}
	}else{
		cnt1=15;
		speed1=1;
	}
}

